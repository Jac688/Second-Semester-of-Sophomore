#include<stdio.h>
#include<stdlib.h>
#include <time.h>
void QuickSort(int[], int, int);
int Conquar(int[], int, int);
void Median3(int[], int, int);
void Swap(int[], int, int);

int main(){
    // The size of array is 10
    printf("\n\n============ Size = 10 ==============\n");
    int *A1 = (int*)malloc(sizeof(int)*10);
    int len = 10;
    printf("Before QuickSort: ");
    // Before the quick sort
    for(int i = 0; i<len; i++){
        A1[i] = rand();
        printf("%d ", A1[i]);
    }

    printf("\n");
    QuickSort(A1, 0, len-1);
    printf("After QuickSort: ");
    for(int i = 0; i<len; i++){
        printf("%d ", A1[i]);
    }
    free(A1);

    printf("\n\n=========== Size = 10^5 =============\n");
    clock_t start, end;
    double tim;
    // The amount of allocated dynamic space is 10^5
    int* A2 = (int*)malloc(sizeof(int)*100000);

    for(int i=0; i<100000; i++){
        // Use the rand() to generate
        A2[i] = rand();
    }

    // Test the number 10^5
    int len2 = 100000;
    start = clock();  // The start time (Insertion Sort)
    QuickSort(A2, 0, len2-1);
    end = clock();  // The end time (Insertion Sort)
    tim = (double)(end-start);  // The time interval
    printf("The time of QuickSort: %.2lf ms.\n", tim);
    return 0;
}

void QuickSort(int *A, int left, int right){
    // In the end, you should detemine the order of the last two one
    if(left+1 >= right){
        if(A[left]>A[right]){
            Swap(A,left,right);
        }
        return;
    }
    // p is the middle of the two part
    int p = Conquer(A,left,right);
    // The left recursion
    QuickSort(A, left, p-1);
    // The right recursion
    QuickSort(A, p+1, right);
}

int Conquer(int *A, int left, int right){
    Median3(A, left, right);
    // right-1 is the pivot
    int i = left+1, j = right-2, p = A[right-1];
    while(1){
        // Find the left-hand side that starts bigger than pivot
        while(A[i]<p)
            i++;
        // Find the right-hand side that starts smaller than pivot
        while(A[j]>p)
            j--;
        // If it's bigger than pivot and smaller than pivot, it's transposition
        if(i<j){
            Swap(A,i,j);
            i++;
            j--;
        }
        else{
            break;
        }
    }
    // Turn the privot to the middle of two part 
    Swap(A, i, right-1);
    // i as the new pivot
    return i;
}

// Before the Divide the large and the small in half
// Use Median3 to estimate the pivotdwsxaz
void Median3(int *A, int left, int right){
    int median = (right+left)/2;
    if(A[left]>A[median])
        Swap(A, left, median);
    if(A[median]>A[right])
        Swap(A, median, right);
    // After compare between the right and median
    // It should compare the left and median again
    if(A[left]>A[median])
        Swap(A, left, median);

    // return the pivot to the last but one
    Swap(A, median, right-1);
    return ;
}

// Swap the value of two positions in the array
void Swap(int *A, int i, int j){
    int temp;
    temp = A[i];
    A[i] = A[j];
    A[j] = temp;
    return ;
}