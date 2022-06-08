#include "AVL.h"
#include <stdlib.h>

Node* insertNode(Node **proot, int x){
    Node* newN = NULL;
    if(!(*proot)){
        // add a new dynamic space to store new node
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = x;
        // Have no children
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        *proot = newNode;
        return *proot;
	}
    
	// Prevent adding duplicate values
	if((*proot)->key == x){
		return NULL;
    }
    
    // rebalance(&(*proot), x);

	// Determine the parameters of the recursion based on their size
	if((*proot)->key > x){
		newN = insertNode(&(*proot)->left, x);
    }
	else{
		newN = insertNode(&(*proot)->right, x);
    }
    updateHeight(&(*proot));
    rebalance(&(*proot));
    return newN;
}

void updateHeight(Node** proot){
	if(!(*proot))
		return ;

	if(!(*proot)->left && !(*proot)->right){
		(*proot)->height=0;
		return;
	}
	if((*proot)->left && !(*proot)->right)
		(*proot)->height = (*proot)->left->height+1;
        
    if(!(*proot)->left && (*proot)->right) 
		(*proot)->height = (*proot)->right->height+1;
	
	if((*proot)->left && (*proot)->right){
		if((*proot)->right->height >= (*proot)->left->height)
			(*proot)->height = (*proot)->right->height+1;
		else
			(*proot)->height = (*proot)->left->height+1;
	}
}

int height(Node* root) {
	if (!root) 
        return 0;
	int hr = height(root->right) + 1;
	int hl = height(root->left) + 1;
	return max(hl, hr); // return the larger hight to be this current node hight
}

int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

bool balanced(Node *root){
    if (!root)
		return true;

	if(!root->left&&!root->right)
		return true;

    if(!root->right && root->left){
		int right_height=-1;
		if(root->left->height - right_height>1)//if height greater than 1
			return false;
	}

	if(!root->left && root->right){
		int left_height = -1;
		if(root->right->height-left_height>1)
			return false;
	}
	
	if(root->right && root->left){
        if(root->right->height-root->left->height>1)
            return false;
		if(root->left->height-root->right->height>1)
			return false;
    }
	return true;
}

void rebalance(Node **proot){
    if(balanced(*proot))
		return;

	int lh = -1;
	int rh = -1;
	if((*proot)->left)
		lh = (*proot)->left->height;
	if((*proot)->right)
		rh=(*proot)->right->height;

    if(lh-rh <= 1){
		int rl = -1;
		int rr = -1;

		if((*proot)->right->left)
			rl = (*proot)->right->left->height;
		if((*proot)->right->right)
			rr = (*proot)->right->right->height;
        // case_rr
		if(rl-rr <= -1){
			leftRotate(&(*proot));
            printf("xsj");
        }
        // case_rl
		if(rl-rr > -1){
            printf("mzh");
			rightRotate(&(*proot)->right);
			leftRotate(&(*proot));
		}
        
	}
	if(lh-rh > 1){
		int ll = -1;
		int lr = -1;
		if((*proot)->left->left)
			ll = (*proot)->left->left->height;
		if((*proot)->left->right)
			lr = (*proot)->left->right->height;
        // case_ll
		if(ll-lr > -1)
			rightRotate(&(*proot));
		// case_lr
		else{
			leftRotate(&(*proot)->left);
			rightRotate(&(*proot));
		}
	}
}

bool case1_rr(Node *root){
    printf("xsj");
    if(!root->left && root->right) {
		if(root->right->right && !(root->right->left))
            return true;
    }
    else if(root->left && root->right && root->right->height - root->left->height > 1){
        if(!(root->right->left) && root->right->right->height > 0)
            return true;
        if(root->right->right->height > root->right->left->height > 0)
            return true;
    }
    else
        return false;
}

bool case2_rl(Node *root){
    printf("mzh");
    if(!root->left && root->right) {
		if(root->right->left && !(root->right->right))
            return true;
    }
    else if(root->left && root->right && root->right->height - root->left->height > 1){
        if(!(root->right->right) && root->right->left->height > 0)
            return true;
        if(root->right->left->height > root->right->right->height > 0)
            return true;
    }
    else
        return false;
}

bool case3_lr(Node *root){
    printf("zyh");
    if(!root->right && root->left) {
		if(root->left->right && !(root->left->left))
            return true;
    }
    else if(root->left && root->right && root->left->height - root->right->height > 1){
        if(!(root->left->right) && root->left->left->height > 0)
            return true;
        if(root->left->right->height > root->left->left->height > 0)
            return true;
    }
    else
        return false;
}

bool case4_ll(Node *root){
    printf("kyh");
    if(!root->right && root->left) {
		if(root->left->left && !(root->left->right))
            return true;
    }
    else if(root->left && root->right && root->left->height - root->right->height > 1){
        if(!(root->left->left) && root->left->right->height > 0)
            return true;
        if(root->left->left->height > root->left->right->height > 0)
            return true;
    }
    else
        return false;
}

void rightRotate(Node **proot){
    Node* k2 = *proot;
    Node* k1 = k2->left;
    Node* y = k1->right;
    *proot = k1;
    k1->right = k2;
    k2->left = y;
    updateHeight(&k2);
    updateHeight(&k1);
}

void leftRotate(Node **proot){
    Node* k2 = *proot;
    Node* k1 = k2->right;
    Node* y = k1->left;
    *proot = k1;
    k1->left = k2;
    k2->right = y;
    updateHeight(&k2);
    updateHeight(&k1); 
}

Node *deleteNode(Node **proot,int x){
	Node *match = NULL;
	if (!(*proot))
		return NULL;

	if ((*proot)->key > x)
		Node *match = deleteNode(&(*proot)->left,x);
	else if((*proot)->key < x)
		Node *match =deleteNode(&(*proot)->right,x);
	else
		Node *match = deleteRoot(&(*proot));

	updateHeight(&(*proot));
	rebalance(&(*proot));
	return match;
}

Node* deleteRoot(Node** proot){
    Node* currNode = *proot;
    if(!(*proot)->left){
        *proot = (*proot)->right;
        return currNode;
    }
    if(!(*proot)->right){
        *proot = (*proot)->left;
        return currNode;
    }
    Node* minN = deleteMin(&(*proot)->right);
    minN->left = (*proot)->left;
    minN->right = (*proot)->right;
    *proot = minN;
    return currNode;
}

Node* deleteMin(Node** proot){
    if(!(*proot)->left){
        Node* minN = *proot;
        *proot = (*proot)->right;
        return minN;
    }
    Node* minN = deleteMin(&(*proot)->left);
    updateHeight(&(*proot));
    rebalance(&(*proot));
    return minN;
}


Node* findNode(Node *root, int x){
    if(!root)
		return NULL;
    if(root->key == x)
        return root;
    // Find and return the node

	// Determine the parameters of the recursion based on their size
	if(root->key > x)
		return findNode(root->left, x);
	else
		return findNode(root->right, x);
	return 0;
}
/*
 function:
	searches for a node in the tree
 input:
	root - pointer to the tree root
	x - the key of of the node to be searched
 output:
	returns a pointer to the found node 
	returns NULL if no such node exists
*/

void destroyTree(Node *root){
    if(!root)
	return ;
	// Destroy every nodes in BST
	destroyTree(root->left);
	destroyTree(root->right);
	free(root);
	root = NULL;
	return ;
}
/*
 function:
	deletes all the nodes in the tree and frees the memory occupied by them
 input:
	root - pointer to the tree node
*/
