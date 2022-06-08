/* for Visual Studio users */
#include "stack.h" 
/* for VS code users */
//#include "stack.cpp" // for VS Code users

bool CreateStack(Stack *stack, int size){
    // Detemine the maxTop if is larger than zero
	if(size <= 0)
		return false;

    // Allocate memory space
	stack -> values = (int*)malloc(sizeof(int)*size);

    // The initialization default value is -1 and the stack is empty
	stack -> top = -1;
	stack -> maxTop = size -1;
	return true;
}

bool Push(Stack *stack, int x){
    // If the stack is full, we cannot push something
	if(IsFull(stack))
		return false;
	stack->values[++stack->top] = x;
	return true;
}

bool Pop(Stack *stack, int *x){
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
		printf("%d ", stack->values[i]);
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

bool Top(Stack* stack, int* x){
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

// Include the postfixEval and IsNumber method.
int postfixEval(char* postfix){
	// If the string is null, return -1 
	if(!postfix){
		printf("\nWarning, the input is not existing.");
		return -1;
	}
	// Allocation memory space
	int* i=(int *)malloc(sizeof(int));
	int* j=(int *)malloc(sizeof(int));
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	CreateStack(stack, 50);
	// Split a string by Spaces
	char* c = strtok(postfix, " ");
	while(c){
		// It is a number case
		if((*c != '*' && *c != '+' && *c != '-' && *c != '/') && IsNumber(c))
			Push(stack, atoi(c));
		// It is a operation case
		else if(*c == '*' || *c == '+' || *c == '-' || *c == '/'){
			if(stack->top > 0){
				// pop the top two elements firstly 
				Pop(stack, i);
				Pop(stack, j);
				// Then push the result by the operation
				if(*c == '*'){
					Push(stack, (*i) * (*j));
				}
				if(*c == '+'){
					Push(stack, (*i) + (*j));
				}
				if(*c == '-')
					Push(stack, (*j) - (*i));
				if(*c == '/'){
					// Should take attention to divide by zero
					if((*i) == 0){
						printf("Cannot be divided by zero! ");
						return -1;				
					}
					Push(stack, (*j) / (*i));
				}
			}
			// It is other cases which is not valid
			else{
				return -1;
			}
		}
		else{
			return -1;
		}
		c = strtok(NULL, " ");
	}
	// The number of elements must be one
	if(stack->top != 0)
		return -1;
	return stack->values[stack->top];
}

// Use this function to detemine the string is a number
bool IsNumber(char *c){
	int cnt = 0;
	int i = 0;
	while(*(c+i)!='\0'){
    	if(*c>='0' && *c<='9')
			cnt++;
		i++;
	}
	if(cnt == strlen(c))
		return true;
	else
		return false;
}

