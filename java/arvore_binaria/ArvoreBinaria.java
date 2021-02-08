package arvore_binaria;

import java.util.List;

public class ArvoreBinaria {
    private No raiz;

    public ArvoreBinaria() {
        raiz = null;
    }

    public boolean isVazia() {
        return (raiz == null);
    }

    public void inserir(int item) {
        raiz = inserir(item, raiz);
    }

    private No inserir(int item, No noAtual) {
        if (noAtual == null) {
            noAtual = new No(item, null, null);
        } else if (item > noAtual.item) {
            noAtual.dir = inserir(item, noAtual.dir);
        } else if (item < noAtual.item) {
            noAtual.esq = inserir(item, noAtual.esq);
        } else {
            System.out.println("Elemento "+item+" já inserido na árvore");
            return null;
        }
        return noAtual;
    }

	public void inserirList(List<Integer> lista) {
		for (int item : lista) 
			inserir(item);
	}

    public void inserirV2(int item) {
        inserirV2(item, raiz, null);
    }

    // estabelece conexão com nó depois da sua 
    // criação por meio do pai
    private void inserirV2(int item, No noAtual, No pai) {
        if (noAtual == null) {
            noAtual = new No(item, null, null);
            if (raiz == null) {
                raiz = noAtual;
                return;
            }
            if (item < pai.item) {
                pai.esq = noAtual;
            } else {
                pai.dir = noAtual;
            }
        } else if (item < noAtual.item) {
            inserirV2(item, noAtual.esq, noAtual);
        } else if (item > noAtual.item) {
            inserirV2(item, noAtual.dir, noAtual);
        } else {
            System.out.println("Elemento "+item+" já inserido na árvore.");
            return;
        }
    }

    public void remover(int item) {
        raiz = remover(item, raiz);
    }

    private No remover(int item, No noAtual) {
        if (noAtual == null) {
            System.out.println("Item não encontrado na árvore.");
            return null;
        } else if (item < noAtual.item) {
            noAtual.esq = remover(item, noAtual.esq);
        } else if (item > noAtual.item) {
            noAtual.dir = remover(item, noAtual.dir);
        } else if (noAtual.dir == null) {
            noAtual = noAtual.esq;
        } else if (noAtual.esq == null) {
            noAtual = noAtual.dir;
        } else {
            noAtual.esq = trocaPorMaiorDaEsquerda(noAtual, noAtual.esq);
        }
        return noAtual;
    }

    private No trocaPorMaiorDaEsquerda(No aSerRemovido, No noAtual) {
        if (noAtual.dir != null) {
            noAtual.dir = trocaPorMaiorDaEsquerda(aSerRemovido, noAtual.dir);
        } else {
            aSerRemovido.item = noAtual.item;
            noAtual = noAtual.esq;
        }
        return noAtual;
    }

    public void mostrarPreOrdem() {
        System.out.print("PRE-ORDEM: ");
        System.out.print("[ ");
        mostrarPreOrdem(raiz);
        System.out.println("]");
    }

    private void mostrarPreOrdem(No noAtual) {
        if (noAtual != null) {
            System.out.print(noAtual.item+" ");
            mostrarPreOrdem(noAtual.esq);
            mostrarPreOrdem(noAtual.dir);
        }
    }

    public void mostrarEmOrdemCrescente() {
        System.out.print("EM-ORDEM: ");
        System.out.print("[ ");
        mostrarEmOrdemCrescente(raiz);
        System.out.println("]");
    }

    private void mostrarEmOrdemCrescente(No noAtual) {
        if (noAtual != null) {
            mostrarEmOrdemCrescente(noAtual.esq);
            System.out.print(noAtual.item+" ");
            mostrarEmOrdemCrescente(noAtual.dir);
        }
    }

    public void mostrarPosOrdem() {
        System.out.print("POS-ORDEM: ");
        System.out.print("[ ");
        mostrarPosOrdem(raiz);
        System.out.println("]");
    }

    private void mostrarPosOrdem(No noAtual) {
        if (noAtual != null) {
            mostrarPosOrdem(noAtual.esq);
            mostrarPosOrdem(noAtual.dir);
            System.out.print(noAtual.item+" ");
        }
    }

	public void mostrarTodasOrdens() {
		System.out.println();
        mostrarPreOrdem();
        mostrarEmOrdemCrescente();
        mostrarPosOrdem();
	}

	public void desalocarArvoreDaMemoria() {
		desalocarNos(raiz);
	}

	private void desalocarNos(No no) {
		if (no != null) {
			desalocarNos(no.esq);
			desalocarNos(no.dir);
			no.esq = null;
			no.dir = null;
		}
	}
}
