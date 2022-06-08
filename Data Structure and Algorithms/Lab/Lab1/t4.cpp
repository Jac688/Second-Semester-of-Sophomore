#include<stdio.h>
#include<string.h>
int main(){
    char GPA[5];
    printf("Please enter your grade: ");
    // Determine whether the user input is more than one character
    scanf("%s", &GPA);
    if(strlen(GPA)>=2){
        printf("Warning: Invalid input!");
        return 0;
    }
    
    printf("Your GPA point is: ");
    switch(GPA[0]){
        case 'a':           // That means that 'a' and 'A' are the same case
        case 'A':
            printf("4.00");
            break;          // End the case with the break keyword
        case 'b':           // That means that 'b' and 'B' are the same case;
        case 'B':
            printf("3.00");
            break;
        case 'c':           // That means that 'c' and 'C' are the same case;
        case 'C':
            printf("2.00");
            break;
        case 'd':           // That means that 'd' and 'D' are the same case;
        case 'D':
            printf("1.00");
            break;
        case 'f':           // That means that 'f' and 'F' are the same case;
        case 'F':
            printf("0.00");
            break;
        default :           // The other cases is invalid, put in default
        printf("Warning! Invalid grade!");
    }
    return 0;
}