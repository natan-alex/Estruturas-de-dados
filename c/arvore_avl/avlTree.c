#include "avlTree.h"
#include "noAvl.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int remocaoFeita, insercaoFeita;

// ===========================================================

AvlTree * newAvl() { 
	AvlTree * avl = (AvlTree *) malloc(sizeof(AvlTree));
	avl->raiz = NULL;
	return avl;
}

// ===========================================================

int getMaior(int n1, int n2) {
	return (n1 <= n2) ? n2 : n1;		
}

int getFatorDoNo(No * no) {
	return (no == NULL) ? 0 : no->fator;
}

// fator do nó recebe o maior entre os fatores
// da esquerda e direita -> o que faz com que os fatores
// sejam armazenados em módulo
void atualizarFatorDoNo(No * no) {
	no->fator = 1 + getMaior(getFatorDoNo(no->esq), getFatorDoNo(no->dir)); 
}

// cálculo é feito com fator do nó a esquerda
// menos o fator do nó a direita
int calcularFatorDoNo(No * no) {
	return getFatorDoNo(no->esq) - getFatorDoNo(no->dir);
}

// ===========================================================

No * realizarRotacaoSimplesAEsquerda(No * no) {
	No * noDir = no->dir;
	No * noDirEsq = noDir->esq;
	no->dir = noDirEsq;
	noDir->esq = no;

	atualizarFatorDoNo(no);
	atualizarFatorDoNo(noDir);

	return noDir;
}

No * realizarRotacaoSimplesADireita(No * no) {
	No * noEsq = no->esq;
	No * noEsqDir = noEsq->dir;
	no->esq = noEsqDir;
	noEsq->dir = no;

	atualizarFatorDoNo(no);
	atualizarFatorDoNo(noEsq);

	return noEsq;
}
  
No * realizarRotacaoDuplaAEsquerda(No * no) {
	no->esq = realizarRotacaoSimplesAEsquerda(no->esq);
	return realizarRotacaoSimplesADireita(no);
}

No * realizarRotacaoDuplaADireita(No * no) {
	no->dir = realizarRotacaoSimplesADireita(no->dir);
	return realizarRotacaoSimplesAEsquerda(no);
}
// ===========================================================

void mostrarPre(No * no) {
	if (no != NULL) {
		printf("%d ", no->item);
		mostrarPre(no->esq);
		mostrarPre(no->dir);
	}
}

void mostrarPreOrdem(AvlTree * avl) {
	printf("PRE-ORDEM: ");
	printf("[ ");
	mostrarPre(avl->raiz);
	printf("]\n");
}

void mostrarEm(No * no) {
	if (no != NULL) {
		mostrarEm(no->esq);
		printf("%d ", no->item);
		mostrarEm(no->dir);
	}
}

void mostrarEmOrdem(AvlTree * avl) {
	printf("EM-ORDEM: ");
	printf("[ ");
	mostrarEm(avl->raiz);
	printf("]\n");
}

void mostrarPos(No * no) {
	if (no != NULL) {
		mostrarPos(no->esq);
		mostrarPos(no->dir);
		printf("%d ", no->item);
	}
}

void mostrarPosOrdem(AvlTree * avl) {
	printf("POS-ORDEM: ");
	printf("[ ");
	mostrarPos(avl->raiz);
	printf("]\n");
}

void mostrarTodasOrdens(AvlTree * avl) {
	mostrarPreOrdem(avl);
	mostrarEmOrdem(avl);
	mostrarPosOrdem(avl);
}

// ===========================================================

// contar o número de nos de maneira recursiva:
// conta o número de filhos de um nó + 1 do próprio nó
int contarNos(No * no) {
	return (no != NULL) ? contarNos(no->esq) + contarNos(no->dir) + 1 : 0;
}

int contarNosDaArvore(AvlTree * avl) {
	return contarNos(avl->raiz);
}

// ===========================================================

// retorna o nó balanceado fazendo as devidas rotações
No * balancearNo(No * no) {
	if (no != NULL) {
		atualizarFatorDoNo(no);
		int fatorDoNo = calcularFatorDoNo(no);
		if (fatorDoNo == -2) {
			// nó mais pesado a direita
			if (calcularFatorDoNo(no->dir) == 1) {
				no = realizarRotacaoDuplaADireita(no);
			} else {
				no = realizarRotacaoSimplesAEsquerda(no);
			}
		} else if (fatorDoNo == 2) {
			// nó mais pesado a esquerda
			if (calcularFatorDoNo(no->esq) == -1) {
				no = realizarRotacaoDuplaAEsquerda(no);
			} else {
				no = realizarRotacaoSimplesADireita(no);
			}
		}
	}
	return no;
}

// ===========================================================

No * inserir(No * no, int item) {
	if (no == NULL) {
		no = newNo(item);
		insercaoFeita = 1;
	} else if (item > no->item) {
		no->dir = inserir(no->dir, item);
		no = balancearNo(no);
	} else if (item < no->item) {
		no->esq = inserir(no->esq, item);
		no = balancearNo(no);
	} else {
		// item == no->item
		printf("Item já inserido previamente na árvore!\n");
	}
	return no;
}

int inserirNaArvore(AvlTree * avl, int item) {
	insercaoFeita = 0;
	avl->raiz = inserir(avl->raiz, item);
	return insercaoFeita;
}

// ===========================================================

No * remover(No * no, int aSerRemovido) {
	if (no == NULL) {
		// item nao encontrado
		printf("Item não encontrado.\n");
	} else if (aSerRemovido > no->item) {
		no->dir = remover(no->dir, aSerRemovido);
	} else if (aSerRemovido < no->item) {
		no->esq = remover(no->esq, aSerRemovido);
	} else if (no->esq == NULL) {
		no = no->dir;
		remocaoFeita = 1;
	} else if (no->dir == NULL) {
		no = no->esq;
		remocaoFeita = 1;
	} else {
		No * tmp = no->esq, * paiTmp = no;
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
			atualizarFatorDoNo(paiTmp);
		}
		free(tmp);
		paiTmp = NULL;
		tmp = NULL;
		remocaoFeita = 1;
	}
	return balancearNo(no);
}

int removerDaArvore(AvlTree * avl, int aSerRemovido) {
	remocaoFeita = 0;
	avl->raiz = remover(avl->raiz, aSerRemovido);
	return remocaoFeita;
}

// ===========================================================

No * pesquisarInfos(No * no, int item) {
	No * result;
	if (no == NULL) {
		result = NULL;
	} else if (item == no->item) {
		result = no;
	} else if (item > no->item) {
		result = pesquisarInfos(no->dir, item);
	} else {
		result = pesquisarInfos(no->esq, item);
	}
	return result;
}

void pesquisarPorNoContendoItem(AvlTree * avl, int item) {
	No * result = pesquisarInfos(avl->raiz, item);
	if (result != NULL) {
		printf("Item encontrado!\n");
		printf("Informações sobre o nó que contém o item:\n");
		printf("Fator: %d\n", calcularFatorDoNo(result));
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

int pesquisar(No * no, int item) {
	int encontrado = 0;
	if (no != NULL) {
		if (item == no->item) {
			encontrado = 1;
		} else if (item > no->item) {
			encontrado = pesquisar(no->dir, item);
		} else {
			encontrado = pesquisar(no->esq, item);
		}
	}
	return encontrado;
}

int pesquisarPorItemNaArvore(AvlTree * avl, int item) {
	return pesquisar(avl->raiz, item);
}

// ===========================================================

void desalocarNos(No * no) {
	if (no != NULL) {
		desalocarNos(no->esq);
		desalocarNos(no->dir);
		free(no);
		no = NULL;
	}
}

void desalocarArvoreDaMemoria(AvlTree * avl) {
	desalocarNos(avl->raiz);
	free(avl);
	avl = NULL;
}
