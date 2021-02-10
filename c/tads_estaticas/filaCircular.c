#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
	int size;
	int first;
	int last;
	int * array;
} Queue;

Queue * newQueue() {
	Queue * queue = (Queue *) malloc(sizeof(Queue));
	queue->first = 0; 
	queue->last = 0;
	// default size of the queue is 10.
	queue->size = 10;
	queue->array = (int *) malloc(sizeof(int) * 11);
	return queue;
}

Queue * newQueue2(int sizeofQueue) {
	Queue * queue = (Queue *) malloc(sizeof(Queue));
	queue->first = 0; 
	queue->last = 0;
	queue->size = sizeofQueue;
	queue->array = (int *) malloc(sizeof(int) * (sizeofQueue + 1));
	return queue;
}

int enqueue(Queue * queue, int item) {
	int wasInserted = 0;
    if ((queue->last + 1) % (queue->size + 1) == queue->first) {
        printf("Fila cheia!\n");
        return wasInserted;
    }

	// the last item of the queue refers to the position of the next insertion
    queue->array[queue->last] = item;
	// walk trought the array roundly
    queue->last = (queue->last + 1) % (queue->size + 1);
	wasInserted = 1;
	return wasInserted;
}

int dequeue(Queue * queue) {
	int removed = 0x7fffffff;
    if (queue->first == queue->last) {
        printf("Fila vazia!\n");
        return removed; 
    }

	// the first item of the queue refers to the position of the next remotion
    removed = queue->array[queue->first];
	// walk trought the array roundly
    queue->first = (queue->first + 1) % (queue->size + 1);
	return removed;
}

void showItens(Queue * queue) {
    printf("[");
    for (int i = queue->first; i != queue->last; i = (i + 1) % (queue->size + 1)) 
        printf(" %d ", queue->array[i]);
    printf("]\n");
}

void freeQueue(Queue * queue) {
	free(queue->array);
}

int main() {
	Queue * queue = newQueue();
    for (int i = 0; i < 11; i++)
        enqueue(queue, i);

    showItens(queue);

    for (int i = 0; i < 11; i++)
		printf("%d\n", dequeue(queue));

    showItens(queue);

	for (int i = 1; i < 4; i++)
		enqueue(queue, i);

	showItens(queue);

	dequeue(queue);
	dequeue(queue);

	showItens(queue);

	printf("queue->first: %d\n", queue->first);
	printf("queue->last: %d\n", queue->last);
	freeQueue(queue);
}
