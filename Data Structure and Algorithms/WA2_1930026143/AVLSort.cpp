#include<stdio.h>
#include<stdlib.h>
#include "AVL.h"

int main(){
    int a[] = {13,25,58,80,15,82,6,65,29,70,68};
    int *A = a;
    int n = sizeof(a)/sizeof(a[0]);
    AVLSort(A, n);
    printf("After AVLsort: ");
    for(int i=0; i<n; i++){
        printf("%d ", A[i]);
    }

}

void AVLSort(int *A, int n){
    Node* proot = NULL;
    for(int i=0; i<n; i++)
        insertNode(&proot, A[i]);
    // Node* curr = proot;
    inOrder(proot, A, 0);
}

int inOrder(Node* root, int* A, int i) {
	if (!root) 
		return i;

	i = inOrder(root->left, A, i);
	A[i] = root->key;
	i++;
	i = inOrder(root->right, A, i);
	return i;
}

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
	if (!(*proot))//if null
		return;
	if (!(*proot)->left && !(*proot)->right) {
		(*proot)->height = 0;//if both null,means leaf
		return;
	}
	if ((*proot)->left && !(*proot)->right)//adjust the height 
		(*proot)->height = (*proot)->left->height + 1;
	if ((*proot)->right && !(*proot)->left)//adjust the height 
		(*proot)->height = (*proot)->right->height + 1;
	if ((*proot)->left && (*proot)->right) {//adjust the height 
		if ((*proot)->right->height >= (*proot)->left->height)
			(*proot)->height = (*proot)->right->height + 1;
		else//adjust the height 
			(*proot)->height = (*proot)->left->height + 1;
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
    if(!root->right && !root->left)
        return true;
    if(!root->right && root->left->height<1)
        return true;
    if(!root->left && root->right->height<1)
        return true;
    if(-2 < root->left->height - root->right->height < 2)
        return true;
    else    
        return false;
}

void rebalance(Node **proot){
    if(balanced(*proot))
        return ;
    if(case1_rr(*proot))
        leftRotate(&(*proot));
    if(case2_rl(*proot)){
        leftRotate(&(*proot));
        rightRotate(&(*proot));
    }
    if(case3_lr(*proot)){
        rightRotate(&(*proot));
        leftRotate(&(*proot));
    }
    if(case4_ll(*proot))
        leftRotate(&(*proot));
}

bool case1_rr(Node *root){
    if(!root->left && root->right) {
		if(root->right->right && !(root->right->left))
            return true;
    }
    else if(root->left && root->right && root->right->height - root->left->height > 1){
        if(!(root->right->left) && root->right->right->height > 0)
            return true;
        if(root->right->right->height > -root->right->left->height > 0)
            return true;
    }
    else
        return false;
}

bool case2_rl(Node *root){
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

