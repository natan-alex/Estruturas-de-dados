public class CelulaMatriz {
    public int item;
    public CelulaMatriz inf, sup, esq, dir;

    public CelulaMatriz() {
        this(-1,null,null,null,null);
    }

    public CelulaMatriz(int item, CelulaMatriz inf, CelulaMatriz sup, CelulaMatriz esq, CelulaMatriz dir) {
        this.item = item;
        this.inf = inf;
        this.sup = sup;
        this.esq = esq;
        this.dir = dir;
    }
}
