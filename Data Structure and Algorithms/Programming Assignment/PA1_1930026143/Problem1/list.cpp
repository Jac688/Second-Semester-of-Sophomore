#include "list.h"


void ReverseList(Node** phead){
    // Detemine the list if is null
    if(*phead == NULL){
        printf("This list is NULL.\n");
        return;
    }

    Node* pre = NULL; 
    Node* curr = *phead; 

    // Use the nextTemp to recond the next code
    // The next code pointee to previous code
    while (curr->next != NULL) {
        Node* nextTemp = curr->next; 
        curr->next = pre; 
        pre = curr;
        curr = nextTemp; 
    }
    // Connect the last code and finish
    curr->next = pre;
    *phead = curr;
}


int DeleteNodes(Node** phead, double x){
    // Detemine if the stack is null
    if(*phead == NULL || IsEmpty(*phead) == true){
        printf("This list is null or empty.\n");
        return 0;
    }
    Node* cur = *phead;;
    int cnt = 0;
    while(cur->next != NULL){
        // The node should be deleted happen in head pointer
        if(Compare((*phead)->data,x)){
            (*phead) = cur->next;
            cur = *phead;
            // use cnt to count the deleted number
            cnt++;
        }
        // The node should be deleted happen in other nodes
        else if(Compare(cur->next->data,x)){
            cur->next = cur->next->next;

            cnt++;
        }
        else{
            cur = cur->next;
        }
    }
    // return the number
    return cnt;
}

void RemoveDuplicates(Node** phead){
    // Detemine if the list is null
	if (phead == NULL || IsEmpty(*phead))
	{
		printf("The list is not existing or empty!\n");
		return ;
	}

	// Use temp to recond the next node
    Node *pre = NULL;
    Node *pnext = NULL;
    Node *cur = *phead;
    

	while (cur != NULL)
	{
		//If the current node and the next node have the same value
		if(cur->next!=NULL && (cur->next->data == cur->data))
		{
			pnext = cur->next;
			// The duplicates are adjacent and detemine if they are equal
			while(pnext!=NULL && (cur->data==pnext->data)){
				pnext = pnext->next;
			}
			//if current node happen in  head pointer case
			if(cur == *phead)
				*phead = pnext;
			//if current node happen in other nodes case 
			else
				pre->next=pnext;
			cur = pnext;
		}
        // If they are not equal to each other, then pass to the next node
		else{
			pre = cur;
			cur = cur->next;
		}
	}
}

bool Compare(double a, double b){
    if(abs(a-b)<=0.000001)
        return true;
    else{
        return false;
    }
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


