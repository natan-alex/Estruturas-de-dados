package lista_dinamica;

import main.Celula;

public class ListaDinamica {
	public Celula primeiraAuxiliar, ultima;
	private int qtd;

	public ListaDinamica() {
		primeiraAuxiliar = new Celula();
		ultima = primeiraAuxiliar;
		qtd = 0;
	}

	public boolean isListaVazia() {
		return ultima == primeiraAuxiliar;
	}

	public int getTamanhoDaLista() {
		return qtd;
	}

	public boolean inserirNoInicio(int item) {
		Celula auxiliar = new Celula(item);

		if (isListaVazia()) {
			ultima = auxiliar;
		}

		auxiliar.prox = primeiraAuxiliar.prox;
		primeiraAuxiliar.prox = auxiliar; 
		qtd++;
		auxiliar = null;

		return true;
	}

	public boolean inserirNoFim(int item) {
		Celula auxiliar = new Celula(item);

		if (isListaVazia()) {
			primeiraAuxiliar.prox = auxiliar;
		}

		ultima.prox = auxiliar;
		ultima = auxiliar;

		qtd++;
		auxiliar = null;

		return true;
	}

	public boolean inserirPos(int item, int pos) {
		if (pos < 0 || pos > qtd) {
			System.out.println("Falha ao inserir: posição de inserção inválida.");
			return false;
		}

		Celula auxiliar = new Celula(item);
		Celula tmp = primeiraAuxiliar;
		for (int cont = 0; cont < pos; tmp = tmp.prox, cont++);
		auxiliar.prox = tmp.prox;
		tmp.prox = auxiliar;
		qtd++;
		auxiliar = null;

		return true;
	}

	public int removerDoInicio() {
		int itemRemovido = Integer.MIN_VALUE;

		if (isListaVazia()) {
			System.out.println("Falha ao remover: lista vazia!");
			return itemRemovido;
		}

		Celula auxiliar = primeiraAuxiliar;
		primeiraAuxiliar = primeiraAuxiliar.prox;
		auxiliar.prox = null;
		auxiliar = null;
		itemRemovido = primeiraAuxiliar.item;
		qtd--;

		return itemRemovido;
	}

	public int removerDoFim() {
		int itemRemovido = Integer.MIN_VALUE;

		if (isListaVazia()) {
			System.out.println("Falha ao remover: lista vazia!");
			return itemRemovido;
		}

		Celula auxiliar = primeiraAuxiliar.prox;
		for (; auxiliar.prox != ultima; auxiliar = auxiliar.prox);
		itemRemovido = ultima.item;
		auxiliar.prox = null;
		ultima = auxiliar;
		qtd--;
		auxiliar = null;

		return itemRemovido;
	}

	public int removerPos(int pos) {
		int itemRemovido = Integer.MIN_VALUE;
		if (pos < 0 || pos >= qtd) {
			System.out.println("Falha ao remover: posição de remoção inválida.");
			return itemRemovido;
		} else if (pos == 0) {
			itemRemovido = removerDoInicio();
		} else if (pos == (qtd-1)) {
			itemRemovido = removerDoFim();
		} else {
			Celula auxiliar = primeiraAuxiliar;
			for (int cont = 0; cont < pos; auxiliar = auxiliar.prox, cont++);
			Celula aRemover = auxiliar.prox;
			auxiliar.prox = aRemover.prox;
			aRemover.prox = null;
			itemRemovido = aRemover.item;
			aRemover = null;
			auxiliar = null;
			qtd--;
		}

		return itemRemovido;
	}

	public int pesquisarItem(int item) {
		int pos = -1, cont = 0;
		for (Celula auxiliar = primeiraAuxiliar.prox; auxiliar != null && (pos == -1); auxiliar = auxiliar.prox, cont++) {
			if (auxiliar.item == item) {
				pos = cont;
			}
		}
		return pos;
	}

	public void mostrarLista() {
		System.out.print("[ ");
		for (Celula auxiliar = primeiraAuxiliar.prox; auxiliar != null; auxiliar = auxiliar.prox) {
			System.out.print(auxiliar.item+" ");
		}
		System.out.println("]");
	}
}

