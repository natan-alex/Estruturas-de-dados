package arvore_avl;

public class NoAvl {
	int item, fator;
	NoAvl esq, dir;

	public NoAvl(int item) {
		this(item, 1, null, null);
	}
	
	public NoAvl(int item, int fator, NoAvl esq, NoAvl dir) {
		this.item = item;
		this.fator = fator;
		this.esq = esq;
		this.dir = dir;
	}
}
