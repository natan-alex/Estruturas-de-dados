#include <stdio.h>

#include "hashComLista.h"

void menuHashComLista() {
	int tamanho;
	printf("Tamanho da tabela hash: ");
	scanf("%d", &tamanho);
	THash * thash = newTHash(tamanho);	
	int opcao, item, pos, posNaLista;
	do {
		printf("\n");
		printf("\t\tMENU: HASH COM LISTA\n");
		printf("  [1] - inserir um item no fim de uma lista da tabela\n");
		printf("  [2] - inserir um item no início de uma lista da tabela\n");
		printf("  [3] - inserir um item numa posição de uma lista da tabela\n");
		printf("  [4] - remover o item do fim da lista da tabela\n");
		printf("  [5] - remover o item do início de uma lista da tabela\n");
		printf("  [6] - remover um item de uma posição de uma lista da tabela\n");
		printf("  [7] - pesquisar por um item numa lista da tabela\n");
		printf("  [8] - obter a posição de um item\n");
		printf("  [9] - mostrar itens da tabela\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		scanf("%d", &opcao);
		printf("\n");
		switch(opcao) {
			case 0:
				desalocarHash(thash);
				printf("Programa encerrado.\n");
				break;
			case 1:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				if (inserirNoFimDaListaDaTabela(thash, item)) {
					printf("Item inserido com sucesso.\n");
				} else { 
					printf("Falha ao inserir o item.\n");
				}
				break;
			case 2:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				if (inserirNoInicioDaListaDaTabela(thash, item)) {
					printf("Item inserido com sucesso.\n");
				} else { 
					printf("Falha ao inserir o item.\n");
				}
				break;
			case 3:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				printf("Posição de inserção: ");
				scanf("%d", &pos);
				if (inserirNumaPosDaListaDaTabela(thash, item, pos)) {
					printf("Item inserido com sucesso.\n");
				} else { 
					printf("Falha ao inserir o item.\n");
				}
				break;
			case 4:
				printf("Posição, na tabela, do item a ser removido: ");
				scanf("%d", &item);
				if (removerDoFimDaListaDaTabela(thash, item) != 0x7fffffff) {
					printf("Item removido com sucesso.\n");
				} else { 
					printf("Falha ao remover o item.\n");
				}
				break;
			case 5:
				printf("Posição, na tabela, do item a ser removido: ");
				scanf("%d", &item);
				if (removerDoInicioDaListaDaTabela(thash, item) != 0x7fffffff) {
					printf("Item removido com sucesso.\n");
				} else { 
					printf("Falha ao remover o item.\n");
				}
				break;
			case 6:
				printf("Posição, na tabela, do item a ser removido:");
				scanf("%d", &pos);
				printf("Posição de remoção na lista: ");
				scanf("%d", &posNaLista);
				if (removerDaTabelaNaPos(thash, pos, posNaLista) != 0x7fffffff) {
					printf("Item removido com sucesso.\n");
				} else { 
					printf("Falha ao remover o item.\n");
				}
				break;
			case 7:
				printf("Item a ser procurado: ");
				scanf("%d", &item);
				if (pesquisarItemNaTabela(thash, item)) {
					printf("Item encontrado!\n");
				} else {
					printf("Item não encontrado na tabela.\n");
				}
				break;
			case 8:
				printf("Item a ser procurado: ");
				scanf("%d", &item);
				getPosicaoDeUmItem(thash, item);
				break;
			case 9:
				mostrarItensTabela(thash);
				break;
			default:
				printf("Opção inválida.\n");
				break;
		}
	} while (opcao != 0);
}
