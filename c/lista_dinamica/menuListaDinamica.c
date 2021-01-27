#include <stdio.h>
#include <string.h>
#include "../lista_dinamica/listaDinamica.h"
#include "menuListaDinamica.h"
#include "../common/sobreOpcoes.h"

void realizarOperacaoDaLista(Lista * lista, char * operacao) {
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
    mostrarItensDaLista(lista);
}

void menuListaDinamica() {
    Lista * lista = newLista();
    int op;
    do {
        printf("MENU: LISTA DINAMICA\n");
        printf("[1] -- inserir no inicio\n");
        printf("[2] -- inserir no fim\n");
        printf("[3] -- inserir na pos\n");
        printf("[4] -- remover do inicio\n");
        printf("[5] -- remover do fim\n");
        printf("[6] -- remover da pos\n");
        printf("[7] -- Mostrar itens\n");
        printf("[0] -- sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1: 
                realizarOperacaoDaLista(lista, "II");
                break;
            case 2:
                realizarOperacaoDaLista(lista, "IF");
                break;
            case 3:
                realizarOperacaoDaLista(lista, "I*");
                break;
            case 4:
                realizarOperacaoDaLista(lista, "RI");
                break;
            case 5:
                realizarOperacaoDaLista(lista, "RF");
                break;
            case 6:
                realizarOperacaoDaLista(lista, "R*");
                break;
            case 7:
                printf("Elementos da lista: ");
                mostrarItensDaLista(lista);
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
