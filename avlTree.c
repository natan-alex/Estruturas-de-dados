#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct No {
	int item;
	struct No * esq, * dir;
	int fator;
} No;

No * newNo(int item) {
	No * no = (No *) malloc(sizeof(No));
	no->item = item;
	no->esq = NULL;
	no->dir = NULL;
	no->fator = 0;
	return no;
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

typedef struct AvlTree {
	No * raiz;
} AvlTree;

AvlTree * newAvl() {
	AvlTree * avl = (AvlTree *) malloc(sizeof(AvlTree));
	avl->raiz = NULL;
	return avl;
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

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
int obterDiferencaFator(No * no) {
	int fatorEsq = (no->esq == NULL) ? 0 : 1 + no->esq->fator;
	int fatorDir = (no->dir == NULL) ? 0 : 1 + no->dir->fator;
	return fatorEsq - fatorDir;
}

No * balancearNo(No * no) {
	if (no != NULL) {
		int fator = obterDiferencaFator(no);
		if (abs(fator) <= 1) {
			// se nao precisar de fazer nenhuma rotacao
			// atualiza o fator do no em questao
			no->fator = abs(fator);
		} else if (fator == -2) {
			// mais pesada a direita
			int fatorFilhoDir = obterDiferencaFator(no->dir);
			if (fatorFilhoDir == 1) {
				no->dir = rotacaoSimplesDir(no->dir);
			}
			no = rotacaoSimplesEsq(no);
		} else if (fator == 2) {
			// mais pesada a esquerda
			int fatorFilhoEsq = obterDiferencaFator(no->esq);
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
		printf("Fator: %d\n", obterDiferencaFator(result));
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

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

int lerOpcao() {
	int opcao;
	scanf("%d", &opcao);
	return opcao;
}

int tratarOpcao(int opcao, int limiteInferior, int limiteSuperior) {
	while (opcao < limiteInferior || opcao > limiteSuperior) {
		printf("Opção inválida, tente novamente.\n");
		printf("Nova opção: ");
		opcao = lerOpcao();
	}
	return opcao;
}

void chamarFuncaoCorrespondente(int opcao, AvlTree * avl) {
	printf("\n");
	int item;
	switch(opcao) {
		case 0:
			desalocarArvoreDaMemoria(avl);
			printf("Programa encerrado.\n");
			break;
		case 1:
			printf("Item a ser inserido: ");
			scanf("%d", &item);
			inserirNaArvore(avl, item);
			break;
		case 2:
			printf("Item a ser removido: ");
			scanf("%d", &item);
			removerDaArvore(avl, item);
			break;
		case 3:
			printf("Item a ser procurado: ");
			scanf("%d", &item);
			pesquisarPorItemNaArvore(avl, item);
			break;
		case 4:
			printf("Item a ser procurado: ");
			scanf("%d", &item);
			pesquisarPorNoContendoItem(avl, item);
			break;
		case 5:
			mostrarTodasOrdens(avl);
			break;
		case 6:
			mostrarPreOrdem(avl);
			break;
		case 7:
			mostrarEmOrdem(avl);
			break;
		case 8:
			mostrarPosOrdem(avl);
			break;
		case 9:
			printf("Número de nós: %d\n", contarNosDaArvore(avl));
			break;
		default:
			break;
	}
}

void menu(AvlTree * avl) {
	int opcao;
	do {
		printf("\n");
		printf("\t\tMENU\t\t\n");
		printf("  [1] - inserir item na árvore\n");
		printf("  [2] - remover item da árvore\n");
		printf("  [3] - checar se existe item na árvore\n");
		printf("  [4] - pesquisar informações do nó que contém determinado item\n");
		printf("  [5] - mostrar árvore em todas as ordens\n");
		printf("  [6] - mostrar árvore na pré-ordem\n");
		printf("  [7] - mostrar árvore em-ordem\n");
		printf("  [8] - mostrar árvore na pós-ordem\n");
		printf("  [9] - mostrar número de nós da árvore\n");
		printf("  [0] - sair\n");
		printf("  Opção: ");
		opcao = lerOpcao();
		opcao = tratarOpcao(opcao, 0, 9);
		chamarFuncaoCorrespondente(opcao, avl);
	} while (opcao != 0);
}

// -*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-

int main(int argc, char ** argv) {
	AvlTree * avl = newAvl();
	menu(avl);
    return 0;
}
