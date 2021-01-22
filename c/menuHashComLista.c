#include "lista_dinamica/listaDinamica.h"
#include "hash_com_lista/hashComLista.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv) {
    Lista ** thash = newHash2(5);
    inserirNaTabela(thash, 10);
    inserirNaTabela(thash, 20);
    inserirNaTabela(thash, 21);
    inserirNaTabela(thash, 31);
    inserirNaTabela(thash, 51);
    inserirNaTabela(thash, 22);
    inserirNaTabela(thash, 13);
    inserirNaTabela(thash, 44);
    mostrarItensTabela(thash);
    removerDaTabela(thash, 0);
    mostrarItensTabela(thash);
    removerDaTabelaNaPos(thash, 1, 1);
    mostrarItensTabela(thash);
    getPosicaoDeUmItem(thash, 13);
    return 0;
}

