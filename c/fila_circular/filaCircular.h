#ifndef FILACIRCULAR_H
#define FILACIRCULAR_H

typedef struct Queue {
	int size;
	int first;
	int last;
	int * array;
} Queue;

Queue * newQueue();

Queue * newQueue2(int sizeofQueue);

int enqueue(Queue * queue, int item);

int dequeue(Queue * queue);

void showItens(Queue * queue);

void freeQueue(Queue * queue);

#endif
