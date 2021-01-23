#include <stdio.h>
#include "menuFilaDinamica.h"
#include "../fila_dinamica/filaDinamica.h"
#include "../common/sobreOpcoes.h"

void menuFilaDinamica() {
	Queue * fila = newQueue();
	int opcao, item;
	do {
		printf("\n");
		printf("\t\tMENU: FILA DINAMICA\n");
		printf("  [1] - enfileirar um item\n");
		printf("  [2] - desenfileirar um item\n");
		printf("  [3] - mostrar itens da fila\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		opcao = lerOpcao();
		opcao = tratarOpcao(opcao, 0, 3);
		printf("\n");
		switch(opcao) {
			case 0:
				freeQueue(fila);
				printf("Programa encerrado.\n");
				break;
			case 1:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				enqueue(fila, item);
				break;
			case 2:
				item = dequeue(fila);
				if (item != -9999) {
					printf("Item removido: %d\n", item);
				}
				break;
			case 3:
				showItens(fila);
				break;
			default:
				break;
		}
	} while (opcao != 0);
}
