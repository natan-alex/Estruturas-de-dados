#include "pilhaDinamica.h"
#include "../common/celula.h"

#include <stdio.h>
#include <stdlib.h>

Pilha * newPilha() {
	Pilha * pilha = (Pilha *) malloc(sizeof(Pilha));
	pilha->topo = newCelula();
	return pilha;
}

int getTamanhoDaPilha(Pilha * pilha) {
	int tam = 0;
	for (Celula * tmp = pilha->topo; tmp != NULL; tmp = tmp->prox, tam++);
	return tam;
}

int empilhar(Pilha * pilha, int item) {
	pilha->topo = newCelula3(pilha->topo, item);
	return 1;
}

int desempilhar(Pilha * pilha) {
	int removido = -9999;
	if (pilha->topo == NULL) {
		printf("Erro ao desempilhar: pilha vazia.\n");
	} else {
		Celula * tmp = pilha->topo;
		pilha->topo = tmp->prox;
		removido = tmp->item;
		free(tmp);
	}
	return removido;
}

void mostrarItensDaPilha(Pilha * pilha) {
	for (Celula * tmp = pilha->topo; tmp != NULL; tmp = tmp->prox) {
		printf("\t|\t%d\t|\n", tmp->item);
	}
}
