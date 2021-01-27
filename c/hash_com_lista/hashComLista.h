#ifndef HASH_COM_LISTA_H
#define HASH_COM_LISTA_H

#include "../lista_dinamica/listaDinamica.h"
#include <stdbool.h>

extern int tamTabela;

Lista ** newHash(); 

Lista ** newHash2(int tamanho); 

int hash(int item); 

bool pesquisarItemNaTabela(Lista ** thash, int item); 

void getPosicaoDeUmItem(Lista ** thash, int item); 

void mostrarItensTabela(Lista ** thash); 

bool inserirNoFimDaListaDaTabela(Lista ** thash, int Item); 

bool inserirNoInicioDaListaDaTabela(Lista ** thash, int item); 

bool inserirNumaPosDaListaDaTabela(Lista ** thash, int item, int pos); 

int removerDoFimDaListaDaTabela(Lista ** thash, int pos); 

int removerDoInicioDaListaDaTabela(Lista ** thash, int pos); 

int removerDaTabelaNaPos(Lista ** thash, int posNaHash, int posNaLista); 

#endif
