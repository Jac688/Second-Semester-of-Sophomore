#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define random(x)(rand()%x)
void InsertionSort(int*, int);
void MergeSort(int*, int, int);
void Merge(int*, int, int, int);

int main(){
    clock_t start3, start4;
    clock_t end3, end4;
    double tim3, tim4;

    // Test the result of 10 numbers
    int A1[10] = {10,9,8,7,6,5,4,3,2,1};

    // Get the length of the A1, A2
    int len1 = sizeof(A1)/sizeof(A1[0]);
    printf("Before InsertionSort: ");
    for(int i=0; i<sizeof(A1)/sizeof(A1[0]); i++)
        printf("%d ", A1[i]);

    // Test the Insertion Sort
    InsertionSort(A1, len1);
    printf("\nAfter InsertionSort: ");
    for(int i=0; i<sizeof(A1)/sizeof(A1[0]); i++)
        printf("%d ", A1[i]);
    
    int A2[] = {10,9,8,7,6,5,4,3,2,1};
    printf("\nBefore MergeSort: ");
    for(int i=0; i<sizeof(A1)/sizeof(A1[0]); i++){
        printf("%d ", A2[i]);
    }
    // Test the Merge Sort
    MergeSort(A2, 0, len1-1);
    printf("\nAfter MergeSort: ");
    for(int i=0; i<sizeof(A1)/sizeof(A1[0]); i++){
        printf("%d ", A2[i]);
    }
    
    printf("\n========================================\n");
    printf("\nSize = 10^5:\n");
    // The amount of allocated dynamic space is 10^5
    int* A3 = (int*)malloc(sizeof(int)*100000);

    for(int i=0; i<100000; i++){
        // Use the rand() to generate
        A3[i] = random(100);
    }

    // Test the number 10^5
    int len2 = 100000;
    start3 = clock();  // The start time (Insertion Sort)
    InsertionSort(A3, len2);
    end3 = clock();  // The end time (Insertion Sort)
    
    tim3 = (double)(end3-start3);  // The time interval

    int* A4 = (int*)malloc(sizeof(int)*100000);
    for(int i=0; i<100000; i++){
        A4[i] = random(100);
    }

    start4 = clock();  // The start time (Merge Sort)
    MergeSort(A4, 0, len2-1); 
    end4 = clock();  // The end time (Merge Sort)
    tim4 = (double)(end4-start4);  // The time interval
    printf("Insertion time: %.2lf ms and Merge time: %.2lf ms", tim3, tim4);
    
    free(A3);
    free(A4);
    return 0;
}

void InsertionSort(int *A, int n){
    int i, j = 0;
    int temp = 0;
    for(i=1; i<n; i++){
        temp = A[i];  // Recond the right(insertion) values
        j = i-1;
        while(j>=0 && A[j]>temp){
            A[j+1] = A[j];  // If left one is bigger than insertion one 
            j--;  // Move forward
        }
        A[j+1] = temp;  // Insertion values
    }
}

void MergeSort(int *A, int left, int right){
    // Illegal input
    if(right < left)  
        printf("Warnning! Invalid input!");
    // Basic case
    if(left == right)
        return;

    // Complete the dichotomy with recursion
    int middle = (left+right)/2;
    // Separate left
    MergeSort(A, left, middle);
    // Separate right
    MergeSort(A, middle+1, right);
    // Sort and merge
    Merge(A, left, middle, right);
}

void Merge(int* A, int left, int middle, int right){
    int *B = (int*)malloc(sizeof(int)*(right-left+1));
    int i1 = left, i2 = middle+1, i=0;
    // The left half of the array is compared to the right half
    while(i1<=middle && i2<=right){
        // Pick out the smaller one and assign it to B
        if(A[i1] < A[i2]){
            B[i++] = A[i1++];
        }
        else{
            B[i++] = A[i2++];
        }
    }
    // And then we just assign the rest of the numbers directly to B
    while(i1 <= middle){
        B[i++] = A[i1++];
    } 
    while(i2 <= right){
        B[i++] = A[i2++];
    }
    // Copy B to A
    for(int i=0, n=left; i<=right-left; i++, n++)
        A[n] = B[i];
    free(B);
}