#include "filaDinamica.h"
#include "../common/celula.h"

#include <stdio.h>
#include <stdlib.h>

Queue * newQueue() {
    Queue * q = (Queue *) malloc(sizeof(Queue));
    q->head = newCelula();
    q->last = q->head;
    q->nItems = 0;
    return q;
}

int isEmpty(Queue * q) {
    return (q->head == q->last);
}

void enqueue(Queue * q, int item) {
    Celula * tmp = newCelula();
    tmp->item = item;

    if (isEmpty(q))
        q->head->prox = tmp;

    q->last->prox = tmp;
    q->last = tmp;
    tmp = NULL;
    q->nItems++;
}

int dequeue(Queue * q) {
    if (isEmpty(q)) {
        printf("Fila vazia!\n");
        return -9999;
    }

    Celula * tmp = q->head;
    q->head = q->head->prox;
    int removido = q->head->item;
    free(tmp);
    tmp = NULL;

    q->nItems--;
    return removido;
}

void showItens(Queue * q) {
    Celula * c;
    printf("[");

    for (c = q->head->prox; c != NULL; c = c->prox)
        printf(" %d", c->item);

    printf(" ]\n");
    c = NULL;
}

void freeQueue(Queue * q) {
    Celula * c;
    Celula * nextToFree;
    for (c = q->head; c != NULL; c = nextToFree) {
        nextToFree = c->prox;
        free(c);
    }
    c = NULL;
    nextToFree = NULL;
}
