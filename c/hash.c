#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Hash {
	int tableSize;
	int overflowSize;
	int realSize;
	int posOverflow; // control insertions in overflow area
	int ** thash;
} Hash;

Hash * newHash(int tamTable, int tamOverflow) {
	Hash * th = (Hash *) malloc(sizeof(Hash));

	th->posOverflow = 0;
	th->tableSize = tamTable;
	th->overflowSize = tamOverflow;
	th->realSize = tamTable + tamOverflow;

    th->thash = (int **) malloc(sizeof(int *) * th->realSize);

    for (int i = 0; i < th->realSize; i++) {
        th->thash[i] = NULL;
    }

    return th;
}

int hash(Hash * th, int key) {
    return key % th->tableSize;
}

// return the position where the item
// has been inserted
// return -1 if could not insert
int inserir(Hash * th, int item) {
    int posInsercao = -1;
    int pos = hash(th, item);
    int *p = (int *) malloc(sizeof(int));
    *p = item;
    if (th->thash[pos] == NULL) {
        th->thash[pos] = p;
        posInsercao = pos;
    } else {
		// check if there is space to insert something
		// in the overflow area
        if (th->posOverflow < (th->realSize - th->tableSize)) {
            int posReserva = th->tableSize + th->posOverflow++;
            th->thash[posReserva] = p; 
            posInsercao = posReserva;
        } else {
            printf("Area de reserva cheia!\n");
            free(p);
        }
    }
    p = NULL;
    return posInsercao;
}

// remove item using its position
int removerPos(Hash * th, int key) {
    int removed = 0x7fffffff;

    // is key valid?
    if (key < 0 || key >= th->realSize) {
        printf("Chave de procura invalida. Chave: %d\n", key);
    } else {
        // if there is something in the position
        if (th->thash[key] != NULL) {
            removed = *th->thash[key];
            bool hasSubstitute = false;
			// search for a substitute that has
			// the same hash of the item
            for (int i = 0; i < th->posOverflow && !hasSubstitute; i++) {
                if (hash(th, *th->thash[i + th->tableSize]) == key) {
                    hasSubstitute = true;
                    *(th->thash[key]) = *(th->thash[i + th->tableSize]);
                    if (th->posOverflow > 0)
                        th->posOverflow--;
                    *(th->thash[i + th->tableSize]) = *(th->thash[th->tableSize + th->posOverflow]);
                    free(th->thash[th->tableSize + th->posOverflow]);
                    th->thash[th->tableSize + th->posOverflow] = NULL;
                }
            }
			// if there is no substitute,
			// just remove the item
            if (!hasSubstitute) {
                free(th->thash[key]);
                th->thash[key] = NULL;
            }
        }
    }

    return removed;
}

// remove item -> return its position 
int removerItem(Hash * th, int item) {
    int posRemovido = -1;
    int posItem = hash(th, item);
    if (*(th->thash[posItem]) == item) {
        posRemovido = posItem;
        bool hasSubstitute = false;
        for (int i = 0; i < th->posOverflow && !hasSubstitute; i++) {
            if (hash(th, *(th->thash[i + th->tableSize])) == posItem) {
                hasSubstitute = true;
                *(th->thash[posItem]) = *(th->thash[i + th->tableSize]);
                if (th->posOverflow > 0)
                    th->posOverflow--;
                *(th->thash[i + th->tableSize]) = *(th->thash[th->tableSize + th->posOverflow]);
                free(th->thash[th->tableSize + th->posOverflow]);
                th->thash[th->tableSize + th->posOverflow] = NULL;
            }
        }
        if (!hasSubstitute) {
            free(th->thash[posItem]);
            th->thash[posItem] = NULL;
        }
    } else {
        // searching in the overflow area
        for (int i = 0; i < th->posOverflow; i++) {
            if (*(th->thash[i + th->tableSize]) == item) {
                posRemovido = i + th->tableSize;
                // if th->posOverflow > 0, the position of
                // the last item in overflow area
                // is th->tableSize + th->posOverflow - 1
                if (th->posOverflow > 0)
                    th->posOverflow--;
                *(th->thash[i + th->tableSize]) = *(th->thash[th->tableSize + th->posOverflow]);
                free(th->thash[th->tableSize + th->posOverflow]);
                th->thash[th->tableSize + th->posOverflow] = NULL;
                i = th->posOverflow;
            }
        }
    }
    return posRemovido;
}

void mostrar(Hash * th) {
    printf("\nÁrea principal: [ ");
    for (int i = 0; i < th->tableSize; i++) 
        printf("%d ", (th->thash[i] == NULL) ? -1 : *(th->thash[i]));
    printf("]\n");
    
    printf("Área de reserva: [ ");
    for (int i = 0; i < th->overflowSize; i++) 
        printf("%d ", (th->thash[i + th->tableSize] == NULL) ? -1 : *(th->thash[i + th->tableSize]));
    printf("]\n\n");
}

int main() {
	Hash * th = newHash(7, 5);
    inserir(th, 10);
    inserir(th, 30);
    mostrar(th);
    inserir(th, 20);
    inserir(th, 21);
    inserir(th, 14);
    inserir(th, 45);
    inserir(th, 35);
    inserir(th, 4);
    inserir(th, 12);
    inserir(th, 1);
    mostrar(th);
    printf("Posicao removido: %d\n", removerItem(th, 21));
    printf("apos remocao do 21: \n");
    mostrar(th);
    printf("Posicao removido: %d\n", removerItem(th, 45));
	mostrar(th);
    printf("Item removido: %d\n", removerPos(th, 30));
    mostrar(th);
}
