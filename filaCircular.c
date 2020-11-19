#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// the maximum size of the queue
#define TAM 5
// make easy to do the operations
#define REALSIZE (TAM+1)

int first = 0;
int last = 0;

int array[REALSIZE];

void enqueue(int item) {
    if ((last + 1) % REALSIZE == first) {
        printf("Fila cheia!\n");
        return;
    }

    array[last] = item;
    last = (last + 1) % REALSIZE;
}

int dequeue() {
    if (first == last) {
        printf("Fila vazia!\n");
        return -1;
    }

    int removido = array[first];
    first = (first + 1) % REALSIZE;
}

void showItens() {
    printf("[");
    for (int i = first; i != last; ++i) 
        printf(" %d ", array[i]);
    printf("]\n");
}

int main() {
    for (int i = 0; i < 5; i++)
        enqueue(i);
    printf("%d\n", dequeue());
    showItens();
}
