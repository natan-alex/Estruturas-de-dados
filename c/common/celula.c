#include "celula.h"

#include <stdlib.h>

Celula * newCelula() {
    Celula * c = (Celula *) malloc(sizeof(Celula));
    c->item = 0;
    c->prox = NULL;
    return c;
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
