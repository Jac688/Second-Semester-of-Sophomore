#include "BST.h"
#include "stdlib.h"

Node* insertNode(Node **proot, int x){
	// insert your code here and remove the "return 0" statement
	if(!(*proot)){
		// add a new dynamic space to store new node
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->key = x;
		// Have no children
		newNode->left = NULL;
		newNode->right = NULL;
		*proot = newNode;
		return *proot;
	}
	// Prevent adding duplicate values
	if((*proot)->key == x)
		return NULL;
	// Determine the parameters of the recursion based on their size
	if((*proot)->key > x)
		return insertNode(&(*proot)->left, x);
	else
		return insertNode(&(*proot)->right, x);
	return 0;
}

Node* deleteNode(Node **proot, int x){
	// insert your code here and remove the "return 0" statement
	if(!(*proot))
		return NULL;
	if((*proot)->key == x){
		Node* root = *proot;
		if(!(*proot)->left && !(*proot)->right ){
			// Node* root = *proot;
			*proot = NULL;
			// return root;
		}
		else if((*proot)->left && !(*proot)->right){
			// Node* root = *proot;
			*proot = (*proot)->left;
			// return root;
		}
		else if(!(*proot)->left && (*proot)->right){
			// Node* root = *proot;
			*proot = (*proot)->right;
			// return root;
		}
		else{
			// Find the minmum in the right
			Node* minright = finMin((*proot)->right);
			// Delete and recond it
			Node* dminright = deleteNode(&((*proot)->right), minright->key);
			// Replace the root by the minmum of right
			dminright->left = (*proot)->left;
			dminright->right = (*proot)->right;
			*proot = dminright;
			// return root;
		}
		return root;
	}
	// Determine the parameters of the recursion based on their size
	else if((*proot)->key > x)
		return deleteNode(&((*proot)->left), x);
	else 
		return deleteNode(&((*proot)->right), x);
	return 0;
}

// Find the minmum of the right hand 
Node* finMin(Node* rnode){
	if(!rnode)
		return NULL;
	while(!(rnode->left))
		rnode = rnode->left;
		
	// return rnode->left but not left
	return rnode->left;
}

Node* findNode(Node *root, int x){
	// insert your code here and remove the "return 0" statement
	if(root->key == x)
	    // Find and return the node
		return root;
	if(!root)
		return NULL;
	// Determine the parameters of the recursion based on their size
	if(root->key > x)
		return findNode(root->left, x);
	else
		return findNode(root->right, x);
	return 0;
}

void destroyTree(Node *root){
	// insert your code here
	if(!root)
		return ;
	// Destroy every nodes in BST
	destroyTree(root->left);
	destroyTree(root->right);
	free(root);
	root = NULL;
	return ;
}