#include "queue.h"

bool CreateQueue(Queue *queue, int size){
    // Detemine that if the input is invalid
    if(size <= 0)
        return false;
    // Allocate memory space
    queue->values = (double*)malloc(sizeof(double)*size);
    // Initialization, rear=0 means that is NULL now
    queue->front = 0;
    queue->rear = -1;
    queue->counter = 0;
    queue->maxSize= size;
    return true;
}

bool IsEmpty(Queue* queue){
    // The first thing you have to do is determine that the queue exists
    if(queue != NULL){
        // counter is the number of the numbers
        if(queue->counter == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        printf("\nThe queue is NULL.");
        return false;
    }
}

bool IsFull(Queue* queue){
    // The first thing is determine that the queue exists
    if(queue != NULL){
        // counter == maxSize and reach the maximum number
        if(queue->counter == queue->maxSize){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        printf("\nThe queue is NULL.");
        return false;
    }
}

bool Enqueue(Queue* queue, double x){
    if(IsFull(queue)){
        printf("Warning! The queue is full.\n");
        return false;
    }
    // % queue->maxSize means that is a circular queue
    queue->rear = (queue->rear+1) % queue->maxSize;
    // Assign and counter+1
    queue->values[queue->rear] = x;
    queue->counter++;
    return true;
}

bool Dequeue(Queue* queue, double* x){
    if(IsEmpty(queue))
        return false;
    *x = queue->values[queue->front];
    // Front also varies with the circle
    queue->front = (queue->front+1) % queue->maxSize;
    // front changes and counter-1
    queue->counter--;
    return true;
}

void DisplayQueue(Queue* queue){
    // Determine that the queue exists
    if(queue == NULL){
        printf("\nThe queue is NULL.");
        return;
    }
    // Determines if the queue is empty
    if(IsEmpty(queue)){
        printf("The queue is empty.");
        return;
    }
    // Most important!
    /*  1. loop from the front
        2. The times of the loop 
        3. Thes index in the values should reminder maxSize
           because of the circle
    */
    printf("The number in the queue are: ");
    for (int i=queue->front; i< queue->front+(queue->counter); i++){
        printf("%.2f  ", queue->values[i % queue->maxSize]);
    }
}

void DestroyQueue(Queue**pqueue){
    // Reset the value
    (*pqueue)->counter = 0;
    (*pqueue)->rear = -1;
    (*pqueue)->front = 0;  
    // Free memory and makes the pointer null
    free((*pqueue)->values);
    free(*pqueue);
    *pqueue = NULL;
}