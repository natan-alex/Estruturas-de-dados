#include "hashComLista.h"
#include "../lista_dinamica/listaDinamica.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

THash * newTHash(int tamanho) {
	THash * thash = (THash *) malloc(sizeof(THash));
    thash->tamTabela = tamanho;
    thash->tabelaHash = (Lista **) malloc(sizeof(Lista *) * (thash->tamTabela));
    for (int i = 0; i < (thash->tamTabela); i++) 
        thash->tabelaHash[i] = newLista();
    return thash;
}

int hash(THash * thash, int item) {
    return item % (thash->tamTabela);
}

bool inserirNoFimDaListaDaTabela(THash * thash, int item) {
    bool inseriuComSucesso = false;
    int pos = hash(thash, item);
    inseriuComSucesso = inserirNoFim(thash->tabelaHash[pos], item);
    return inseriuComSucesso;
}

bool inserirNoInicioDaListaDaTabela(THash * thash, int item) {
    bool inseriuComSucesso = false;
    int pos = hash(thash, item);
    inseriuComSucesso = inserirNoInicio(thash->tabelaHash[pos], item);
    return inseriuComSucesso;
}

bool inserirNumaPosDaListaDaTabela(THash * thash, int item, int pos) {
    bool inseriuComSucesso = false;
    int posNaHash = hash(thash, item);
    inseriuComSucesso = inserirNaPos(thash->tabelaHash[posNaHash], item, pos);
    return inseriuComSucesso;
}

int removerDoFimDaListaDaTabela(THash * thash, int pos) {
    int removido = INT_MIN;
    if (pos >= 0 && pos < (thash->tamTabela)) {
        removido = removerDoFim(thash->tabelaHash[pos]);
    } else {
        printf("Posicao na tabela invalida.\n");
    }
    return removido;
}

int removerDoInicioDaListaDaTabela(THash * thash, int pos) {
    int removido = INT_MIN;
    if (pos >= 0 && pos < (thash->tamTabela)) {
        removido = removerDoInicio(thash->tabelaHash[pos]);
    } else {
        printf("Posicao na tabela invalida.\n");
    }
    return removido;
}

int removerDaTabelaNaPos(THash * thash, int posNaHash, int posNaLista) {
    int removido = INT_MIN;
    if (posNaHash >= 0 && posNaHash < (thash->tamTabela)) {
        if (posNaLista >= 0 && posNaLista < (thash->tabelaHash[posNaHash]->qtd)) {
            removido = removerDaPos(thash->tabelaHash[posNaHash], posNaLista);
        } else {
            printf("Posicao de remocao na lista invalida.\n");
        }
    } else {
        printf("Posicao na tabela invalida.\n");
    }
    return removido;
}

bool pesquisarItemNaTabela(THash * thash, int item) {
    bool existeOItem = false;
    int posItem = hash(thash, item);
    existeOItem = pesquisarItemNaLista(thash->tabelaHash[posItem], item);
    return existeOItem;
}

void getPosicaoDeUmItem(THash * thash, int item) {
    printf("Pesquisando pelo item %d...\n", item);
    int posItemNaTabela = hash(thash, item);
	int posItemNaLista = getPosicaoDoItemNaLista(thash->tabelaHash[posItemNaTabela], item);
    if (posItemNaLista != -1) {
        printf("Item encontrado na posição %d da tabela e %d da lista.\n", posItemNaTabela, posItemNaLista);
    } else {
        printf("Item nao encontrado.\n");
    }
}

void mostrarItensTabela(THash * thash) {
	printf("Itens da tabela:\n");
    for (int i = 0; i < (thash->tamTabela); i++) {
		printf("Posição %d: ", i);
        mostrarItensDaLista(thash->tabelaHash[i]);
	}
    printf("\n");
}

void desalocarHash(THash * thash) {
	for (int i = 0; i < (thash->tamTabela); i++) {
		free(thash->tabelaHash[i]);
	}
	free(thash);
}
