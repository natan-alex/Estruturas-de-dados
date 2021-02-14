#include "noBST.h"

#ifndef BINARY_SEARCH_TREE 
#define BINARY_SEARCH_TREE

typedef struct BST {
	NoBST* raiz;
} BST;

BST * newBST();

void mostrarPreBinaria(NoBST * no);

void mostrarPreOrdemBinaria(BST * binaria);

void mostrarEmBinaria(NoBST * no);

void mostrarEmOrdemBinaria(BST * binaria);

void mostrarPosBinaria(NoBST * no);

void mostrarPosOrdemBinaria(BST * binaria);

void mostrarTodasOrdensBinaria(BST * binaria);

int contarNosDaBinaria(NoBST * no);

int contarNosDaArvoreBinaria(BST * binaria);

NoBST * inserirNaBinaria(NoBST * no, int item);

int inserirNaArvoreBinaria(BST * binaria, int item);

NoBST * removerDaBinaria(NoBST * no, int aSerRemovido);

int removerDaArvoreBinaria(BST * binaria, int aSerRemovido);

NoBST * pesquisarInfosNaBinaria(NoBST * no, int item);

void pesquisarPorNoContendoItemNaBinaria(BST * binaria, int item);

int pesquisarNaBinaria(NoBST * no, int item);

int pesquisarPorItemNaArvoreBinaria(BST * binaria, int item);

void desalocarNosArvoreBinaria(NoBST * no);

void desalocarArvoreBinariaDaMemoria(BST * binaria);

#endif
