#include "hashComLista.h"
#include "../lista_dinamica/listaDinamica.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int tamTabela;

Lista ** newHash(int tamanho) {
    tamTabela = tamanho;
    Lista ** tabelaHash = (Lista **) malloc(sizeof(Lista *) * tamTabela);
    for (int i = 0; i < tamTabela; i++) 
        tabelaHash[i] = newLista();
    return tabelaHash;
}

int hash(int item) {
    return item % tamTabela;
}

bool inserirNoFimDaListaDaTabela(Lista ** thash, int item) {
    bool inseriuComSucesso = false;
    int pos = hash(item);
    inseriuComSucesso = inserirNoFim(thash[pos], item);
    return inseriuComSucesso;
}

bool inserirNoInicioDaListaDaTabela(Lista ** thash, int item) {
    bool inseriuComSucesso = false;
    int pos = hash(item);
    inseriuComSucesso = inserirNoInicio(thash[pos], item);
    return inseriuComSucesso;
}

bool inserirNumaPosDaListaDaTabela(Lista ** thash, int item, int pos) {
    bool inseriuComSucesso = false;
    int posNaHash = hash(item);
    inseriuComSucesso = inserirNaPos(thash[posNaHash], item, pos);
    return inseriuComSucesso;
}

int removerDoFimDaListaDaTabela(Lista ** thash, int pos) {
    int removido = INT_MIN;
    if (pos >= 0 && pos < tamTabela) {
        removido = removerDoFim(thash[pos]);
    } else {
        printf("Posicao na tabela invalida.\n");
    }
    return removido;
}

int removerDoInicioDaListaDaTabela(Lista ** thash, int pos) {
    int removido = INT_MIN;
    if (pos >= 0 && pos < tamTabela) {
        removido = removerDoInicio(thash[pos]);
    } else {
        printf("Posicao na tabela invalida.\n");
    }
    return removido;
}

int removerDaTabelaNaPos(Lista ** thash, int posNaHash, int posNaLista) {
    int removido = INT_MIN;
    if (posNaHash >= 0 && posNaHash < tamTabela) {
        if (posNaLista >= 0 && posNaLista < thash[posNaHash]->qtd) {
            removido = removerDaPos(thash[posNaHash], posNaLista);
        } else {
            printf("Posicao de remocao na lista invalida.\n");
        }
    } else {
        printf("Posicao na tabela invalida.\n");
    }
    return removido;
}

bool pesquisarItemNaTabela(Lista ** thash, int item) {
    bool existeOItem = false;
    int posItem = hash(item);
    existeOItem = pesquisarItemNaLista(thash[posItem], item);
    return existeOItem;
}

void getPosicaoDeUmItem(Lista ** thash, int item) {
    printf("Pesquisando pelo item %d...\n", item);
    int posItemNaTabela = hash(item);
	int posItemNaLista = getPosicaoDoItemNaLista(thash[posItemNaTabela], item);
    if (posItemNaLista != -1) {
        printf("Item encontrado na posição %d da tabela e %d da lista.\n", posItemNaTabela, posItemNaLista);
    } else {
        printf("Item nao encontrado.\n");
    }
}

void mostrarItensTabela(Lista ** thash) {
	printf("Itens da tabela:\n");
    for (int i = 0; i < tamTabela; i++) {
		printf("Posição %d: ", i);
        mostrarItensDaLista(thash[i]);
	}
    printf("\n");
}
