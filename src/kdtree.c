#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "kdtree.h"
#include "rect.h"
#include "circle.h"

typedef struct Node{
	_Info info;
	float point[2];
	struct Node *left;
	struct Node *right;
} Tree;

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

_Tree search_key(_Tree tree, float point[2], int depth){
	Tree* root = (Tree*) tree;
	int cd = depth%2;
	if(root==NULL || root->point==point){
		return root;
	}
	if(point[cd] < root->point[cd]){
		return search_key(root->left, point, depth+1);
	}
	return search_key(root->right, point, depth+1);
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
_Tree delete_node(_Tree tree, float *point, int depth){
	Tree* root = (Tree*) tree;
	if(root == NULL){
		return root;
	}

	int cd = depth % 2;

	if(is_equal(root->point, point)==1){
		if(root->right != NULL){
			Tree *min = find_min_init(root->right, cd);
			copy_point(root->point, min->point);
			root->right = delete_node(root->right, min->point, depth+1);
		}

		else if(root->left != NULL){
			Tree *min = find_min_init(root->left, cd);
			copy_point(root->point, min->point);
			root->left = delete_node(root->left, min->point, depth+1);
		}

		else{
			if(root->info != NULL){
				free(root->info);
			}
			free(root);
			return NULL;
		}
	}

	if(point[cd] < root->point[cd]){
		root->left = delete_node(root->left, point, depth+1);
	}
	else{
		root->right = delete_node(root->right, point, depth+1);
	}
	
	return root;
}

_Tree delete_node_init(_Tree tree, float *point){
	return delete_node(tree, point, 0);
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

void fodace(_Tree tree){
	Tree *root = tree;
}

