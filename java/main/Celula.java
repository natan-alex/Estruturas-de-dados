package main;

public class Celula {
    public int item;
    public Celula prox;

    public Celula() {
        this(Integer.MIN_VALUE, null);
    }

    public Celula(int item) {
        this.item = item;
        this.prox = null;
    }

    public Celula(int item, Celula prox) {
        this.item = item;
        this.prox = prox;
    }
}
