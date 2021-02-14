#include <stdio.h>
#include "menuBinaria.h"
#include "binarySearchTree.h"

void menuBinaria() {
	BST * binaria = newBST();
	int opcao, item;
	do {
		printf("\n");
		printf("\t\tMENU: ARVORE BINARIA\n");
		printf("  [1] - inserir item na árvore\n");
		printf("  [2] - remover item da árvore\n");
		printf("  [3] - checar se existe item na árvore\n");
		printf("  [4] - pesquisar informações do nó que contém determinado item\n");
		printf("  [5] - mostrar árvore em todas as ordens\n");
		printf("  [6] - mostrar árvore na pré-ordem\n");
		printf("  [7] - mostrar árvore em-ordem\n");
		printf("  [8] - mostrar árvore na pós-ordem\n");
		printf("  [9] - mostrar número de nós da árvore\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		scanf("%d", &opcao);
		printf("\n");
		switch(opcao) {
			case 0:
				desalocarArvoreBinariaDaMemoria(binaria);
				printf("Programa encerrado.\n");
				break;
			case 1:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				if (inserirNaArvoreBinaria(binaria, item)) {
					printf("Item inserido com sucesso.\n");
				} else { 
					printf("Falha ao inserir o item.\n");
				}
				break;
			case 2:
				printf("Item a ser removido: ");
				scanf("%d", &item);
				if (removerDaArvoreBinaria(binaria, item)) {
					printf("Item removido com sucesso.\n");
				} else { 
					printf("Falha ao remover o item.\n");
				}
				break;
			case 3:
				printf("Item a ser procurado: ");
				scanf("%d", &item);
				if (pesquisarPorItemNaArvoreBinaria(binaria, item)) {
					printf("Item encontrado na árvore.\n");
				} else {
					printf("Item não encontrado.\n");
				}
				break;
			case 4:
				printf("Item a ser procurado: ");
				scanf("%d", &item);
				pesquisarPorNoContendoItemNaBinaria(binaria, item);
				break;
			case 5:
				mostrarTodasOrdensBinaria(binaria);
				break;
			case 6:
				mostrarPreOrdemBinaria(binaria);
				break;
			case 7:
				mostrarEmOrdemBinaria(binaria);
				break;
			case 8:
				mostrarPosOrdemBinaria(binaria);
				break;
			case 9:
				printf("Número de nós: %d\n", contarNosDaArvoreBinaria(binaria));
				break;
			default:
				printf("Opção inválida.\n");
				break;
		}
	} while (opcao != 0);
}
