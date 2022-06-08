#include "list.cpp"

int main(){
    // Duplicates happen in the tail of the list
	Node *head1 = 0;
    for (int i = 0; i < 5; i++)
        InsertNode(&head1, 0, i);
    InsertNode(&head1, 5, 0);
    printf("Before RemoveDuplicates: ");
    DisplayList(head1);
    RemoveDuplicates(&head1);
    printf("After RemoveDuplicates: ");
    DisplayList(head1);
    printf("\n");

    // Duplicates happen in the head of the list
    Node *head2 = 0;
    for (int i = 0; i < 3; i++)
        InsertNode(&head2, i, 1);
    InsertNode(&head2,3,3);
    printf("Before RemoveDuplicates: ");
    DisplayList(head2);
    RemoveDuplicates(&head2);
    printf("After RemoveDuplicates: ");
    DisplayList(head2);
    printf("\n");

    // There are multiple duplicate values, and they are adjacent
    Node *head3 = 0;
    for (int i = 0; i < 8; i++) {
        if (i < 3)
            InsertNode(&head3, i, 1);
        else if(i < 5)
            InsertNode(&head3, i, 2);
        else InsertNode(&head3,i,3);
    }
    InsertNode(&head3,8,4);
    printf("Before RemoveDuplicates: ");
    DisplayList(head3);
    RemoveDuplicates(&head3);
    printf("After RemoveDuplicates: ");
    DisplayList(head3);
    printf("\n");
    
    // There are multiple duplicate values, and they are not adjacent
    Node *head4 = 0;
    for (int i = 0; i < 8; i++) {
        if (i < 3)
            InsertNode(&head4, i, 1);
        else if(i < 5)
            InsertNode(&head4, i, 2);
        else InsertNode(&head4,i,3);
    }
    InsertNode(&head4,5,4);
    printf("Before RemoveDuplicates: ");
    DisplayList(head4);
    RemoveDuplicates(&head4);
    printf("After RemoveDuplicates: ");
    DisplayList(head4);
    printf("\n");

    // DeleteNodes happen in the tail of the list
    Node* head5 = 0;
    for(int i = 0;i < 5;i++)
        InsertNode(&head5,i,i);
    InsertNode(&head5,5,4);
    printf("Before DeleteNodes: ");
    DisplayList(head5);
    DeleteNodes(&head5, 4);
    printf("After DeleteNodes: ");
    DisplayList(head5);
    printf("\n");

    // DeleteNodes happen in the head of the list
    Node* head6 = 0;
    for(int i = 0;i < 5;i++)
        InsertNode(&head6,i,i);
    InsertNode(&head6,0,4);
    printf("Before DeleteNodes: ");
    DisplayList(head6);
    DeleteNodes(&head6, 4);
    printf("After DeleteNodes: ");
    DisplayList(head6);
    printf("\n");

    // Test ReverseList method with a list which is not duplicate
    Node* head7 = 0;
    for(int i = 0;i < 5;i++)
        InsertNode(&head7,i,i);
    printf("Before RemoveDuplicates: ");
    DisplayList(head7);
    RemoveDuplicates(&head7);
    printf("After RemoveDuplicates: ");
    DisplayList(head7);
    ReverseList(&head7);
    printf("After ReverseList: ");
	DisplayList(head7);
    
    printf("\nThe NULL cases:\n");
    // Test the case that the argument is null
    Node* head8 = NULL;
    DeleteNodes(&head8, 8);
    RemoveDuplicates(&head8);
    ReverseList(&head8);
}

