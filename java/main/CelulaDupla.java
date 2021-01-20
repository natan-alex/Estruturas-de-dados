package main;

public class CelulaDupla {
    public int item;
    public CelulaDupla prox, anterior;

    public CelulaDupla() {
        this(Integer.MIN_VALUE, null, null);
    }

    public CelulaDupla(int item) {
        this.item = item;
        this.prox = null;
        this.anterior = null;
    }

    public CelulaDupla(int item, CelulaDupla prox, CelulaDupla anterior) {
        this.item = item;
        this.prox = prox;
		this.anterior = anterior;
    }
}
