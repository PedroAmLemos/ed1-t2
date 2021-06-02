#include <stdio.h>
#include <stdlib.h>
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
	Node* root = (Node*) tree;
	return insert_kd(root, point, info, 0);
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
// Tree delete_node(Tree tree, float point[2], int depth){
// 	Node* root = (Node*) tree;
// 	int cd = depth%2;
// 	if(root == NULL){
// 		return root;
// 	}
// 	else if(point[cd] < root->point==point[cd])
// }

