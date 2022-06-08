#include<stdio.h>

int main(){
    int a = 0;  // Initialization
    int b = 0;  // Initialization
    printf("Please enter the two numbers: ");
    scanf("%d %d", &a, &b);
    printf("The bigger one is: %d\n", a>b?a:b);
    /* same as:
    if(a>b){
        printf("%d", a);
    }
    else{
        printf("%d", b);
    }
    */
    return 0;
}