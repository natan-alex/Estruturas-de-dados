#include <stdio.h>
#include <stdlib.h>
#define TAM 10

int stack[TAM];
int n = 0;

int isFull() {
    return (n == TAM) ? 1 : 0;
}

int isEmpty() {
    return (n == 0) ? 1 : 0;
}

void push(int item) {
    if (isFull()) {
        printf("Pilha cheia!\n");
        return;
    }

    stack[n++] = item;
}

int pop() {
    if (isEmpty()) {
        printf("Pilha vazia!\n");
        return -1;
    }

    return stack[n--];
}

void showItens() {
    for (int i = n-1; i >= 0; i--) 
        printf("|\t%d\t|\n", stack[i]);
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    push(1);
    push(2);
    push(3);
    showItens();
    pop();
    showItens();
}
