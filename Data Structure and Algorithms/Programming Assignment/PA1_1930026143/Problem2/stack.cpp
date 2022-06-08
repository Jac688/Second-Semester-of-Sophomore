#include "stack.h" 

bool ValidBrackets(char* str) {
	// Allocate dynamic memory
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	CreateStack(stack);
	// detemined if it is null
    if(!str)
        return false;
	if(str == "")
		return true;
	// The length if the string must be even
	if(strlen(str)%2!=0){
		return false;
	}

	for(int i = 0; i < strlen(str)/2; i++){
		// The first half must be in front parentheses
		if((*(str+i)) =='{' || (*(str+i)) == '[' || (*(str+i)) == '('){
			// and push to the stack
			Push(stack, *(str+i));
		}
		// Or return false
		else{
			return false;
		}
	}
	char *p = (char*)malloc(sizeof(char));
	for(int i = 0; i < strlen(str)/2; i++){
		// Determine whether the parentheses correspond one-to-one
		Pop(stack, p);
		if(((*p == '{' && (*(str+(strlen(str)/2)+i)) != '}')) || ((*p == '(' && (*(str+(strlen(str)/2)+i)) != ')')) || ((*p == '[' && (*(str+(strlen(str)/2)+i)) != ']')))
			return false;
	}
    return true;
}

bool CreateStack(Stack *stack){
    // Allocate memory space
	stack -> values = (char*)malloc(sizeof(char)*50);
    // The initialization default value is -1 and the stack is empty
	stack -> top = -1;
	stack -> maxTop = 49;
	return true;
}

bool Push(Stack *stack, char x){
    // If the stack is full, we cannot push something
	if(IsFull(stack))
		return false;
	stack->values[++stack->top] = x;
	return true;
}

bool Pop(Stack *stack, char *x){
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
	for(int i=0; i<=stack->top; i++){
        // Keep two decimals
		printf("%c ", stack->values[i]);
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

bool Top(Stack* stack, char* x){
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

