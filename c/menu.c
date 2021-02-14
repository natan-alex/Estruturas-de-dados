#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arvore_binaria/menuBinaria.h"
#include "arvore_avl/menuAvl.h"
#include "fila_dinamica/menuFilaDinamica.h"
#include "lista_dinamica/menuListaDinamica.h"
#include "pilha_dinamica/menuPilhaDinamica.h"

int main(int argc, char ** argv) {
	if (argc < 2) {
		printf("Nenhum argumento passado ao programa.\n");
		printf("Argumentos possíveis: \n");
		printf(" * arvore_avl\n");
		printf(" * arvore_binaria\n");
		printf(" * lista_dinamica\n");
		printf(" * fila_dinamica\n");
		printf(" * pilha_dinamica\n");
	} else {
		if (strcmp(argv[1], "arvore_avl") == 0) {
			menuAvl();	
		} else if (strcmp(argv[1], "arvore_binaria") == 0) {
			menuBinaria();
		} else if (strcmp(argv[1], "lista_dinamica") == 0) {
			menuListaDinamica();
		} else if (strcmp(argv[1], "fila_dinamica") == 0) {
			menuFilaDinamica();
		} else if (strcmp(argv[1], "pilha_dinamica") == 0) {
			menuPilhaDinamica();
		} else {
			printf("Argumento inválido\n");
		}
	}

    return 0;
}
