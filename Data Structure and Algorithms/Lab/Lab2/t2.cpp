#include<stdio.h>
int Sum(int);
int main(){
    int n = 0;
    printf("Please enter a number: ");
    scanf("%d", &n);   // Read the number

    if(n < 0){
        printf("Invalid input: the number cannot be less than 0!");
        return 0;
    }
    printf("%d\n", Sum(n)); 
    return 0;
}

int Sum(int n){
    if(n == 0){  // Base
        return 0;
    }
    return n+Sum(n-1);  // Step
}