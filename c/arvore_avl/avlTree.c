#include "avlTree.h"
#include "noAvl.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

AvlTree * newAvl() { 
	AvlTree * avl = (AvlTree *) malloc(sizeof(AvlTree));
	avl->raiz = NULL;
	return avl;
}

No * rotacaoSimplesEsq(No * desbalanceado) {
	No * noDir = desbalanceado->dir;
	No * noDirEsq = noDir->esq;
	desbalanceado->dir = noDirEsq;
	noDir->esq = desbalanceado;
	return noDir;
}

No * rotacaoSimplesDir(No * desbalanceado) {
	No * noEsq = desbalanceado->esq;
	No * noEsqDir = noEsq->dir;
	desbalanceado->esq = noEsqDir;
	noEsq->dir = desbalanceado;
	return noEsq;
}

No * rotacaoDuplaEsq(No * desbalanceado) {
	desbalanceado->esq = rotacaoSimplesEsq(desbalanceado->esq);
	desbalanceado = rotacaoSimplesDir(desbalanceado);
	return desbalanceado;
}

No * rotacaoDuplaDir(No * desbalanceado) {
	desbalanceado->dir = rotacaoSimplesDir(desbalanceado->dir);
	desbalanceado = rotacaoSimplesEsq(desbalanceado);
	return desbalanceado;
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

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

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

// contar o numero de nos de maneira recursiva:
// conta o numero de filhos de um no + 1 do proprio no
int contarNos(No * no) {
	return (no != NULL) ? contarNos(no->esq) + contarNos(no->dir) + 1 : 0;
}

int contarNosDaArvore(AvlTree * avl) {
	return contarNos(avl->raiz);
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

// retorna o fator de um no:
// fator = fatorNoEsq - fatorNoDir
int calcularFator(No * no) {
	int fatorEsq = (no->esq == NULL) ? 0 : 1 + no->esq->fator;
	int fatorDir = (no->dir == NULL) ? 0 : 1 + no->dir->fator;
	return fatorEsq - fatorDir;
}

No * balancearNo(No * no) {
	if (no != NULL) {
		int fator = calcularFator(no);
		if (abs(fator) <= 1) {
			// se nao precisar de fazer nenhuma rotacao
			// atualiza o fator do no em questao
			no->fator = abs(fator);
		} else if (fator == -2) {
			// mais pesada a direita
			int fatorFilhoDir = calcularFator(no->dir);
			if (fatorFilhoDir == 1) {
				no->dir = rotacaoSimplesDir(no->dir);
			}
			no = rotacaoSimplesEsq(no);
		} else if (fator == 2) {
			// mais pesada a esquerda
			int fatorFilhoEsq = calcularFator(no->esq);
			if (fatorFilhoEsq == -1) {
				no->esq = rotacaoSimplesEsq(no->esq);
			}
			no = rotacaoSimplesDir(no);
		}
	}
	return no;
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

No * inserir(No * no, int item) {
	if (no == NULL) {
		no = newNo(item);
		printf("Item inserido com sucesso.\n");
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

void inserirNaArvore(AvlTree * avl, int item) {
	avl->raiz = inserir(avl->raiz, item);
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

No * retornaMaiorSubArvoreEsq(No * no) {
	No * tmp = no->esq;
	for (; tmp->dir != NULL; tmp = tmp->dir);
	return tmp;
}

No * remover(No * no, int aSerRemovido) {
	if (no == NULL) {
		// item nao encontrado
		printf("Item nao encontrado.\n");
	} else if (aSerRemovido > no->item) {
		no->dir = remover(no->dir, aSerRemovido);
	} else if (aSerRemovido < no->item) {
		no->esq = remover(no->esq, aSerRemovido);
	} else if (no->esq == NULL) {
		no = no->dir;
	} else if (no->dir == NULL) {
		no = no->esq;
	} else {
		No * tmp = no->esq;
		no->esq = retornaMaiorSubArvoreEsq(no)->esq;
		no->item = tmp->item;
		free(tmp);
		tmp = NULL;
	}
	return balancearNo(no);
}

void removerDaArvore(AvlTree * avl, int aSerRemovido) {
	avl->raiz = remover(avl->raiz, aSerRemovido);
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

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
		printf("Fator: %d\n", calcularFator(result));
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

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

bool pesquisar(No * no, int item) {
	bool encontrado = false;
	if (no != NULL) {
		if (item == no->item) {
			encontrado = true;
		} else if (item > no->item) {
			encontrado = pesquisar(no->dir, item);
		} else {
			encontrado = pesquisar(no->esq, item);
		}
	}
	return encontrado;
}

void pesquisarPorItemNaArvore(AvlTree * avl, int item) {
	if (pesquisar(avl->raiz, item)) {
		printf("Item encontrado!\n");
	} else {
		printf("Item nao encontrado.\n");
	}
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

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
