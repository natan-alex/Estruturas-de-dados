#include <stdio.h>
#include "menuPilhaEstatica.h"
#include "pilhaEstatica.h"

void menuPilhaEstatica() {
	int opcao, item, tamPilha;
	printf("Tamanho da pilha: ");
	scanf("%d", &tamPilha);
	Stack * stack = newStack2(tamPilha);
	do {
		printf("\n");
		printf("\t\tMENU: PILHA ESTATICA\n");
		printf("  [1] - empilhar um item\n");
		printf("  [2] - desempilhar um item\n");
		printf("  [3] - mostrar itens da stack\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		scanf("%d", &opcao);
		printf("\n");
		switch(opcao) {
			case 0:
				freeStack(stack);
				printf("Programa encerrado.\n");
				break;
			case 1:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				push(stack, item);
				break;
			case 2:
				item = pop(stack);
				if (item != 0x7fffffff) {
					printf("Item removido: %d\n", item);
				}
				break;
			case 3:
				showItens(stack);
				break;
			default:
				printf("Opção inválida.\n");
				break;
		}
	} while (opcao != 0);
}
