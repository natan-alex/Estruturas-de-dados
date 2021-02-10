#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int size;
	int control; // control the position of the insertions and remotions in the array
	int * array;
} Stack;

Stack * newStack() {
	Stack * stack = (Stack *) malloc(sizeof(Stack));
	stack->size = 10; // 10 is the default size of the stack
	stack->control = 0;
	stack->array = (int *) malloc(sizeof(int) * 10);
	return stack;
}

Stack * newStack2(int sizeofStack) {
	Stack * stack = (Stack *) malloc(sizeof(Stack));
	stack->size = sizeofStack;
	stack->control = 0;
	stack->array = (int *) malloc(sizeof(int) * sizeofStack);
	return stack;
}

int isFull(Stack * stack) {
    return (stack->control == stack->size) ? 1 : 0;
}

int isEmpty(Stack * stack) {
    return (stack->control == 0) ? 1 : 0;
}

void push(Stack * stack, int item) {
    if (isFull(stack)) {
        printf("Pilha cheia!\n");
        return;
    }

    stack->array[stack->control++] = item;
}

int pop(Stack * stack) {
	int removed = 0x7fffffff;
    if (isEmpty(stack)) {
        printf("Pilha vazia!\n");
        return removed;
    }

    removed = stack->array[stack->control--];
	return removed;
}

void showItens(Stack * stack) {
    for (int i = stack->control - 1; i >= 0; i--) 
        printf("|\t%d\t|\n", stack->array[i]);
    printf("\n");
}

void freeStack(Stack * stack) {
	free(stack->array);
}

int main() {
	Stack * stack = newStack();
	for (int i = 1; i < 11; i++)
		push(stack, i*3);
	showItens(stack);
	for (int i = 0; i < 12; i++)
		printf("%d\n", pop(stack));
	showItens(stack);
	freeStack(stack);
}
