#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

typedef struct Stack {
	int size;
	int control; // control the position of the insertions and remotions in the array
	int * array;
} Stack;

Stack * newStack();

Stack * newStack2(int sizeofStack);

int isFull(Stack * stack);

int isEmpty(Stack * stack);

void push(Stack * stack, int item);

int pop(Stack * stack);

void showItens(Stack * stack);

void freeStack(Stack * stack);

#endif

