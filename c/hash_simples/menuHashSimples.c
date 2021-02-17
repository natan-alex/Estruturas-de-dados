#include <stdio.h>

#include "menuHashSimples.h"
#include "hash.h"

void menuHashSimples() {
	int tamTabela, tamReserva;
	printf("Tamanho da tabela hash: ");
	scanf("%d", &tamTabela);
	printf("Tamanho da área de reserva da tabela: ");
	scanf("%d", &tamReserva);
	Hash * thash = newHash(tamTabela, tamReserva);
	int opcao, item, pos;
	do {
		printf("\n");
		printf("\t\tMENU: HASH SIMPLES\n");
		printf("  [1] - inserir um item na tabela\n");
		printf("  [2] - remover um item da tabela\n");
		printf("  [3] - remover um item de uma posição específica\n");
		printf("  [4] - mostrar itens da tabela\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		scanf("%d", &opcao);
		printf("\n");
		switch(opcao) {
			case 0:
				desalocarTabela(thash);
				printf("Programa encerrado.\n");
				break;
			case 1:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				pos = inserir(thash, item);
				if (pos != -1) {
					printf("Item inserido na posição %d da tabela.\n", pos);
				} else { 
					printf("Falha ao inserir o item.\n");
				}
				break;
			case 2:
				printf("Item a ser removido: ");
				scanf("%d", &item);
				pos = removerItem(thash, item); 
				if (pos != -1) {
					printf("Item removido da posição %d da tabela.\n", pos);
				} else { 
					printf("Falha ao remover o item.\n");
				}
				break;
			case 3:
				printf("Posição, na tabela, do item a ser removido: ");
				scanf("%d", &pos);
				item = removerPos(thash, pos);
				if (item != 0x7fffffff) {
					printf("Item removido: %d.\n", item);
				} else { 
					printf("Falha ao remover da posição %d.\n", pos);
				}
				break;
			case 4:
				mostrar(thash);
				break;
			default:
				printf("Opção inválida.\n");
				break;
		}
	} while (opcao != 0);
}
