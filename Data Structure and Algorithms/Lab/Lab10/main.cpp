#include <stdio.h>
#include <stdlib.h>
#include "AVL.cpp"
#include "printTree.cpp"


int main() 
{
  Node * root = NULL;    
  
  int ins[]={13, 25, 58, 80, 15, 82, 6, 65, 29, 70, 68};
  int len = 11, x;
  for(int i=0; i<len; i++){
      printf("\nAfter inserting key %d..\n", ins[i]);
      insertNode(&root,ins[i]);
      printTree(root);
  }
  // printf("\nInsert a new node (+ to insert, - to delete, 0 to exit): ");
  // scanf("%d",&x);
  // while(x){
  //     if(x > 1)
  //       insertNode(&root,x);
  //     else
  //       free(deleteNode(&root,-x));
  //     printTree(root);
  //     printf("\nInsert a new node (+ to insert, - to delete, 0 to exit): ");
  //     scanf("%d",&x);
  // }
  
  // destroyTree(root);

  return 0;
}
