package pilha_dinamica;

public class CelulaPilha {
    public int item;
    public CelulaPilha prox;

    public CelulaPilha() {
        this(-1, null);
    }

    public CelulaPilha(int item, CelulaPilha prox) {
        this.item = item;
        this.prox = prox;
    }
}
