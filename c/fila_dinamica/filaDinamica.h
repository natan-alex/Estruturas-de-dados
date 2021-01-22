#ifndef FILA_DINAMICA_H
#define FILA_DINAMICA_H

#include "../common/celula.h"

typedef struct Queue {
    Celula * head;
    Celula * last;
    int nItems;
} Queue;

Queue * newQueue(); 

int isEmpty(Queue * q); 

void enqueue(Queue * q, int item); 

int dequeue(Queue * q); 

void showItens(Queue * q); 

void freeQueue(Queue * q); 

#endif
