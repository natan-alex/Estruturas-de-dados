#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hash.h"
#include "menuHashSimples.h"

Hash * newHash(int tamTable, int tamOverflow) {
	Hash * th = (Hash *) malloc(sizeof(Hash));

	th->posOverflow = 0;
	th->tableSize = tamTable;
	th->overflowSize = tamOverflow;
	th->realSize = tamTable + tamOverflow;

    th->tabela = (int **) malloc(sizeof(int *) * th->realSize);

    for (int i = 0; i < th->realSize; i++) {
        th->tabela[i] = NULL;
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
    if (th->tabela[pos] == NULL) {
        th->tabela[pos] = p;
        posInsercao = pos;
    } else {
		// check if there is space to insert something
		// in the overflow area
        if (th->posOverflow < (th->realSize - th->tableSize)) {
            int posReserva = th->tableSize + th->posOverflow++;
            th->tabela[posReserva] = p; 
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
        if (th->tabela[key] != NULL) {
            removed = *th->tabela[key];
            bool hasSubstitute = false;
			// search for a substitute that has
			// the same hash of the item
            for (int i = 0; i < th->posOverflow && !hasSubstitute; i++) {
                if (hash(th, *th->tabela[i + th->tableSize]) == key) {
                    hasSubstitute = true;
                    *(th->tabela[key]) = *(th->tabela[i + th->tableSize]);
                    if (th->posOverflow > 0)
                        th->posOverflow--;
                    *(th->tabela[i + th->tableSize]) = *(th->tabela[th->tableSize + th->posOverflow]);
                    free(th->tabela[th->tableSize + th->posOverflow]);
                    th->tabela[th->tableSize + th->posOverflow] = NULL;
                }
            }
			// if there is no substitute,
			// just remove the item
            if (!hasSubstitute) {
                free(th->tabela[key]);
                th->tabela[key] = NULL;
            }
        }
    }

    return removed;
}

// remove item -> return its position 
int removerItem(Hash * th, int item) {
    int posRemovido = -1;
    int posItem = hash(th, item);
    if (*(th->tabela[posItem]) == item) {
        posRemovido = posItem;
        bool hasSubstitute = false;
        for (int i = 0; i < th->posOverflow && !hasSubstitute; i++) {
            if (hash(th, *(th->tabela[i + th->tableSize])) == posItem) {
                hasSubstitute = true;
                *(th->tabela[posItem]) = *(th->tabela[i + th->tableSize]);
                if (th->posOverflow > 0)
                    th->posOverflow--;
                *(th->tabela[i + th->tableSize]) = *(th->tabela[th->tableSize + th->posOverflow]);
                free(th->tabela[th->tableSize + th->posOverflow]);
                th->tabela[th->tableSize + th->posOverflow] = NULL;
            }
        }
        if (!hasSubstitute) {
            free(th->tabela[posItem]);
            th->tabela[posItem] = NULL;
        }
    } else {
        // searching in the overflow area
        for (int i = 0; i < th->posOverflow; i++) {
            if (*(th->tabela[i + th->tableSize]) == item) {
                posRemovido = i + th->tableSize;
                // if th->posOverflow > 0, the position of
                // the last item in overflow area
                // is th->tableSize + th->posOverflow - 1
                if (th->posOverflow > 0)
                    th->posOverflow--;
                *(th->tabela[i + th->tableSize]) = *(th->tabela[th->tableSize + th->posOverflow]);
                free(th->tabela[th->tableSize + th->posOverflow]);
                th->tabela[th->tableSize + th->posOverflow] = NULL;
                i = th->posOverflow;
            }
        }
    }
    return posRemovido;
}

void mostrar(Hash * th) {
    printf("\nÁrea principal: [ ");
    for (int i = 0; i < th->tableSize; i++) { 
		if (th->tabela[i] != NULL) 
			printf("%d ", *(th->tabela[i]));
	}
    printf("]\n");
    
    printf("Área de reserva: [ ");
    for (int i = 0; i < th->overflowSize; i++) {
		if ((th->tabela[ i + (th->tableSize) ]) != NULL)
			printf("%d ", *(th->tabela[i + th->tableSize]));
	}
    printf("]\n\n");
}

void desalocarTabela(Hash * th) {
	for (int i = 0; i < th->realSize; i++) {
		free(th->tabela[i]);
	}
	free(th);
}
