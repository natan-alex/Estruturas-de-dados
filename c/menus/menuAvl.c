#include <stdio.h>
#include "menuAvl.h"
#include "../arvore_avl/avlTree.h"
#include "../common/sobreOpcoes.h"

void menuAvl() {
	AvlTree * avl = newAvl();
	int opcao, item;
	do {
		printf("\n");
		printf("\t\tMENU: ARVORE AVL\n");
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
		opcao = lerOpcao();
		opcao = tratarOpcao(opcao, 0, 9);
		printf("\n");
		switch(opcao) {
			case 0:
				desalocarArvoreDaMemoria(avl);
				printf("Programa encerrado.\n");
				break;
			case 1:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				inserirNaArvore(avl, item);
				break;
			case 2:
				printf("Item a ser removido: ");
				scanf("%d", &item);
				removerDaArvore(avl, item);
				break;
			case 3:
				printf("Item a ser procurado: ");
				scanf("%d", &item);
				pesquisarPorItemNaArvore(avl, item);
				break;
			case 4:
				printf("Item a ser procurado: ");
				scanf("%d", &item);
				pesquisarPorNoContendoItem(avl, item);
				break;
			case 5:
				mostrarTodasOrdens(avl);
				break;
			case 6:
				mostrarPreOrdem(avl);
				break;
			case 7:
				mostrarEmOrdem(avl);
				break;
			case 8:
				mostrarPosOrdem(avl);
				break;
			case 9:
				printf("Número de nós: %d\n", contarNosDaArvore(avl));
				break;
			default:
				break;
		}
	} while (opcao != 0);
}
