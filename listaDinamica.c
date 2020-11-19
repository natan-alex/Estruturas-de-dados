#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Celula {
    int item;
    struct Celula * prox;
} Celula;

typedef struct ListaFlex {
    Celula * primeira;
    Celula * ultima;
} ListaFlex;

Celula * newCelula() {
    Celula * c = (Celula *) malloc(sizeof(Celula));

    c->item = 0;
    c->prox = NULL;
    return c;
}

Celula * newCelula2(int item, Celula * prox) {
    Celula * c = (Celula *) malloc(sizeof(Celula));

    c->item = item;
    c->prox = prox;
    return c;
}

ListaFlex * newListaFlex() {
    ListaFlex * lf = (ListaFlex *) malloc(sizeof(ListaFlex));
    lf->primeira = newCelula();
    lf->ultima = lf->primeira;
    return lf;
}

int isVazia(ListaFlex * lf) {
    return (lf->primeira == lf->ultima) ? 1 : 0;
}

int tamanhoLista(ListaFlex * lf) {
    int tam = 0;
    Celula * c;
    for (c = lf->primeira->prox; c != NULL; c = c->prox) 
        tam++;
    c = NULL;
    return tam;
}

void inserirInicio(ListaFlex * lf, int item) {
    Celula * c = newCelula2(item, NULL);
    if (isVazia(lf)) 
        lf->ultima = c;
    c->prox = lf->primeira->prox;
    lf->primeira->prox = c;
    c = NULL;
}

void inserirFim(ListaFlex * lf, int item) {
    Celula * c = newCelula2(item, NULL);
    if (isVazia(lf)) 
        lf->primeira->prox = c;
    lf->ultima->prox = c;
    lf->ultima = c;
    c = NULL;
}

void inserirPos(ListaFlex * lf, int item, int pos) {
    int tam = tamanhoLista(lf);
    if (pos < 0 || pos > tam) {
        printf("Posicao de insercao invalida.\n");
        return;
    } else if (pos == 0) {
        inserirInicio(lf, item);
        return;
    } else if (pos == tam) {
        inserirFim(lf, item);
        return;
    } else {
        int cont = 1;
        Celula * c;
        for (c = lf->primeira->prox; cont < pos; c = c->prox);
        Celula * tmp = newCelula2(item, c->prox);
        c->prox = tmp;
        c = NULL;
        tmp = NULL;
    }
}

int removerInicio(ListaFlex * lf) {
    Celula * c = lf->primeira;
    lf->primeira = lf->primeira->prox;
    free(c);
    c = NULL;
    return lf->primeira->item;
}

int removerFim(ListaFlex * lf) {
    Celula * c;
    for (c = lf->primeira->prox; c->prox != lf->ultima; c = c->prox);
    Celula * tmp = lf->ultima;
    lf->ultima = c;
    lf->ultima->prox = NULL;
    int removido = tmp->item;
    free(tmp);
    c = NULL;
    tmp = NULL;
    return removido;
}

int removerPos(ListaFlex * lf, int pos) {
    int tam = tamanhoLista(lf);
    int removido = -1;
    if (pos < 0 || pos > tam) {
        printf("Posicao de remocao invalida.\n");
    } else if (pos == 0) {
        removido = removerInicio(lf);
    } else if (pos == tam) {
        removido = removerFim(lf);
    } else {
        int cont = 1;
        Celula * c;
        for (c = lf->primeira->prox; cont < pos; c = c->prox);
        Celula * tmp = c->prox;
        removido = tmp->item;
        c->prox = tmp->prox;
        free(tmp);
        c = NULL;
        tmp = NULL;
    }
    return removido;
}

void mostrar(ListaFlex * lf) {
    printf("[");
    Celula * c;
    for (c = lf->primeira->prox; c != NULL; c = c->prox) 
        printf(" %d", c->item);
    printf(" ]\n");
    c = NULL;
}

void desalocarLista(ListaFlex * lf) {
    Celula * c, * proxADesalocar;
    for (c = lf->primeira; c != NULL; c = proxADesalocar) {
        proxADesalocar = c->prox;
        free(c);
    }
    proxADesalocar = NULL;
    c = NULL;
    lf = NULL;
}

void realizaOperacao(ListaFlex * lf, char * operacao) {
    int num, pos;
    if (strcmp(operacao, "II") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        inserirInicio(lf, num);
    } else if (strcmp(operacao, "IF") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        inserirFim(lf, num);
    } else if (strcmp(operacao, "I*") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        printf("Posicao: ");
        scanf("%d", &pos);
        inserirPos(lf, num, pos);
    } else if (strcmp(operacao, "RI") == 0) {
        printf("Removido: %d\n", removerInicio(lf));
    } else if (strcmp(operacao, "RF") == 0) {
        printf("Removido: %d\n", removerFim(lf));
    } else if (strcmp(operacao, "R*") == 0) {
        printf("Posicao: ");
        scanf("%d", &pos);
        printf("Removido: %d\n", removerPos(lf, pos));
    }
    printf("Elementos da lista: ");
    mostrar(lf);
}

int main(int argc, char * argv[]) {
    ListaFlex * lf = newListaFlex();
    int op;
    do {
        printf("MENU\n");
        printf("[1] -- inserirInicio()\n");
        printf("[2] -- inserirFim()\n");
        printf("[3] -- inserirPos()\n");
        printf("[4] -- removerInicio()\n");
        printf("[5] -- removerFim()\n");
        printf("[6] -- removerPos()\n");
        printf("[7] -- mostrar()\n");
        printf("[0] -- sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: 
                realizaOperacao(lf, "II");
                break;
            case 2:
                realizaOperacao(lf, "IF");
                break;
            case 3:
                realizaOperacao(lf, "I*");
                break;
            case 4:
                realizaOperacao(lf, "RI");
                break;
            case 5:
                realizaOperacao(lf, "RF");
                break;
            case 6:
                realizaOperacao(lf, "R*");
                break;
            case 7:
                printf("Elementos da lista: ");
                mostrar(lf);
                break;
            case 0:
                printf("Finalizado.\n");
                desalocarLista(lf);
                break;
            default: 
                printf("Operacao invalida.\n");
                break;
        }
    } while (op != 0);
}
