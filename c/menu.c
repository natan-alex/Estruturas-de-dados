#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arvore_avl/menuAvl.h"
#include "fila_dinamica/menuFilaDinamica.h"
#include "lista_dinamica/menuListaDinamica.h"
#include "pilha_dinamica/menuPilhaDinamica.h"

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
