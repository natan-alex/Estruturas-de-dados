#include "common/celula.h"
#include "lista_dinamica/listaDinamica.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
