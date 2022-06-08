#include "BST.h"
Node *insertNode(Node **proot, int x){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = x;
    newNode->left = NULL;
    newNode->right = NULL;

    if(!(*proot))
        *proot = newNode;
    else{
        Node* pre = NULL;
        Node* curr = *proot;
        // find the node we should insert
        while(curr != NULL){
            pre = curr;
            if(curr->key > x){
                curr = curr->left;
            }
            else if(curr->key < x){
                curr = curr->right;
            }
            // if((*proot)->key == x)
            else{
                return NULL;
            }
        }
        // Compare previous node's key with x
        if(pre->key < x){
            pre->right = newNode;
        }
        if(pre->key > x){
            pre->left = newNode;
        }
    }
    return *proot;
}

/* function: searches for a node in the tree
    input: root: pointer to the tree root
            x: the key of of the node to be searched
    output: returns a pointer to the found node
            returns NULL if no such node exists
*/
Node *findNode(Node *root, int x){
    while(root != NULL){
        // Traversal number queries
        if(root->key > x){
            root = root->left;
        }
        else if(root->key < x){
            root = root->right;
        }
        else{
            return root;
        }
    }
    return NULL;
}


Node *deleteNode(Node **proot, int x){
    // remove the "return 0" statement
    if(!(*proot))
        return NULL;

    Node* pre = NULL;
    Node* curr = *proot;
    // FInd the node should be deleted 
    while(curr && curr->key != x ){
        pre = curr;
        if(curr->key > x){
            curr = curr->left;
        }
        else if(curr->key < x){
            curr = curr->right;
        }
        // if((*proot)->key == x)
    }
    // Case1: The deleted node has no child
    if(!curr){
        // The number x does not exist in the tree
        return NULL;
    }
    // Case2: The deleted node has one left child
    if(!(curr)->left && !(curr)->right){
        Node* root = curr;
        if(pre->key < curr->key)
            pre->right = NULL;
        else if(pre->key > curr->key)
            pre->left = NULL;
        return root;
    }
    // Case3: The deleted node has one right child
    else if(curr->left && !curr->right){
        Node* root = curr;
        if(pre->key < curr->key)
            pre->right = curr->left;
        else if(pre->key > curr->key)
            pre->left = curr->left;
        return root;
    }
    // Case4: The deleted node has two children
    else if(!curr->left && curr->right){
        Node* root = curr;
        if(pre->key < curr->key)
            pre->right = curr->right;
        if(pre->key > curr->key)
            pre->left = curr->right;
        return root;
    }
    else{
        Node* root = curr;
        // Find the minmum in the right
        Node* minright = finMin(curr->right);
        // Delete and recond it
        Node* dminright = deleteNode(&curr, minright->key);
        // Replace the root by the minmum of right
        dminright->left = curr->left;
        dminright->right = curr->right;
        if(!pre){
            *proot = dminright;
            return root;
        }
        if(pre->key < dminright->key)
            pre->right = dminright;
        if(pre->key > dminright->key)
            pre->left = dminright;
        return root;
    }
}

Node* finMin(Node* rnode){
	if(!rnode)
		return NULL;
	while(rnode->left)
		rnode = rnode->left;
	// return rnode->left but not left
	return rnode;
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
