#ifndef LISTADINAMICA_H
#define LISTADINAMICA_H

#include "../common/celula.h"

#include <stdbool.h>

typedef struct Lista {
    Celula * primeiro, * ultimo;
    int qtd;
} Lista;

Lista * newLista(); 

bool isVazia(Lista * lista); 

bool inserirNoInicio(Lista * lista, int item); 

bool inserirNoFim(Lista * lista, int item); 

bool inserirNaPos(Lista * lista, int item, int pos); 

int removerDoInicio(Lista * lista); 

int removerDaPos(Lista * lista, int pos); 

int removerDoFim(Lista * lista); 

bool pesquisarItemNaLista(Lista * lista, int item); 

int getPosicaoDoItemNaLista(Lista * lista, int item);

void mostrarItensDaLista(Lista * lista); 

void desalocarLista(Lista * lista); 

#endif
