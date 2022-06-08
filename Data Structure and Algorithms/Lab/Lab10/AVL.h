#ifndef _TEST_H_
#define _TEST_H_

typedef struct Node {
  int key, height;
  Node *left, *right;
} Node;

Node* insertNode(Node **proot, int x);
/*
 function:
	inserts a new node to the tree
 input:
	proot - pointer to the pointer to the tree root
	x - the key of the new node
 output:
	returns a pointer to the newly inserted node 
	returns NULL if insertion is not successful
*/

Node* deleteNode(Node **proot, int x);
/*
 function:
	removes a node from the tree without freeing it
 input:
	proot - pointer to the pointer to the tree root
	x - the key of of the node to be deleted
 output:
	returns a pointer to the deleted node 
	returns NULL if no such node exists
*/

Node* findNode(Node *root, int x);
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

void destroyTree(Node *root);
/*
 function:
	deletes all the nodes in the tree and frees the memory occupied by them
 input:
	root - pointer to the tree node
*/

Node* deleteRoot(Node** proot);

Node* deleteMin(Node** proot);

void printTree(Node *root);
/*
 function:
	prints ascii tree for given Node structure
	this function is already implemented in printTree.cpp
 input:
	root - pointer to the tree node
*/

int finMin(Node* root);

void updateHeight(Node **proot);

void rebalance(Node **proot);

bool balanced(Node *root);

bool case1_rr(Node *root);
bool case2_rl(Node *root);
bool case3_lr(Node *root);
bool case4_ll(Node *root);

void rightRotate(Node **proot);

void leftRotate(Node **proot);

int max(int a, int b);
int height(Node* root);

#endif