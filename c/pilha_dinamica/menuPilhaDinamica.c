#include <stdio.h>
#include "../common/sobreOpcoes.h"
#include "../pilha_dinamica/pilhaDinamica.h"

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
				if (item != 0x7fffffff) {
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
