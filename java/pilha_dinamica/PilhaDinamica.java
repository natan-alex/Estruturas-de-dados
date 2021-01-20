package pilha_dinamica;

import java.util.List;
import main.Celula;

public class PilhaDinamica {
    private int qtd;
    private Celula topo;
    
    public PilhaDinamica() {
        qtd = 0;
        topo = null;
    }

    public void empilhar(int e) {
        topo = new Celula(e, topo);
        qtd++;
    }

	public void empilharList(List<Integer> lista) {
		for (int item : lista) 
			empilhar(item);
	}

    public int desempilhar() {
        int retorno = topo.item;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        qtd--;
        return retorno;
    }

    public void mostrarPilha() {
        for (Celula c = topo; c != null; c = c.prox) 
            System.out.println("|\t"+c.item+"\t|");
        System.out.println();
    }
}
