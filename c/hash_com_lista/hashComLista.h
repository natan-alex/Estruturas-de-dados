#ifndef HASH_COM_LISTA_H
#define HASH_COM_LISTA_H

#include "../lista_dinamica/listaDinamica.h"
#include <stdbool.h>

typedef struct THash {
	int tamTabela;
	Lista ** tabelaHash;
} THash;

THash * newTHash(int tamanho);

int hash(THash * thash, int item);

bool inserirNoFimDaListaDaTabela(THash * thash, int item);

bool inserirNoInicioDaListaDaTabela(THash * thash, int item);

bool inserirNumaPosDaListaDaTabela(THash * thash, int item, int pos);

int removerDoFimDaListaDaTabela(THash * thash, int pos);

int removerDoInicioDaListaDaTabela(THash * thash, int pos);

int removerDaTabelaNaPos(THash * thash, int posNaHash, int posNaLista);

bool pesquisarItemNaTabela(THash * thash, int item);

void getPosicaoDeUmItem(THash * thash, int item);

void mostrarItensTabela(THash * thash);

void desalocarHash(THash * thash);

#endif
