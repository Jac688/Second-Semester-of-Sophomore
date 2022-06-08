#include "list.h"
#include <stdio.h> 
#include <stdlib.h>

bool Compare(double a, double b){
    if(abs(a-b)<=0.000001)
        return true;
    else{
        return false;
    }
}

int main()
{
	Node *head = 0;
    // The expected output is 0-4, of type double
	for(int i=0; i<5; i++)
		InsertNode(&head, i, i);
	DisplayList(head);
	
    // The expected output is 4-0-0-4, of type double
    for(int i=0; i<5; i++)
		InsertNode(&head, 0, i);
	DisplayList(head);
    
    // Report an error
    InsertNode(&head,12, 7);

    // Find the frist 0, 2, 4, 6 in the list
	for(int i=0; i<7; i+=2){
		int idx = FindNode(head, i);
		if(idx>0)
			printf("%d is at position %d.\n", i, idx);
		else
            // 6 is not in the list
			printf("%d is not in the list.\n", i);
	}

    // Delete the first 0, 4, 7 in the list
	DeleteNode(&head, 0);
	DisplayList(head);

	DeleteNode(&head,4);
	DisplayList(head);

    // Report a warning
    DeleteNode(&head, 7);
    DisplayList(head);
    DestroyList(&head);
}

bool IsEmpty(Node* head){
    bool b = true;
    // Determines whether the header pointer points to a null address
    if(head == NULL)
        b = true;
    else
        b = false;
    return b;
}

Node* InsertNode(Node** phead, int index, double x){
    // index < 0 is invalid input
    if(index < 0)
        return NULL;
    
    // Measure the length of the linked list
    int len = 0;
    Node* plen = *phead;
    while(plen != NULL){
        plen = plen->next;
        len++;
    }

    // Determine if the index is out of range
    if(index > len){
        printf("Invalid input: the index exceeds the length of the list!\n");
        return NULL;

    }
    
    int cnt = 1;
    // Find the node in the index position
    Node *cnode = *phead;
    while(cnode && cnt < index){
        cnode = cnode->next;
        cnt++;
    }
    // Request dynamic memory
    Node *insert = (Node*)malloc(sizeof(Node));
    insert->data = x;

    // index==0 and replace head pointer
    if(index == 0){
        insert->next = *phead;
        *phead = insert;
    }
    // index > 0 and insert the node in the index position
    else if(index > 0){
        insert->next = cnode->next;
        cnode->next = insert;
    }
    return insert;
}

int FindNode(Node* head, double x){
    // Determine if the list is empty
    if(head == NULL){
        return 0;
    }

    Node* currt = head;
    int cnt = 1;
    // Use the currt to travel from the head
    while(currt->next != NULL && Compare(currt->data,x)==false){
        currt = currt->next;
        cnt++;
    }

    // If it don't find x after traversing it, and it doesn't exist
    if(Compare(currt->data,x)==false){
        return 0;
    }
    // Get the index and return
    return cnt;
}

int DeleteNode(Node** phead, double x){
    // Determine if the list is empty
    if(phead == NULL){
        return 0;
    }
    int cnt = 0;
    int len = 0;
    Node* plen = *phead;

    // Measure the length of the linked list
    while(plen->next != NULL){
        plen = plen->next;
        len++;
    }

    Node *cnode = *phead;
    Node *before = *phead;

    // Travel the list and find the double x
    while(cnode->next != NULL && Compare(cnode->data,x)==false){
        cnode = cnode->next;
        cnt++;
    }

    // If it don't find x after traversing it, and it doesn't exist
    if(cnt==len && Compare(cnode->data,x)==false){
        printf("Warning: The number is not in the linked list!\n");
        return 0;
    }

    // Find the node before the one to be deleted
    while(before != NULL && before->next != cnode){
        before = before->next;
    }
    
    if(cnode == *phead){
        // The header pointer is replaced
        *phead = cnode->next;
        free(cnode);
    }
    else{ // cnode != *phead
        if(cnode != NULL){
            // If cnode == NULL, it will report some error if you input the last node in the list
            before->next = before->next->next;
            free(cnode);
        }
        else{
            // If you input the last node in the list, before will point to NULL
            before->next = NULL;
            free(cnode);
        }
    }
    return cnt;
}

void DisplayList(Node* head){
    // Determine if the list is empty or existing
    if(head == NULL){
        printf("\nThe linked list is empty or not exist!\n");
        return;
    }

    Node *temp = head;

    // Travese the linked list
    while(temp != NULL){
        // reserve two decimal fractions
        printf("%.2f  ", temp->data);
        temp = temp->next;
    }printf("\n");
}

void DestroyList(Node** phead){
    // Note: The argument is a pointer to the header pointer
    if(*phead == NULL){
        printf("The linked list is empty or not exist!\n");
        return;
    }
    Node *temp;
    // Each node is freed from the head pointer
    // Instead of just pointing the head pointer to NULL
    while(*phead != NULL){
        temp = *phead;
        *phead = (*phead)->next;
        free(temp);
        *phead = NULL;
    }
    printf("The list is destroyed successfully!");
}



// void sort(Node** phead){
//     if(*phead == NULL) 
// 		return; 
// 	int len = 0;
//     Node *plen = *phead;
//     while(plen != NULL){
//         plen = plen->next;
//         len++;
//     }
//     for(int i1 = 0; i1<len; i1++){
//         Node *p = *phead;
//         p = p -> next;
//         for(int i2 = i1+1; i2<len+1; i2++){
//             Node *p1 = *phead;
//             p1 = p1->next;
//             if(p1->data > p->data){
//                 int temp = p1->data;
//                 p1->data = p->data;
//                 p->data = temp;
//             }
//         }
//     }
// }

// void Reverse(Node* head){
// 	if(head == NULL) 
// 		return; 
// 	int len = 0;
//     Node *plen = head;
//     while(plen != NULL){
//         plen = plen->next;
//         len++;
//     }
//     printf("%d\n", len);

//     for(int i1 = len; i1>0; i1--){
//         Node *p = head;
//         for(int i2 = i1; i2>1; i2--){
//             p = p-> next;

//         }
//         printf("%.2f\n", p->data);
//     }
// 	return;
// }



