package arvore_avl;

public class Main {
    public static void main(String[] args) {
		ArvoreAvl avl = new ArvoreAvl();

		int aInserir[] = {10,12,15,5,2,3,20,11,17,13};
		for (int item : aInserir)
			avl.inserirItemNaAvl(item);

		avl.mostrarEmTodasAsOrdens();
		System.out.println(avl.pesquisarPorItemNaAvl(20));
		System.out.println(avl.pesquisarPorItemNaAvl(11));
		avl.removerItemDaAvl(5);
		avl.mostrarEmTodasAsOrdens();
		avl.inserirItemNaAvl(21);
		avl.mostrarEmTodasAsOrdens();
    }
}
