#include<stdio.h>
#include<stdlib.h>

typedef struct{
    double* values;
    int front;
    int rear;
    int counter;
    int maxSize;
} Queue;

bool CreateQueue(Queue *queue, int size);
/*
    •Creates an empty queue whose capacity is size
    •Input the size of the queue
    •The front is 0 and the rear is -1 at the begin
*/

bool IsEmpty(Queue* queue);
/*
    •Returns true if the queue is empty and false otherwise
    •Detemined if the queue is null firstly
*/

bool IsFull(Queue* queue);
/*
    •Returns true if the queue is full and false otherwise
    •Detemined if the queue is null firstly
*/

bool Enqueue(Queue* queue, double x);
/*
    •Adds a new element with value xto the rear of the queue
    •Returns true if the operation is successful and false otherwise
    •Returns true if the queue is full and false otherwise
    •front+1 % size and it is a circle 
*/

bool Dequeue(Queue* queue, double* x);
/*
    •Removes an element from the front of the queue
    •Returns true if the operation is successful and false otherwise
    •Passes the value of the front element to x
    •rear+1 % size and it is a circle
    •x is a pointer and pointee to the deleted one
*/

void DisplayQueue(Queue* queue);
/*
    •Prints all the elements of the queue,from front to rear
    •Traverse the circle and use the % to restart
*/

void DestroyQueue(Queue**pqueue);
/*
    •Frees the memory occupied by the values in queue and queue struct
    •Set the queue pointer to NULL
    •To be on the safe side, reset the front and rear of our queue
*/