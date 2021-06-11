#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "kdtree.h"
#include "rect.h"
#include "circle.h"
typedef struct Node{
	_Info info;
	float point[2];
	struct Node *left;
	struct Node *right;
} Tree;

float calc_distance(float x1, float y1, float x2, float y2){
    return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

_Tree create_kdnode(float point[2], _Info info) {
	Tree *tree = (Tree *)malloc(sizeof(Tree));
	tree->left = NULL;
	tree->right = NULL;
	tree->point[0] = point[0];
	tree->point[1] = point[1];
	tree->info = info;
	return tree;
}

_Tree insert_kd(_Tree tree, float point[2], _Info info, int depth){
	Tree* root = (Tree*) tree;
	if(root==NULL){
		return create_kdnode(point, info);
    }

	int cd = depth%2;

	if(point[cd] < root->point[cd]){
		root->left = insert_kd(root->left, point, info, depth+1);	
	}else{
		root->right = insert_kd(root->right, point, info, depth+1);	
	}
	return root;
}

_Tree insert_kd_init(_Tree tree, float point[2], _Info info){
	return insert_kd(tree, point, info, 0);
}

void find_point_search_key(_Tree tree, char id[], float *result){
	Tree* root = (Tree*) tree;
	if(root == NULL || (result[0] && result[1] && result[2] && result[3])){
		return;
	}

	find_point_search_key(root->left, id, result);
	find_point_search_key(root->right, id, result);

	_Rect rect = get_info(root);
	char *idToCompare = get_rect_id(rect);
	float rect_data[4];
	rect_data[0] = get_rect_x(get_info(root));
	rect_data[1] = get_rect_y(get_info(root));
	rect_data[2] = get_rect_w(get_info(root));
	rect_data[3] = get_rect_h(get_info(root));
	if((strcmp(idToCompare, id))==0){
		copy_point(result, get_rect_point(rect));
		result[0] = rect_data[0];
		result[1] = rect_data[1];
		result[2] = rect_data[2];
		result[3] = rect_data[3];
		return;
	}
	return;
}

_Info get_info(_Tree tree){
	Tree* root = (Tree*) tree;
	return root->info;
}

void* get_point(_Tree tree){
	Tree* root = (Tree*) tree;
	return root->point;
}

_Tree get_kd_right(_Tree tree){
	Tree* root = (Tree*) tree;
	return root->right;
}

_Tree get_kd_left(_Tree tree){
	Tree* root = (Tree*) tree;
	return root->left;
}

_Tree min_node(_Tree x, _Tree y, _Tree z, int d){
	Tree *res = (Tree*) x;
	Tree *yt  = (Tree*) y;
	Tree *zt  = (Tree*) z;
	if(yt != NULL && yt->point[d] < res->point[d]){
		res = y;
	}
	if(zt != NULL && zt->point[d] < res->point[d]){
		res = z;
	}
	return res;
}

_Tree find_min(_Tree tree, int d, int depth){
	Tree* root = (Tree*) tree;

	if(root == NULL){
		return root;
	}

	int cd = depth % 2;

	if(cd == d){
		if(root->left == NULL){
			return root;
		}
		return find_min(root->left, d, depth+1);
	}
	return min_node(root, find_min(root->left, d, depth+1), find_min(root->right, d, depth+1), d);
}

_Tree find_min_init(_Tree tree, int d){
	return find_min(tree, d, 0);
}

int is_equal(float point1[2], float point2[2]){
	for(int i = 0; i < 2; i++){
		if(point1[i] != point2[i]){
			return 0;
		}
	}
	return 1;
}

void copy_point(float point1[2], float point2[2]){
	for(int i = 0; i < 2; i++){
		point1[i] = point2[i];
	}
}

_Tree delete_node(_Tree tree, float *point, int depth, void (*swap)(_Info, _Info)){
	Tree* root = (Tree*) tree;
	if(root == NULL){
		return root;
	}

	int cd = depth % 2;

	if(is_equal(root->point, point)==1){
		if(root->right != NULL){
			Tree *min = find_min_init(root->right, cd);
			copy_point(root->point, min->point);
			swap(root->info, min->info);
			root->right = delete_node(root->right, min->point, depth+1, swap);
		}

		else if(root->left != NULL){
			Tree *min = find_min_init(root->left, cd);
			copy_point(root->point, min->point);
			swap(root->info, min->info);
			root->right = delete_node(root->left, min->point, depth+1, swap);
			root->left = NULL;
		}

		else{
			if(root->info != NULL){
				free(root->info);
			}
			free(root);
			return NULL;
		}
		return root;
	}

	if(point[cd] < root->point[cd]){
		root->left = delete_node(root->left, point, depth+1, swap);
	}
	else{
		root->right = delete_node(root->right, point, depth+1, swap);
	}
	
	return root;
}

_Tree delete_node_init(_Tree tree, float *point, void (*swap)(_Info, _Info)){
	return delete_node(tree, point, 0, swap);
}

void delete_tree(_Tree tree){
	Tree *root = tree;
	if(root == NULL){
		return;
	}
	delete_tree(root->right);
	delete_tree(root->left);
	if(root->info != NULL){
		free(root->info);
	}
	free(root);
}

bool is_null(_Tree tree){
	Tree *root = tree;
	if (root == NULL){
		return true;
	}
	return false;
}

float find_nearest_neighbor(_Tree tree, float *point,  float distance, _Rect *result, int flag){
	if(tree==NULL){
		return INFINITY;
	}
	Tree *root = tree;
	float centerx = root->point[0] + get_rect_w(get_info(tree))/2;
	float centery = root->point[1] + get_rect_h(get_info(tree))/2;
	float cDistance = calc_distance(centerx, centery, point[0], point[1]);
	if(flag==0){
		*result = get_info(root);
		distance = cDistance;
	}
	if(cDistance<distance){
		*result = get_info(root);
		distance = cDistance;
	}
	cDistance = find_nearest_neighbor(root->left, point, distance, result, 1);
	if(cDistance<distance){
		distance = cDistance;
	}
	cDistance = find_nearest_neighbor(root->right, point, distance, result, 1);
	if(cDistance<distance){
		distance = cDistance;
	}
	return distance;
}

void find_nearest_neighbor_init(_Tree tree, float *point, _Rect *result){
	find_nearest_neighbor(tree, point, 0, result, 0);
}

_Tree print_all_rect(_Tree tree){
	Tree *root = tree;
	if(root==NULL)
		return NULL;
	print_all_rect(root->right);
	print_all_rect(root->left);
	printf("%s\n", get_rect_cc(get_info(root)));
	return root;
}
