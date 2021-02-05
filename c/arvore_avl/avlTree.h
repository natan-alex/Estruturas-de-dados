#include "noAvl.h"
#include <stdbool.h>

#ifndef AVL_TREE_H
#define AVL_TREE_H

typedef struct AvlTree {
	No * raiz;
} AvlTree;

AvlTree * newAvl(); 

int getMaior(int n1, int n2);

int getFatorDoNo(No * no);

void atualizarFatorDoNo(No * no);

int calcularFatorDoNo(No * no);

No * realizarRotacaoSimplesAEsquerda(No * no);

No * realizarRotacaoSimplesADireita(No * no);

  

No * realizarRotacaoDuplaAEsquerda(No * no);

No * realizarRotacaoDuplaADireita(No * no);

void mostrarPre(No * no);

void mostrarPreOrdem(AvlTree * avl);

void mostrarEm(No * no);

void mostrarEmOrdem(AvlTree * avl);

void mostrarPos(No * no);

void mostrarPosOrdem(AvlTree * avl);

void mostrarTodasOrdens(AvlTree * avl);

int contarNos(No * no);

int contarNosDaArvore(AvlTree * avl);

No * balancearNo(No * no);

No * inserir(No * no, int item);

void inserirNaArvore(AvlTree * avl, int item);

No * retornaMaiorSubArvoreEsq(No * no);

No * remover(No * no, int aSerRemovido);

void removerDaArvore(AvlTree * avl, int aSerRemovido);

No * pesquisarInfos(No * no, int item);

void pesquisarPorNoContendoItem(AvlTree * avl, int item);

bool pesquisar(No * no, int item);

void pesquisarPorItemNaArvore(AvlTree * avl, int item);

void desalocarNos(No * no);

void desalocarArvoreDaMemoria(AvlTree * avl);

#endif
