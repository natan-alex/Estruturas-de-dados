package arvore_avl;

public class Main {
    public static void main(String[] args) {
		ArvoreAvl avl = new ArvoreAvl();

		int aInserir[] = {12, 15, 18, 2, 5, 19, 4, 23, 10, 11, 1, 3};
		for (int i = 0; i < aInserir.length; i++) 
			avl.inserirItemNaAvl(aInserir[i]);

		avl.mostrarEmTodasAsOrdens();
		System.out.println(avl.pesquisarPorItemNaAvl(20));
		System.out.println(avl.pesquisarPorItemNaAvl(11));
		avl.removerItemDaAvl(5);
		avl.mostrarEmTodasAsOrdens();
		avl.inserirItemNaAvl(21);
		avl.mostrarEmTodasAsOrdens();
    }
}
