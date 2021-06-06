#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct root {
	float key;
	vInfo data;
	struct root *left;
	struct root *right;
} root;

vRoot create_node(vInfo info, int key){
	root* new_tree  = malloc(sizeof(root));
	new_tree->key   = key;
	new_tree->data  = info;
	new_tree->left  = NULL;
	new_tree->right = NULL;

	return new_tree;
}

vRoot insert(vInfo info, int key, vRoot node) {
	root *tree = (root *)node;
	if(node == NULL)
	return create_node(info, key);
	if(key < tree->key){
		tree->left = insert(info, key, tree->left);
	}else{
		tree->right = insert(info, key, tree->right);
	}
	return tree;
}
