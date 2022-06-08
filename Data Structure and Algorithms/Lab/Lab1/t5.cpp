#include<stdio.h>
int main(){
    char str[50];  // Total number of characters will not exceed 50
    printf("Plaese enter a string: ");
    scanf("%s", str);
    int i = 0;
    for(i=0; i<50; i++){
        if(str[i] == '\0')  // If it read the space, the loop will break
            break;  // i is the times of the loop and length of the string
    }
    printf("The string is: %s\n", str);
    printf("The length of the string is: %d\n", i);

    return 0;
}