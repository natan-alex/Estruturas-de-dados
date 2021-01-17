#include <stdio.h>
#include <stdlib.h>

typedef struct Cell {
    int item;
    struct Cell * prox;
} Cell;

typedef struct Queue {
    Cell * head;
    Cell * last;
    int nItems;
} Queue;

Cell * newCell() {
    Cell * c = (Cell *) malloc(sizeof(Cell));
    c->item = 0;
    c->prox = NULL;
    return c;
}

Queue * newQueue() {
    Queue * q = (Queue *) malloc(sizeof(Queue));
    q->head = newCell();
    q->last = q->head;
    q->nItems = 0;
    return q;
}

int isEmpty(Queue * q) {
    return (q->head == q->last);
}

void enqueue(Queue * q, int item) {
    Cell * tmp = newCell();
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
        return -1;
    }

    Cell * tmp = q->head;
    q->head = q->head->prox;
    int removido = q->head->item;
    free(tmp);
    tmp = NULL;

    q->nItems--;
    return removido;
}

void showItens(Queue * q) {
    Cell * c;
    printf("[");

    for (c = q->head->prox; c != NULL; c = c->prox)
        printf(" %d", c->item);

    printf(" ]\n");
    c = NULL;
}

void freeQueue(Queue * q) {
    Cell * c;
    Cell * nextToFree;
    for (c = q->head; c != NULL; c = nextToFree) {
        nextToFree = c->prox;
        free(c);
    }
    c = NULL;
    nextToFree = NULL;
}

int main() {
    Queue * q = newQueue();

    enqueue(q, 10);
    enqueue(q, 5);
    enqueue(q, 1);
    enqueue(q, 3);
    showItens(q);
    printf("Removido: %d\n", dequeue(q));
    showItens(q);
    printf("Removido: %d\n", dequeue(q));
    showItens(q);

    freeQueue(q);
}
