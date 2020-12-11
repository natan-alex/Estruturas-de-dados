#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TAM 7
#define REALSIZE (TAM+5)

int reserva = 0;

int ** makeTable() {
    int **thash = (int **) malloc(sizeof(int *) * REALSIZE);
    for (int i = 0; i < REALSIZE; i++) {
        thash[i] = NULL;
    }
    return thash;
}

int hash(int key) {
    return key % TAM;
}

// return the position where the item
// has been inserted
// return -1 if could not insert
int inserir(int **thash, int item) {
    int posInsercao = -1;
    int pos = hash(item);
    int *p = (int *) malloc(sizeof(int));
    *p = item;
    if (thash[pos] == NULL) {
        thash[pos] = p;
        posInsercao = pos;
    } else {
        if (reserva < REALSIZE) {
            int posReserva = TAM + reserva++;
            thash[posReserva] = p; 
            posInsercao = posReserva;
        } else {
            printf("Area reserva cheia!\n");
            free(p);
        }
    }
    p = NULL;
    return posInsercao;
}

// remove item using its position
int removerPos(int **thash, int key) {
    int removed = -9999;

    // is key valid?
    if (key < 0 || key >= REALSIZE) {
        printf("Chave de procura invalida.\n");
    } else {
        // if there is something in the position
        if (thash[key] != NULL) {
            removed = *thash[key];
            bool hasSubstitute = false;
            for (int i = 0; i < reserva && !hasSubstitute; i++) {
                if (hash(*thash[i + TAM]) == key) {
                    hasSubstitute = true;
                    *thash[key] = *thash[i + TAM];
                    if (reserva > 0)
                        reserva--;
                    *thash[i + TAM] = *thash[TAM + reserva];
                    free(thash[TAM + reserva]);
                    thash[TAM + reserva] = NULL;
                }
            }
            if (!hasSubstitute) {
                free(thash[key]);
                thash[key] = NULL;
            }
        }
    }

    return removed;
}

// remove item -> return its position 
int removerItem(int **thash, int item) {
    int posRemovido = -1;
    int posItem = hash(item);
    if (*thash[posItem] == item) {
        posRemovido = posItem;
        bool hasSubstitute = false;
        for (int i = 0; i < reserva && !hasSubstitute; i++) {
            // if any item has the same hash
            // as the item to be removed
            if (hash(*thash[i + TAM]) == posItem) {
                hasSubstitute = true;
                *thash[posItem] = *thash[i + TAM];
                if (reserva > 0)
                    reserva--;
                *thash[i + TAM] = *thash[TAM + reserva];
                free(thash[TAM + reserva]);
                thash[TAM + reserva] = NULL;
            }
        }
        if (!hasSubstitute) {
            free(thash[posItem]);
            thash[posItem] = NULL;
        }
    } else {
        // searching in the overflow area
        for (int i = 0; i < reserva; i++) {
            if (*thash[i + TAM] == item) {
                posRemovido = i + TAM;
                // if reserva > 0, the position of
                // the last item in overflow area
                // is TAM + reserva - 1
                if (reserva > 0)
                    reserva--;
                *thash[i + TAM] = *thash[TAM + reserva];
                free(thash[TAM + reserva]);
                thash[TAM + reserva] = NULL;
                i = reserva;
            }
        }
    }
    return posRemovido;
}

void mostrar(int **thash) {
    printf("Área principal: [ ");
    for (int i = 0; i < TAM; i++) 
        printf("%d ", (thash[i] == NULL) ? -1 : *thash[i]);
    printf("]\n");
    
    printf("Área de reserva: [ ");
    for (int i = 0; i < (REALSIZE - TAM); i++) 
        printf("%d ", (thash[i + TAM] == NULL) ? -1 : *thash[i + TAM]);
    printf("]\n\n");
}

int main() {
    int **thash = makeTable();
    inserir(thash, 10);
    inserir(thash, 30);
    mostrar(thash);
    inserir(thash, 20);
    inserir(thash, 21);
    inserir(thash, 14);
    inserir(thash, 45);
    inserir(thash, 35);
    inserir(thash, 4);
    inserir(thash, 12);
    inserir(thash, 1);
    mostrar(thash);
    printf("Posicao removido: %d\n", removerItem(thash, 21));
    printf("apos remocao do 21: \n");
    mostrar(thash);
    printf("Posicao removido: %d\n", removerItem(thash, 45));
    printf("apos remocao do 45: \n");
    printf("Item removido: %d\n", removerPos(thash, 30));
    mostrar(thash);
}
