#include <stdio.h>
#include "menuFilaCircular.h"
#include "filaCircular.h"

void menuFilaCircular() {
	int opcao, item, tamFila;
	printf("Tamanho da fila: ");
	scanf("%d", &tamFila);
	Queue * queue = newQueue2(tamFila);
	do {
		printf("\n");
		printf("\t\tMENU: FILA CIRCULAR\n");
		printf("  [1] - enfileirar um item\n");
		printf("  [2] - desenfileirar um item\n");
		printf("  [3] - mostrar itens da queue\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		scanf("%d", &opcao);
		printf("\n");
		switch(opcao) {
			case 0:
				freeQueue(queue);
				printf("Programa encerrado.\n");
				break;
			case 1:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				enqueue(queue, item);
				break;
			case 2:
				item = dequeue(queue);
				if (item != 0x7fffffff) {
					printf("Item removido: %d\n", item);
				}
				break;
			case 3:
				showItens(queue);
				break;
			default:
				printf("Opção inválida.\n");
				break;
		}
	} while (opcao != 0);
}
