#include<stdio.h>
#include<string.h>
int main(){
    char str[50];
    printf("Please enter a line of sentence: ");
    int i = 0;  // Initialization
    char com[4];
    while(i < 50){
        scanf("%c", &str[i]);
        // Determine whether the last three letters are 'E','n','d'
        com[0] = str[i-2];
        com[1] = str[i-1];
        com[2] = str[i];
        
        if(strcmp(com, "End") == 0){
            break;
        }
        i++;
    }
    // Output number of string
        printf("%d", i-2);

    printf("\n");
    return 0;
}