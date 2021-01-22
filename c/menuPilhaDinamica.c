#include "pilha_dinamica/pilhaDinamica.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv) {
	Pilha * pilha = newPilha();
	for (int i = 1; i < 10; i++) {
		empilhar(pilha, i*4);
	}
	mostrarItensDaPilha(pilha);
	printf("%d\n", desempilhar(pilha));
	printf("%d\n", desempilhar(pilha));
	printf("%d\n", desempilhar(pilha));
	mostrarItensDaPilha(pilha);

    return 0;
}
