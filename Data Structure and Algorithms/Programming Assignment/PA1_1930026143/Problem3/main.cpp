#include "stack.cpp"


int main() {
    printf("\nThese are some cases have error:\n");
    // Case1: Operator is preceded by less than two digits
    char s1[50] = "1 + +";
    int r1 = postfixEval(s1);
    if(r1 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r1);

    // Case2: Numbers and operators are reversed
    char s2[50] = "2 + 3";
    int r2 = postfixEval(s2);
    if(r2 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r2);

    // Case6: There are only some numbers
    char s6[50] = "1 0 14";
    int r6 = postfixEval(s6);
    if(r6 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r6);

    // Case7: Worst case scenario
    char s7[50] = "+ 2";
    int r7 = postfixEval(s7);
    if(r7 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r7);

    // Case8: End up with more than one value in the stack
    char s8[50] = "2 3 4 +";
    int r8 = postfixEval(s8);
    if(r8 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r8);

    // Case9: Divide by 0 in a division operation
    char s9[50] = "2 3 4 + - 4 * 0 /";
    int r9 = postfixEval(s9);
    if(r9 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r9);


    // Case11: Characters that do not contain operators and numbers
    char s11[50] = "xsj";
    int r11 = postfixEval(s11);
    if(r11 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r11);
    
    printf("=============================================\n");
    
    printf("There are corrected cases:\n");
    // Case3: Simply test the correct case
    char s3[50] = "2 3 +";
    int r3 = postfixEval(s3);
    if(r3 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r3);

    // Case4: Complex test for correct conditions
    char s4[50] = "9 1 3 * /";
    int r4 = postfixEval(s4);
    if(r4 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r4);

    // Case5: Complex test of the intersection of operators and numbers
    char s5[50] = "2 10 + 9 6 - /";
    int r5 = postfixEval(s1);
    if(r5 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r5);

    // Case10: Not divide by 0 in a division operation
    char s10[50] = "2 3 4 + - 4 * 2 /";
    int r10 = postfixEval(s10);
    if(r10 == -1)
        printf("Warning! The input string is invalid.\n");
    else
        printf("The result is %d.\n", r10);
    
}
