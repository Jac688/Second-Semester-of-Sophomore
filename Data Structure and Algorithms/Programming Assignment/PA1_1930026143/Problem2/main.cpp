#include "stack.cpp"

int main() {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	CreateStack(stack);
    // Case1: The input string is empty
    if(ValidBrackets("")==true)
        printf("True\n");
    
    // Case2: The input string that meets the requirements
    if(ValidBrackets("{[()]}")==true)
        printf("True\n");

    // Caes3: The input is NULL
    if(ValidBrackets(NULL)==false)
        printf("True\n");

    // Case4: The string before and after does not correspond
    if(ValidBrackets("{]")==false)
        printf("True\n");

    // Case5: Reverse position of open and closing parentheses
    if(ValidBrackets(")]}{{[(")==false)
        printf("True\n");

    // Case6: There are only open parentheses in the string
    if(ValidBrackets("{[(")==false)
        printf("True\n");

    // Case7: There are only closing parentheses in the string
    if(ValidBrackets(")]}")==false)
        printf("True\n");

    // Case8: Other characters appear without parentheses
    if(ValidBrackets("xsj")==false)
        printf("True\n");

    return 0;
}
