#include<stdio.h>

#include<string.h>
void reverseR(int , char *);
int main(){
    char str[50];
    printf("Please enter a string: ");  // Read the string
    scanf("%s", str);
    int length = strlen(str);
    
    reverseR(length, str);  // Call the function to reverse string
    printf("The reverse order of the sentence is: ");
    printf("%s\n",str);

    return 0;
}

void reverseR(int length, char *str){
    int i = strlen(str);   // The length of string(will not change)
    int half = i/2;
    // If the length is reduced to half, recursion will stop
    if(length <= half){  
        return ;
    }

    if(length > half){
        // The first character swap place with the last one by pointer
        char temp = *(str+i-length);
        *(str+i-length) = *(str+length-1);
        *(str+length-1) = temp;
    }
    reverseR(length-1, str);  // "length" will change every times
}