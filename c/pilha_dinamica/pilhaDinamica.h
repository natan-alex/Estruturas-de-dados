#include "../common/celula.h"

#ifndef PILHA_DINAMICA_H
#define PILHA_DINAMICA_H

typedef struct Pilha {
	Celula * topo;
} Pilha;

Pilha * newPilha();

int getTamanhoDaPilha(Pilha * pilha);

int empilhar(Pilha * pilha, int item);

int desempilhar(Pilha * pilha);

void mostrarItensDaPilha(Pilha * pilha);

#endif
