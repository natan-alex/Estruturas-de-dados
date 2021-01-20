package fila_dinamica;

import main.Celula;
import java.util.List;

public class FilaDinamica {
	private Celula primeiraAuxiliar, ultima;
	private int qtd;

	public FilaDinamica() {
		primeiraAuxiliar = new Celula();
		ultima = primeiraAuxiliar;
		qtd = 0;
	}

	public int getTamanhoDaFila() {
		return qtd;
	}

	public boolean isFilaVazia() {
		return ultima == primeiraAuxiliar;
	}

	public boolean enfileirar(int item) {
		boolean insercaoFeita = false;
		Celula auxiliar = new Celula(item);

		if (isFilaVazia()) {
			primeiraAuxiliar.prox = auxiliar;
		}

		ultima.prox = auxiliar; 
		ultima = auxiliar;
		qtd++;
		auxiliar = null;

		insercaoFeita = true;
		return insercaoFeita;
	}

	public void enfileirarList(List<Integer> lista) {
		boolean insercaoFeita = false;
		for (int item : lista) {
			insercaoFeita = enfileirar(item);
			if (insercaoFeita)
				System.out.println("Item "+item+" inserido com sucesso.");
		}
	}

	public int desenfileirar() {
		int itemRemovido = Integer.MIN_VALUE;

		if (isFilaVazia()) {
			System.out.println("Falha ao remover: fila vazia!");
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

	public void mostrarFila() {
		System.out.print("[ ");
		for (Celula c = primeiraAuxiliar.prox; c != null; c = c.prox) {
			System.out.print(c.item+" ");
		}
		System.out.println("]");
	}

}

