#include<stdlib.h>
#include<stdio.h>
#include<time.h>
// typedef struct{
//     int* size;
//     int max = 10;
// }Stack;

bool Insert(int* , int, int);
int DeleteMin(int*, int);
void Swap(int*, int, int);
bool IsEmpty(int);
bool HaveChildren(int, int);
int IndexLarger(int*, int);
void HeapSort(int*, int);

int main(){
    // The size of array is 10
    printf("\n============ Size = 10 ==============\n");
    int *A1 = (int*)malloc(sizeof(int)*10);
    int len1 = _msize(A1)/sizeof(int);
    printf("Before HeapSort: ");
    // Before the Heap sort
    for(int i = 0; i<len1; i++){
        A1[i] = rand()/100;
        printf("%d ", A1[i]);
    }

    printf("\n");
    HeapSort(A1, len1);
    printf("After HeapSort: ");
    for(int i = 0; i<len1; i++){
        printf("%d ", A1[i]);
    }
    free(A1);

    printf("\n\n=========== Size = 10^5 =============\n");
    clock_t start, end;
    double tim;
    // The amount of allocated dynamic space is 10^5
    int* A2 = (int*)malloc(sizeof(int)*100000);
    int len2 = _msize(A2)/sizeof(int);  // 100000
    for(int i=0; i<len2; i++){
        // Use the rand() to generate
        A2[i] = rand()/10;
    }

    // Test the number 10^5
    start = clock();  // The start time (Insertion Sort)
    HeapSort(A2, len2);
    end = clock();  // The end time (Insertion Sort)
    tim = (double)(end-start);  // The time interval
    printf("The time of HeapSort: %.2lf ms.\n", tim);
    return 0;
}

void HeapSort(int *A, int size){
    for(int i = 0; i<= size-1; i++){
        // maximum heap is used here
        Insert(A, i, A[i]);
    }
    for(int i = size-1; i >= 0; i--){
        // minimum heap is used here
        A[i] = DeleteMin(A, i+1);
    }
}

bool Insert(int* A, int size, int x){
    int hole;
    hole = size++;
    // Detemine the x is larger than its superior
    while(hole>0 && x>A[(hole-1)/2]){
        // Replace the children's data and move to the its superior
        A[hole] = A[(hole-1)/2];
        hole = (hole-1)/2;
    }
    A[hole] = x;
    return true;
}

int DeleteMin(int* A, int size){
    if(IsEmpty(size))
        return 0;
    int max = A[0], hole = 0, x = A[--size];
    // percolate down
    int sid = 0;
    while(HaveChildren(hole, size)){
        // Get the index of the larger child
        sid = IndexLarger(A, hole);
        if(x>=A[sid]){
            break;
        }
        // Replace the super's data and move to the smaller child
        A[hole] = A[sid];
        hole = sid;
    }
    A[hole] = x;
    return max;
}

// Detemineif the heap is empty 
bool IsEmpty(int size){
    if(size < 0)
        return true;
    else    
        return false;
}

// Find the max value of children 
// and return the index of the child
int IndexLarger(int* A, int hole){
    int l = A[2*hole+1];
    int r = A[2*hole+2];
    if(r > l)
        return 2*hole+2;
    else
        return 2*hole+1;
}

// Detemine if the hole has two children
bool HaveChildren(int hole, int size){
    // Compare with the size
    if(hole*2+2 <= size)
        return true;
    else   
        return false;
}
