#include "queue.cpp" // for VS code users
// #include "queue.h"  // for visual studio users


int main(void) {
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	double value;
	CreateQueue(queue, 5);
	puts("Enqueue 5 items ...");
	
	for (int x = 0; x < 5; x++)
		Enqueue(queue, x);
	DisplayQueue(queue);
	

	puts("\nNow attempting to enqueue 5 ...");
	Enqueue(queue, 5);
	DisplayQueue(queue);
	
	Dequeue(queue, &value);
	printf("\nRetrieved element = %f\n", value);
	
	while(!IsEmpty(queue))
		Dequeue(queue, &value);
	DisplayQueue(queue);
	
	puts("\nNow attempting to enqueue 7 ...");
	Enqueue(queue, 7);
	DisplayQueue(queue);
	
	DestroyQueue(&queue);
	DisplayQueue(queue);
}
