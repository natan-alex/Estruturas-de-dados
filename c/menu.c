#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common/celula.h"
#include "lista_dinamica/listaDinamica.h"
#include "hash_com_lista/hashComLista.h"
#include "fila_dinamica/filaDinamica.h"
#include "arvore_avl/avlTree.h"
#include "pilha_dinamica/pilhaDinamica.h"

int lerOpcao() {
	int opcao;
	scanf("%d", &opcao);
	return opcao;
}

int tratarOpcao(int opcao, int limiteInferior, int limiteSuperior) {
	while (opcao < limiteInferior || opcao > limiteSuperior) {
		printf("Opção inválida, tente novamente.\n");
		printf("Nova opção: ");
		opcao = lerOpcao();
	}
	return opcao;
}

void realizarOperacaoDaLista(Lista * lista, char * operacao) {
    int num, pos;
    if (strcmp(operacao, "II") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        inserirNoInicio(lista, num);
    } else if (strcmp(operacao, "IF") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        inserirNoFim(lista, num);
    } else if (strcmp(operacao, "I*") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        printf("Posicao: ");
        scanf("%d", &pos);
        inserirNaPos(lista, num, pos);
    } else if (strcmp(operacao, "RI") == 0) {
        printf("Removido: %d\n", removerDoInicio(lista));
    } else if (strcmp(operacao, "RF") == 0) {
        printf("Removido: %d\n", removerDoFim(lista));
    } else if (strcmp(operacao, "R*") == 0) {
        printf("Posicao: ");
        scanf("%d", &pos);
        printf("Removido: %d\n", removerDaPos(lista, pos));
    }
    printf("Elementos da lista: ");
    mostrarItensDaLista(lista);
}

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

void menuListaDinamica() {
    Lista * lista = newLista();
    int op;
    do {
        printf("MENU: LISTA DINAMICA\n");
        printf("[1] -- inserir no inicio\n");
        printf("[2] -- inserir no fim\n");
        printf("[3] -- inserir na pos\n");
        printf("[4] -- remover do inicio\n");
        printf("[5] -- remover do fim\n");
        printf("[6] -- remover da pos\n");
        printf("[7] -- Mostrar itens\n");
        printf("[0] -- sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: 
                realizarOperacaoDaLista(lista, "II");
                break;
            case 2:
                realizarOperacaoDaLista(lista, "IF");
                break;
            case 3:
                realizarOperacaoDaLista(lista, "I*");
                break;
            case 4:
                realizarOperacaoDaLista(lista, "RI");
                break;
            case 5:
                realizarOperacaoDaLista(lista, "RF");
                break;
            case 6:
                realizarOperacaoDaLista(lista, "R*");
                break;
            case 7:
                printf("Elementos da lista: ");
                mostrarItensDaLista(lista);
                break;
            case 0:
                printf("Finalizado.\n");
                desalocarLista(lista);
                break;
            default: 
                printf("Operacao invalida.\n");
                break;
        }
    } while (op != 0);
}

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

void menuPilhaDinamica() {
	Pilha * pilha = newPilha();
	int opcao, item;
	do {
		printf("\n");
		printf("\t\tMENU: PILHA DINAMICA\n");
		printf("  [1] - empilhar um item\n");
		printf("  [2] - desempilhar um item\n");
		printf("  [3] - mostrar itens da pilha\n");
		printf("  [4] - tamanho atual da pilha\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		opcao = lerOpcao();
		opcao = tratarOpcao(opcao, 0, 4);
		printf("\n");
		switch(opcao) {
			case 0:
				printf("Programa encerrado.\n");
				break;
			case 1:
				printf("Item a ser inserido: ");
				scanf("%d", &item);
				empilhar(pilha, item);
				break;
			case 2:
				item = desempilhar(pilha);
				if (item != -9999) {
					printf("Item removido: %d\n", item);
				}
				break;
			case 3:
				mostrarItensDaPilha(pilha);
				break;
			case 4:
				printf("Tamanho: %d\n", getTamanhoDaPilha(pilha));
				break;
			default:
				break;
		}
	} while (opcao != 0);
}

int main(int argc, char ** argv) {
	if (argc < 2) {
		printf("Nenhum argumento passado ao programa.\n");
		printf("Argumentos possíveis: \n");
		printf(" * avl\n");
		printf(" * lista\n");
		printf(" * fila\n");
		printf(" * pilha\n");
	} else {
		if (strcmp(argv[1], "avl") == 0) {
			menuAvl();	
		} else if (strcmp(argv[1], "lista") == 0) {
			menuListaDinamica();
		} else if (strcmp(argv[1], "fila") == 0) {
			menuFilaDinamica();
		} else if (strcmp(argv[1], "pilha") == 0) {
			menuPilhaDinamica();
		}
	}

    return 0;
}
