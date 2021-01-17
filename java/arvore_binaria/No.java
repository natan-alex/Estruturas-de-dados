package arvore_binaria;

public class No {
    public No esq, dir;
    public int item;

    public No() {
        this(-1, null, null);
    }

    public No(int item, No esq, No dir) {
        this.item = item;
        this.esq = esq;
        this.dir = dir;
    }
}
