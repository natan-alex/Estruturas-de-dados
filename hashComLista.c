/**************************************************
**                 Hash com Lista                **
**                dinamica simples               **
**************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Celula {
    struct Celula * prox;
    int item;
} Celula;

typedef struct lista {
    Celula * primeiro, * ultimo;
    int qtd;
} Lista;

Celula * newCelula() {
    Celula * celula = (Celula *) malloc(sizeof(Celula));

    celula->prox = NULL;
    celula->item = 0;

    return celula;
}

Celula * newCelula2(int item) {
    Celula * celula = (Celula *) malloc(sizeof(Celula));

    celula->prox = NULL;
    celula->item = item;

    return celula;
}

Celula * newCelula3(Celula * prox, int item) {
    Celula * celula = (Celula *) malloc(sizeof(Celula));

    celula->prox = prox;
    celula->item = item;

    return celula;
}

Lista * newLista() {
    Lista * lista = (Lista *) malloc(sizeof(Lista));

    lista->primeiro = newCelula();
    lista->ultimo = lista->primeiro;
    lista->qtd = 0;

    return lista;
}

bool inserirNoFim(Lista * lista, int item) {
    bool inseriuComSucesso = false;
    Celula * c = newCelula2(item);
    // lista vazia
    if (lista->primeiro == lista->ultimo) 
        lista->primeiro->prox = c;
    
    lista->ultimo->prox = c;
    lista->ultimo = c;
    lista->qtd++;
    inseriuComSucesso = true;
    c = NULL;
    return inseriuComSucesso;
}

bool inserirNoInicio(Lista * lista, int item) {
    bool inseriuComSucesso = false;
    Celula * c = newCelula2(item);
    // lista vazia
    if (lista->primeiro == lista->ultimo) 
        lista->ultimo = c;
    
    c->prox = lista->primeiro->prox;
    lista->primeiro->prox = c;
    lista->qtd++;
    inseriuComSucesso = true;
    c = NULL;
    return inseriuComSucesso;
}

bool inserirNaPos(Lista * lista, int item, int pos) {
    bool inseriuComSucesso = false;
    if (pos < 0 || pos > lista->qtd) {
        printf("Posicao de insercao invalida.\n");
    } else {
        Celula * c = newCelula2(item);
        // inserir
        if (pos == 0) {
            inseriuComSucesso = inserirNoInicio(lista, item);
        } else if (pos == lista->qtd) {
            inseriuComSucesso = inserirNoFim(lista, item);
        } else {
            Celula * tmp = lista->primeiro->prox;
            for (int i = 0; i < pos-1; i++) 
                tmp = tmp->prox;    
            c->prox = tmp->prox;
            tmp->prox = c;
            tmp = NULL;
            inseriuComSucesso = true;
        }
        c = NULL;
        lista->qtd++;
    }
    return inseriuComSucesso;
}

int removerDoInicio(Lista * lista) {
    int removido = -9999;
    if (lista->primeiro == lista->ultimo) {
        printf("Lista vazia!\n");
    } else {
        Celula * tmp = lista->primeiro->prox;
        lista->primeiro->prox = lista->primeiro->prox->prox;    
        removido = tmp->item;
        printf("removido: %d\n", removido);
        tmp->prox = NULL;
        free(tmp);
        tmp = NULL;
        lista->qtd--;
    }
    return removido;
}

int removerDoFim(Lista * lista) {
    int removido = -9999;
    if (lista->primeiro == lista->ultimo) {
        printf("Lista vazia!\n");
    } else {
        Celula * tmp;
        for (tmp = lista->primeiro; tmp->prox != lista->ultimo; tmp = tmp->prox); 
        removido = tmp->prox->item;
        lista->ultimo = tmp;
        lista->ultimo->prox = NULL;
        free(tmp->prox);
        tmp = NULL;
        lista->qtd--;
    }
    return removido;
}

int removerDaPos(Lista * lista, int pos) {
    int removido = -9999;
    if (pos < 0 || pos >= lista->qtd) {
        printf("Posicao de remocao invalida.\n");
    } else if (pos == 0) {
        removido = removerDoInicio(lista);
        lista->qtd--;
    } else if (pos == lista->qtd - 1) {
        removido = removerDoFim(lista);
        lista->qtd--;
    } else {
        int cont = 1;
        Celula * c;
        for (c = lista->primeiro->prox; cont < pos; c = c->prox, cont++);
        Celula * tmp = c->prox;
        removido = tmp->item;
        c->prox = tmp->prox;
        tmp->prox = NULL;
        free(tmp);
        c = NULL;
        tmp = NULL;
        lista->qtd--;
    }
    return removido;
}

bool pesquisar(Lista * lista, int item) {
    bool encontrado = false;
    for (Celula * c = lista->primeiro->prox; c != NULL && !encontrado; c = c->prox)
        if (c->item == item) 
            encontrado = true;
    return encontrado;
}

void mostrarItens(Lista * lista) {
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

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int tamHash = 10;

Lista ** newHash() {
    Lista ** tabelaHash = (Lista **) malloc(sizeof(Lista *) * tamHash);
    for (int i = 0; i < tamHash; i++) 
        tabelaHash[i] = newLista();
    return tabelaHash;
}

Lista ** newHash2(int tamanho) {
    tamHash = tamanho;
    Lista ** tabelaHash = (Lista **) malloc(sizeof(Lista *) * tamHash);
    for (int i = 0; i < tamHash; i++) 
        tabelaHash[i] = newLista();
    return tabelaHash;
}

int hash(int item) {
    return item % tamHash;
}

bool inserirNaTHash(Lista ** thash, int item) {
    bool inseriuComSucesso = false;
    int pos = hash(item);
    inseriuComSucesso = inserirNoFim(thash[pos], item);
    return inseriuComSucesso;
}

int removerDaTHash(Lista ** thash, int pos) {
    int removido = -9999;
    if (pos >= 0 && pos < tamHash) {
        removido = removerDoFim(thash[pos]);
    } else {
        printf("Posicao na tabela invalida.\n");
    }
    return removido;
}

int removerDaTHashNaPos(Lista ** thash, int posNaHash, int posNaLista) {
    int removido = -9999;
    if (posNaHash >= 0 && posNaHash < tamHash) {
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

bool pesquisarItemNaTHash(Lista ** thash, int item) {
    bool existeOItem = false;
    int posItem = hash(item);
    existeOItem = pesquisar(thash[posItem], item);
    return existeOItem;
}

void pesquisarItemNaTHash2(Lista ** thash, int item) {
    printf("Pesquisando pelo item %d...\n", item);
    bool existeOItem = false;
    int posItem = hash(item);
    existeOItem = pesquisar(thash[posItem], item);
    if (existeOItem) {
        printf("Item encontrado.\n");
    } else {
        printf("Item nao encontrado.\n");
    }
}

void mostrarItensTHash(Lista ** thash) {
    for (int i = 0; i < tamHash; i++) 
        mostrarItens(thash[i]);
    printf("\n");
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

int main(int argc, char ** argv) {
    Lista ** thash = newHash2(5);
    inserirNaTHash(thash, 10);
    inserirNaTHash(thash, 20);
    inserirNaTHash(thash, 21);
    inserirNaTHash(thash, 31);
    inserirNaTHash(thash, 51);
    inserirNaTHash(thash, 22);
    inserirNaTHash(thash, 13);
    inserirNaTHash(thash, 44);
    mostrarItensTHash(thash);
    removerDaTHash(thash, 0);
    mostrarItensTHash(thash);
    removerDaTHashNaPos(thash, 1, 1);
    mostrarItensTHash(thash);
    pesquisarItemNaTHash2(thash, 31);
    return 0;
}
