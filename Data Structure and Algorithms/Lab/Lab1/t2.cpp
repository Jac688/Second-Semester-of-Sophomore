#include<stdio.h>

/*
int main(){
    int value1, value2, sum;
    value1 = 50;
    value2 = 25;
    sum = value1 + value2;
    printf("The sum of %d and %d is %d\n", value1, value2, sum );
    system("pause");
    return 0;
}
*/

// The output is: The sum of 50 and 25 is 75

/* If only Change int to float and check the result, it will get some error,
   because the %d is decimal signed integer but not float
*/

int main(){
    float value1, value2, sum;
    value1 = 50;
    value2 = 25;
    sum = value1 + value2;
    printf("The sum of %.1f and %f is %f\n", value1, value2, sum );

    return 0;
}
// The sum of 50.0 and 25.000000 is 75.000000