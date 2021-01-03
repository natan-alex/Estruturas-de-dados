#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Celula {
    struct Celula * prox;
    int item;
} Celula;

typedef struct Lista {
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
        }
        lista->qtd++;
    } else {
        printf("Posição de inserção inválida.\n");
    }
    return deuCerto;
}

int removerDoInicio(Lista * lista) {
    int removido = -9999;
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
    int removido = -9999;
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
    int removido = -9999;
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

void realizaOperacao(Lista * lista, char * operacao) {
    int num, pos;
    if (strcmp(operacao, "II") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        inserirNoInicio(lista, num);
    } else if (strcmp(operacao, "IF") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        inserirNoFim(lista, num);
    } else if (strcmp(operacao, "I*") == 0) {
        printf("Numero: ");
        scanf("%d", &num);
        printf("Posicao: ");
        scanf("%d", &pos);
        inserirNaPos(lista, num, pos);
    } else if (strcmp(operacao, "RI") == 0) {
        printf("Removido: %d\n", removerDoInicio(lista));
    } else if (strcmp(operacao, "RF") == 0) {
        printf("Removido: %d\n", removerDoFim(lista));
    } else if (strcmp(operacao, "R*") == 0) {
        printf("Posicao: ");
        scanf("%d", &pos);
        printf("Removido: %d\n", removerDaPos(lista, pos));
    }
    printf("Elementos da lista: ");
    mostrarItens(lista);
}

int main(int argc, char * argv[]) {
    Lista * lista = newLista();
    int op;
    do {
        printf("MENU\n");
        printf("[1] -- inserirNoInicio()\n");
        printf("[2] -- inserirNoFim()\n");
        printf("[3] -- inserirNaPos()\n");
        printf("[4] -- removerDoInicio()\n");
        printf("[5] -- removerDoFim()\n");
        printf("[6] -- removerDaPos()\n");
        printf("[7] -- mostrarItens()\n");
        printf("[0] -- sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: 
                realizaOperacao(lista, "II");
                break;
            case 2:
                realizaOperacao(lista, "IF");
                break;
            case 3:
                realizaOperacao(lista, "I*");
                break;
            case 4:
                realizaOperacao(lista, "RI");
                break;
            case 5:
                realizaOperacao(lista, "RF");
                break;
            case 6:
                realizaOperacao(lista, "R*");
                break;
            case 7:
                printf("Elementos da lista: ");
                mostrarItens(lista);
                break;
            case 0:
                printf("Finalizado.\n");
                desalocarLista(lista);
                break;
            default: 
                printf("Operacao invalida.\n");
                break;
        }
    } while (op != 0);
}
