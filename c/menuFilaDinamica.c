#include "fila_dinamica/filaDinamica.h"

#include <stdio.h>

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
