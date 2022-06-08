#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char *values;
	int top;
	int maxTop;
} Stack;

bool CreateStack(Stack *stack);
/*
    •Creates an empty queue whose capacity is size
	•Memory needs to be allocated dynamically
*/

bool IsEmpty(Stack* stack);
/*
    Detemines if the stack is empty and false otherwise
	That means that the top is still -1
	should detemine if the stack is null first
*/

bool IsFull(Stack* stack);
/*
    •Detemines if the stack is full and false otherwise
	•That means that the top is eaual to maxTop
	•should detemine if the stack is null first
*/

bool Top(Stack* stack, char* x);
/*
    •Returns true if the operation is successful and false otherwise
	•Passes the value of the top element tox
	•x is a pointer to pointee the top value
*/

bool Push(Stack* stack, char x);
/*
    •Add a new element with value x to the top of the stack
	•Returns true if the operation is successful and false otherwise
	•Detemine if the stack if full and return false first else top+1 and return true
*/

bool Pop(Stack* stack, char* x);
/*
	•Remove an element from the top of the stack
	•Returns true if the operation is successful and false otherwise
	•Passes the value of the top element to x, x pointee to top
	•Detemine if the stack if empty and return false first else top+1 and return true
*/

void DisplayStack(Stack* stack);
/*
	•Display the elements in stack from top to bottom
	•Detemined the stack if is null first
	•The stack is traversed from top to 0
*/

void DestroyStack(Stack**pstack);
/*
	•Frees the values of the stack firstly
	•Frees the memory occupied by the stack struct
	•Then point the stack to NULL 
*/

bool ValidBrackets(char* str);
/*
	•Create a stack firstly
	•Push the first half of the string onto the stack
	•Then pop it out one by one and compare it to the rest of the segment
*/

