#ifndef HASH_COM_LISTA_H
#define HASH_COM_LISTA_H

#include "../lista_dinamica/listaDinamica.h"
#include <stdbool.h>

extern int tamTabela;

Lista ** newHash(); 

Lista ** newHash2(int tamanho); 

int hash(int item); 

bool inserirNaTabela(Lista ** thash, int item); 

int removerDaTabela(Lista ** thash, int pos); 

int removerDaTabelaNaPos(Lista ** thash, int posNaHash, int posNaLista); 

bool pesquisarItemNaTabela(Lista ** thash, int item); 

int getPosicaoDeUmItem(Lista ** thash, int item); 

void mostrarItensTabela(Lista ** thash); 

#endif
