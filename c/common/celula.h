#ifndef CELULA_H
#define CELULA_H

typedef struct Celula {
    int item;
    struct Celula * prox;
} Celula;

Celula * newCelula(); 

Celula * newCelula2(int item); 

Celula * newCelula3(Celula * prox, int item); 

#endif
