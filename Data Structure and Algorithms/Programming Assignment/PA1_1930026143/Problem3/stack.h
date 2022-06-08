#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct {
	int *values;
	int top;
	int maxTop;
} Stack;

bool CreateStack(Stack *stack, int size);
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

bool Top(Stack* stack, int* x);
/*
    •Returns true if the operation is successful and false otherwise
	•Passes the value of the top element tox
	•x is a pointer to pointee the top value
*/

bool Push(Stack* stack, int x);
/*
    •Add a new element with value x to the top of the stack
	•Returns true if the operation is successful and false otherwise
	•Detemine if the stack if full and return false first else top+1 and return true
*/

bool Pop(Stack* stack, int* x);
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

int postfixEval(char* postfix);
/*
	•Create a stack firstly
	•Cut the string section by section
	•Return the result in the end if the string is valid
	or it will return-1
*/

bool IsNumber(char *c);
/*
	•Determine whether the split string is all numbers
	•Compare the char by ASCII code
	•Return true if all of it is number or return false

*/