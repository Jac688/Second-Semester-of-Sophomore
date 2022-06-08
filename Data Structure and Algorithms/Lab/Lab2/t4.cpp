#include<stdio.h>

int GCD(int, int);
int main(){
    int a, b;
    printf("Please enter two integers: ");
    scanf("%d %d", &a, &b);  // Reead the two integers
    int di = GCD(a, b);  // Call the function to get the GCD
    printf("The greatest common divisor of these number is: %d\n", di);
    return 0;
}

int GCD(int x, int y){
    // Division by tossing
    if(y == 0){
        return x;  // Base
    }
    if(y > 0){
        GCD(y, x%y);  // Step
    }
}