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

Tree min_key_node(Tree tree){
	Node *current = (Node*) tree;
	while(current && current->left != NULL){
		current = current->left;
	}
	return current;
}

Tree delete_node(Tree tree, float point[2], int depth){
	Node* root = (Node*) tree;
	int cd = depth%2;
	if(root == NULL){
		return root;
	}
	if(point[cd] < root->point[cd]){
		root->left = delete_node(root->left, point, depth+1);
	}
	else if(point[cd] > root->point[cd]){
		root->right= delete_node(root->right, point, depth+1);
	}
	else{
		if(root->left == NULL){
			Node *tmp = root->right;
			free(root);
			return tmp;
		}
		else if(root->right == NULL){
			Node *tmp = root->left;
			free(root);
			return tmp;
		}
		Node * tmp = min_key_node(root->right);
		root->point[0] = tmp->point[0];
		root->point[1] = tmp->point[1];
		root->right = delete_node(root->right, tmp->point, depth + 1);
	}
	return root;
}

