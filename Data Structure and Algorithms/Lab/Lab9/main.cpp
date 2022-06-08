#include <stdio.h>
#include <stdlib.h>
#include "printTree.cpp"
#include "BST.cpp"

int main() 
{
  Node * root = NULL;    
  
  insertNode(&root,13);
  insertNode(&root,40);
  insertNode(&root,58);
  insertNode(&root,25);
  insertNode(&root,6);
  insertNode(&root,32);

  printTree(root);

  // destroyTree(root);

  return 0;
}