#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "kdtree.h"

typedef struct Node{
	Info info;
	float point[2];
	struct Node *left;
	struct Node *right;
} Node;

Tree create_kdnode(float point[2], Info info) {
	Node *tree = (Node *)malloc(sizeof(Node));
	tree->left = NULL;
	tree->right = NULL;
	tree->point[0] = point[0];
	tree->point[1] = point[1];
	tree->info = info;
	return tree;
}

Tree insert_kd(Tree tree, float point[2], Info info, int depth){
	Node* root = (Node*) tree;
	int cd = depth%2;
	if(root==NULL){
          return create_kdnode(point, info);
    }
	if(point[cd] < root->point[cd]){
		root->left = insert_kd(root->left, point, info, depth+1);	
	}else{
		root->right= insert_kd(root->right, point, info, depth+1);	
	}
	return root;
}

Tree insert_kd_init(Tree tree, float point[2], Info info){
	return insert_kd(tree, point, info, 0);
}

Tree search_key(Tree tree, float point[2], int depth){
	Node* root = (Node*) tree;
	int cd = depth%2;
	if(root==NULL || root->point==point){
		return root;
	}
	if(point[cd] < root->point[cd]){
		return search_key(root->left, point, depth+1);
	}
	return search_key(root->right, point, depth+1);
}

Info get_info(Tree tree){
	Node* root = (Node*) tree;
	return root->info;
}

void* get_point(Tree tree){
	Node* root = (Node*) tree;
	return root->point;
}

Tree get_right(Tree tree){
	Node* root = (Node*) tree;
	return root->right;
}

Tree get_left(Tree tree){
	Node* root = (Node*) tree;
	return root->left;
}

Tree min_node(Tree x, Tree y, Tree z, int d){
	Node *res = (Node*) x;
	Node *yt  = (Node*) y;
	Node *zt  = (Node*) z;
	if(yt != NULL && yt->point[d] < res->point[d]){
		res = y;
	}
	if(zt != NULL && zt->point[d] < res->point[d]){
		res = z;
	}
	return res;
}

Tree find_min(Tree tree, int d, int depth){
	Node* root = (Node*) tree;
	int cd = depth % 2;
	if(root == NULL){
		return root;
	}
	if(cd == d){
		if(root->left == NULL){
			return root;
		}
		return find_min(root->left, d, depth+1);
	}
	return min_node(root, find_min(root->left, d, depth+1), find_min(root->right, d, depth+1), d);
}

Tree find_min_init(Tree tree, int d){
	return find_min(tree, d, 0);
}

bool is_equal(float point1[2], float point2[2]){
	for(int i = 0; i < 2; i++){
		if(point1[i] != point2[i]){
			return false;
		}
	}
	return true;
}

void copy_point(float point1[2], float point2[2]){
	for(int i = 0; i < 2; i++){
		point1[i] = point2[i];
	}
}
Tree delete_node(Tree tree, float point[2], int depth){
	Node* root = (Node*) tree;

	if(root == NULL){
		return root;
	}
	int cd = depth % 2;

	if(is_equal(root->point, point)){

		if(root->right != NULL){
			Node *min = find_min_init(root->right, cd);
			copy_point(root->point, min->point);
			root->right = delete_node(root->right, min->point, depth+1);
		}

		else if(root->left != NULL){
			Node *min = find_min_init(root->left, cd);
			copy_point(root->point, min->point);
			root->left = delete_node(root->left, min->point, depth+1);
		}

		else{
			if(root->info != NULL){
				free(root->info);
			}
			free(root);
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
Tree delete_node_init(Tree tree, float point[2]){
	return delete_node(tree, point, 0);
}