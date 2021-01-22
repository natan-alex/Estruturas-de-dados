#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "noAvl.h"

#include <stdbool.h>

typedef struct AvlTree {
	No * raiz;
} AvlTree;

AvlTree * newAvl(); 

No * rotacaoSimplesEsq(No * desbalanceado); 

No * rotacaoSimplesDir(No * desbalanceado); 

No * rotacaoDuplaEsq(No * desbalanceado); 

No * rotacaoDuplaDir(No * desbalanceado); 

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void mostrarPre(No * no); 

void mostrarPreOrdem(AvlTree * avl); 

void mostrarEm(No * no); 

void mostrarEmOrdem(AvlTree * avl); 

void mostrarPos(No * no); 

void mostrarPosOrdem(AvlTree * avl); 

void mostrarTodasOrdens(AvlTree * avl); 

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

// contar o numero de nos de maneira recursiva:
// conta o numero de filhos de um no + 1 do proprio no
int contarNos(No * no); 

int contarNosDaArvore(AvlTree * avl); 

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

// retorna o fator de um no:
// fator = fatorNoEsq - fatorNoDir
int calcularFator(No * no); 

No * balancearNo(No * no); 

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

No * inserir(No * no, int item); 

void inserirNaArvore(AvlTree * avl, int item); 

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

No * retornaMaiorSubArvoreEsq(No * no); 

No * remover(No * no, int aSerRemovido); 
void removerDaArvore(AvlTree * avl, int aSerRemovido); 

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

No * pesquisarInfos(No * no, int item); 

void pesquisarPorNoContendoItem(AvlTree * avl, int item); 

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

bool pesquisar(No * no, int item); 

void pesquisarPorItemNaArvore(AvlTree * avl, int item); 

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

void desalocarNos(No * no); 

void desalocarArvoreDaMemoria(AvlTree * avl); 

#endif
