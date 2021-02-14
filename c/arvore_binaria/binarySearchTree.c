#include <stdio.h>
#include <stdlib.h>

#include "binarySearchTree.h"
#include "noBST.h"

// controlar o sucesso das inserções e das remoções feitas na 
// árvore
int remocaoFeitaNaBinaria, insercaoFeitaNaBinaria;

// ===========================================================

BST * newBST() { 
	BST * binaria = (BST *) malloc(sizeof(BST));
	binaria->raiz = NULL;
	return binaria;
}

// ===========================================================

void mostrarPreBinaria(NoBST * no) {
	if (no != NULL) {
		printf("%d ", no->item);
		mostrarPreBinaria(no->esq);
		mostrarPreBinaria(no->dir);
	}
}

void mostrarPreOrdemBinaria(BST * binaria) {
	printf("PRE-ORDEM: ");
	printf("[ ");
	mostrarPreBinaria(binaria->raiz);
	printf("]\n");
}

void mostrarEmBinaria(NoBST * no) {
	if (no != NULL) {
		mostrarEmBinaria(no->esq);
		printf("%d ", no->item);
		mostrarEmBinaria(no->dir);
	}
}

void mostrarEmOrdemBinaria(BST * binaria) {
	printf("EM-ORDEM: ");
	printf("[ ");
	mostrarEmBinaria(binaria->raiz);
	printf("]\n");
}

void mostrarPosBinaria(NoBST * no) {
	if (no != NULL) {
		mostrarPosBinaria(no->esq);
		mostrarPosBinaria(no->dir);
		printf("%d ", no->item);
	}
}

void mostrarPosOrdemBinaria(BST * binaria) {
	printf("POS-ORDEM: ");
	printf("[ ");
	mostrarPosBinaria(binaria->raiz);
	printf("]\n");
}

void mostrarTodasOrdensBinaria(BST * binaria) {
	mostrarPreOrdemBinaria(binaria);
	mostrarEmOrdemBinaria(binaria);
	mostrarPosOrdemBinaria(binaria);
}

// ===========================================================

// contar o número de nos de maneira recursiva:
// conta o número de filhos de um nó + 1 do próprio nó
int contarNosDaBinaria(NoBST * no) {
	return (no != NULL) ? contarNosDaBinaria(no->esq) + contarNosDaBinaria(no->dir) + 1 : 0;
}

int contarNosDaArvoreBinaria(BST * binaria) {
	return contarNosDaBinaria(binaria->raiz);
}

// ===========================================================

NoBST * inserirNaBinaria(NoBST * no, int item) {
	if (no == NULL) {
		no = newNoBST(item);
		insercaoFeitaNaBinaria = 1;
	} else if (item > no->item) {
		no->dir = inserirNaBinaria(no->dir, item);
	} else if (item < no->item) {
		no->esq = inserirNaBinaria(no->esq, item);
	} else {
		// item == no->item
		printf("Item já inserido previamente na árvore!\n");
	}
	return no;
}

int inserirNaArvoreBinaria(BST * binaria, int item) {
	insercaoFeitaNaBinaria = 0;
	binaria->raiz = inserirNaBinaria(binaria->raiz, item);
	return insercaoFeitaNaBinaria;
}

// ===========================================================

NoBST * removerDaBinaria(NoBST * no, int aSerRemovido) {
	if (no == NULL) {
		// item nao encontrado
		printf("Item não encontrado.\n");
	} else if (aSerRemovido > no->item) {
		no->dir = removerDaBinaria(no->dir, aSerRemovido);
	} else if (aSerRemovido < no->item) {
		no->esq = removerDaBinaria(no->esq, aSerRemovido);
	} else if (no->esq == NULL) {
		no = no->dir;
		remocaoFeitaNaBinaria = 1;
	} else if (no->dir == NULL) {
		no = no->esq;
		remocaoFeitaNaBinaria = 1;
	} else {
		NoBST * tmp = no->esq, * paiTmp = no;
		// paiTmp deve andar primeiramente a esquerda
		if (tmp->dir != NULL) {
			paiTmp = no->esq;
			tmp = tmp->dir;
		}
		for (; tmp->dir != NULL; tmp = tmp->dir, paiTmp = paiTmp->dir);
		no->item = tmp->item;
		if (paiTmp == no) {
			// nada a direita de tmp
			no->esq = tmp->esq;
		} else {
			paiTmp->dir = tmp->esq;
		}
		free(tmp);
		paiTmp = NULL;
		tmp = NULL;
		remocaoFeitaNaBinaria = 1;
	}
	return no;
}

int removerDaArvoreBinaria(BST * binaria, int aSerRemovido) {
	remocaoFeitaNaBinaria = 0;
	binaria->raiz = removerDaBinaria(binaria->raiz, aSerRemovido);
	return remocaoFeitaNaBinaria;
}

// ===========================================================

NoBST * pesquisarInfosNaBinaria(NoBST * no, int item) {
	NoBST * result;
	if (no == NULL) {
		result = NULL;
	} else if (item == no->item) {
		result = no;
	} else if (item > no->item) {
		result = pesquisarInfosNaBinaria(no->dir, item);
	} else {
		result = pesquisarInfosNaBinaria(no->esq, item);
	}
	return result;
}

void pesquisarPorNoContendoItemNaBinaria(BST * binaria, int item) {
	NoBST * result = pesquisarInfosNaBinaria(binaria->raiz, item);
	if (result != NULL) {
		printf("Item encontrado!\n");
		printf("Informações sobre o nó que contém o item:\n");
		printf("Nó a esquerda: ");
		if (result->esq == NULL) 
			printf("(Não possui)\n");
		else 
			printf("%d\n", result->esq->item);
		printf("Nó a direita: ");
		if (result->dir == NULL) 
			printf("(Não possui)\n");
		else 
			printf("%d\n", result->dir->item);
	} else {
		printf("Item não encontrado.\n");
	}
}

// ===========================================================

int pesquisarNaBinaria(NoBST * no, int item) {
	int encontrado = 0;
	if (no != NULL) {
		if (item == no->item) {
			encontrado = 1;
		} else if (item > no->item) {
			encontrado = pesquisarNaBinaria(no->dir, item);
		} else {
			encontrado = pesquisarNaBinaria(no->esq, item);
		}
	}
	return encontrado;
}

int pesquisarPorItemNaArvoreBinaria(BST * binaria, int item) {
	return pesquisarNaBinaria(binaria->raiz, item);
}

// ===========================================================

void desalocarNosArvoreBinaria(NoBST * no) {
	if (no != NULL) {
		desalocarNosArvoreBinaria(no->esq);
		desalocarNosArvoreBinaria(no->dir);
		free(no);
		no = NULL;
	}
}

void desalocarArvoreBinariaDaMemoria(BST * binaria) {
	desalocarNosArvoreBinaria(binaria->raiz);
	free(binaria);
	binaria = NULL;
}
