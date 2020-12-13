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
