/* for Visual Studio users */
#include "stack.h" 
/* for VS code users */
//#include "stack.cpp" // for VS Code users

bool CreateStack(Stack *stack, int size){
    // Detemine the maxTop if is larger than zero
	if(size <= 0)
		return false;

    // Allocate memory space
	stack -> values = (double*)malloc(sizeof(double)*size);

    // The initialization default value is -1 and the stack is empty
	stack -> top = -1;
	stack -> maxTop = size -1;
	return true;
}

bool Push(Stack *stack, double x){
    // If the stack is full, we cannot push something
	if(IsFull(stack))
		return false;
	stack->values[++stack->top] = x;
	return true;
}

bool Pop(Stack *stack, double *x){
    // If the stack is full, we cannot push something
	if(IsEmpty(stack) == true)
		return false;

    // x is a pointer to top_value
	*x = stack->values[stack->top];

    // Or stack->values[stack->top--] = NULL;
	stack->values[stack->top] = NULL;
	stack->top--;
	return true;
}

void DisplayStack(Stack* stack){
    // Detemined if the stack is empty
	if(stack == NULL || IsEmpty(stack) == true){
		printf("\nThe stack is NULL or not existing");
		return;
	}
    
    printf("\nThe stack has these number: ");
    // Start at zero and stop at top
	for(int i=stack->top; i>=0; i--){
        // Keep two decimals
		printf("%.2f ", stack->values[i]);
	}
}

void DestroyStack(Stack **pstack){
    // clear the stack
	free((*pstack) -> values);
	(*pstack)->top = -1;
	(*pstack)->maxTop = 0;
	free(*pstack);
	*pstack = NULL;
    printf("\nDestroy the stack successfully!");
}

bool IsEmpty(Stack* stack){
	if(stack == NULL){
		printf("The stack is NULL");
		return true;;
	}
	if(stack->top == -1)
		return true;
	else
		return false;
}

bool IsFull(Stack* stack){
	if(stack == NULL){
		printf("The stack is NULL");
		return false;
	}
	if(stack->top == stack->maxTop)
		return true;
	else
		return false;
}

bool Top(Stack* stack, double* x){
	if(stack == NULL){
		printf("The stack is NULL");
		return false;
	}
    if(IsEmpty(stack) == true){
        return false;
    }
    // x pointee to the top value
    *x = stack->values[stack->top];
	return true;
}

