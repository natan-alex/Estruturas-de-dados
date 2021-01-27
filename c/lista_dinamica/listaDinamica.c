#include "listaDinamica.h"
#include "../common/celula.h"

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

Lista * newLista() {
    Lista * lista = (Lista *) malloc(sizeof(Lista));

    lista->primeiro = newCelula();
    lista->ultimo = lista->primeiro;
    lista->qtd = 0;

    return lista;
}

bool isVazia(Lista * lista) {
	return lista->primeiro == lista->ultimo;
}

bool inserirNoInicio(Lista * lista, int item) {
    bool deuCerto = false;
    Celula * c = newCelula2(item);
    if (isVazia(lista)) {
        lista->ultimo = c;
    }
    c->prox = lista->primeiro->prox;
    lista->primeiro->prox = c;
    c = NULL;
    deuCerto = true;
    lista->qtd++;
    return deuCerto;
}

bool inserirNoFim(Lista * lista, int item) {
    bool deuCerto = false;
    Celula * c = newCelula2(item);
    if (isVazia(lista)) {
        lista->primeiro->prox = c;
    }
    lista->ultimo->prox = c;
    lista->ultimo = c;
    c = NULL;
    deuCerto = true;
    lista->qtd++;
    return deuCerto;
}

bool inserirNaPos(Lista * lista, int item, int pos) {
    bool deuCerto = false;
    if (pos >= 0 && pos <= lista->qtd) {
        if (pos == 0) {
            deuCerto = inserirNoInicio(lista, item);
        } else if (pos == lista->qtd) {
            deuCerto = inserirNoFim(lista, item);
        } else {
            Celula * c = newCelula2(item);
            Celula * tmp = lista->primeiro->prox;
            for (int cont = 1; cont < pos; cont++) {
                tmp = tmp->prox;
            }
            c->prox = tmp->prox;
            tmp->prox = c;
            tmp = NULL;
            c = NULL;
			lista->qtd++;
        }
    } else {
        printf("Posição de inserção inválida.\n");
    }
    return deuCerto;
}

int removerDoInicio(Lista * lista) {
    int removido = 0x7fffffff;
    if (isVazia(lista)) {
        printf("Lista vazia!\n");
    } else {
        Celula * c = lista->primeiro;
        lista->primeiro = lista->primeiro->prox;
        free(c);
        removido = lista->primeiro->item;
        c = NULL;
        lista->qtd--;
    }
    return removido;
}

int removerDaPos(Lista * lista, int pos) {
    int removido = 0x7fffffff;
    if (isVazia(lista)) {
        printf("Lista vazia!\n");
    } else {
        if (pos >= 0 && pos < lista->qtd) {
            Celula * c = lista->primeiro;
            for (int cont = 0; cont < pos; cont++) {
                c = c->prox;
            }
            Celula * tmp = c->prox;
            c->prox = tmp->prox;
            removido = tmp->item;
            free(tmp);
            tmp = NULL;
            c = NULL;
            lista->qtd--;
        } else {
            printf("Posição de remoção inválida.\n");
        }
    }
    return removido;
}

int removerDoFim(Lista * lista) {
    int removido = 0x7fffffff;
    if (isVazia(lista)) {
        printf("Lista vazia!\n");
    } else {
        Celula * c = lista->primeiro;
        while (c->prox != lista->ultimo) {
            c = c->prox;
        }
        Celula * tmp = c->prox;
        c->prox = NULL;
        lista->ultimo = c;
        removido = tmp->item;
        free(tmp);
        tmp = NULL;
        c = NULL;
        lista->qtd--;
    }
    return removido;
}

bool pesquisarItemNaLista(Lista * lista, int item) {
	bool encontrado = false;
	for (Celula * tmp = lista->primeiro->prox; tmp != NULL && !encontrado; tmp = tmp->prox) {
		if (tmp->item == item) encontrado = true;
	}
	return encontrado;
}

int getPosicaoDoItemNaLista(Lista * lista, int item) {
	int pos = -1, cont = 0;
	for (Celula * tmp = lista->primeiro->prox; tmp != NULL && (pos == -1); tmp = tmp->prox) {
		if (tmp->item == item) pos = cont;
	}
	return pos;
}

void mostrarItensDaLista(Lista * lista) {
    if (lista->primeiro == lista->ultimo) {
        printf("Lista vazia!\n");
    } else {
        printf("[ ");
        for (Celula * c = lista->primeiro->prox; c != NULL; c = c->prox)
            printf("%d ", c->item);
        printf("]\n");
    }
}

void desalocarLista(Lista * lista) {
    Celula * c, * proxADesalocar;
    for (c = lista->primeiro; c != NULL; c = proxADesalocar) {
        proxADesalocar = c->prox;
        free(c);
    }
    proxADesalocar = NULL;
    c = NULL;
}
