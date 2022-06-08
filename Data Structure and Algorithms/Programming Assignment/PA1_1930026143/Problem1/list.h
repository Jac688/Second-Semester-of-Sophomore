#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	double data;
	struct node* next; 
} Node;

bool IsEmpty(Node* head);
/*
 function:
	tests whether a list is empty
 input:
	head - pointer to the first node
 output:
	true if the list is empty and false otherwise
*/

Node* InsertNode(Node** phead, int index, double x);
/*
 function:
	inserts a new node with certain data after a certain position
 input:
	phead - pointer to the pointer to the first node
	index - the new node is inerted after position index
			insert a new node as the head if index=0
	x - data of the new node
 output:
	a pointer to the new node if insertion is successful and NULL otherwise
*/

int FindNode(Node* head, double x);	
/*
 function:
	finds node with certain data
 input:
	head - pointer to the first node
	x - the first node whose data=x is returned
 output:
	returns the position of the first node whose data=x
	returns 0 if no such node exists
*/

int DeleteNode(Node** phead, double x);
/*
 function:
	deletes a node with certain data
 input:
	phead - pointer to the pointer to the first node
	x - the first node whose data=x is deleted	
 output:
	returns the position of the deleted node
	returns 0 if no such node exists
*/

void DisplayList(Node* head);
/* 
 function:
	prints all the nodes in the list
 input:
	head - pointer to the first node
*/

void DestroyList(Node** phead);
/*
 function:
	deletes all the nodes in the list and frees the memory occupied by them
 input:
	phead - pointer to pointer to the first node
*/

bool Compare(double, double);
/*
 function: 
	Compare two numbers of type double which cannot compare by "==" directly
 input:
	Two doubles that need to be compared
 output:
    true or false
*/

int DeleteNodes(Node** phead, double x);
/*
 function: 
	Deletes all the nodes in the linked list that are equal to the input value
 input:
	phead - pointer to the pointer to the first node
	x - the first node whose data=x is deleted	
 output:
	returns the position of the deleted node
	returns 0 if no such node exists
*/

void RemoveDuplicates(Node** phead);
/*
 function: 
	Deletes all the nodes in the linked list that are more than one
 input:
	phead - pointer to the pointer to the first node	
*/

void ReverseList(Node** phead);
/*
 function: 
	Connect the nodes in the list backwards (in reversed case)
 input:
	phead - pointer to the pointer to the first node	
*/
