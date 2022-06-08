#ifndef _TEST_H_
#define _TEST_H_

typedef struct Node {
  int key, height;
  Node *left, *right;
} Node;

Node* insertNode(Node **proot, int x);
void destroyTree(Node *root);
void AVLSort(int *A, int n);
int inOrder(Node* root, int *A, int x);
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