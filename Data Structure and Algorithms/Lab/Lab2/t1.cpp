#include<stdio.h>
int comparesASCIICode(char, char);
int main(){
    char a;
    char b;
    printf("Please enter two characters: ");
    scanf("%c %c", &a, &b);  // Read the two characters
    printf("%d\n", comparesASCIICode(a, b));  // Call the function to compare
    return 0;
}

int comparesASCIICode(char a, char b){
    int result = a>b?1:(a==b?0:-1);
    // if(a>b){
    //     return 1;
    // }else if(a==b){
    //     return 0;
    // }else{
    //     return -1;
    // }
    return result;
}