import java.util.List;

public class PilhaDinamica {
    private int qtd;
    private CelulaPilha topo;
    
    public PilhaDinamica() {
        qtd = 0;
        topo = null;
    }

    public void empilhar(int e) {
        topo = new CelulaPilha(e, topo);
        qtd++;
    }

	public void empilharList(List<Integer> lista) {
		for (int item : lista) 
			empilhar(item);
	}

    public int desempilhar() {
        int retorno = topo.item;
        CelulaPilha tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        qtd--;
        return retorno;
    }

    public void mostrarPilha() {
        for (CelulaPilha c = topo; c != null; c = c.prox) 
            System.out.println("|\t"+c.item+"\t|");
        System.out.println();
    }
}
