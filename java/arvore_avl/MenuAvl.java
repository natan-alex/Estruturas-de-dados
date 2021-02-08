package arvore_avl;

import main.Common;
import main.MenuInterface;

public class MenuAvl implements MenuInterface {
	@Override
	public void menu() {
		ArvoreAvl avl = new ArvoreAvl();
		int opcao, item;
		do {
			System.out.println("");
			System.out.println("\t\tMENU: ARVORE AVL");
			System.out.println("  [1] - inserir item na árvore");
			System.out.println("  [2] - remover item da árvore");
			System.out.println("  [3] - checar se existe item na árvore");
			System.out.println("  [4] - pesquisar informações do nó que contém determinado item");
			System.out.println("  [5] - mostrar árvore em todas as ordens");
			System.out.println("  [6] - mostrar árvore na pré-ordem");
			System.out.println("  [7] - mostrar árvore em-ordem");
			System.out.println("  [8] - mostrar árvore na pós-ordem");
			System.out.println("  [9] - mostrar número de nós da árvore");
			System.out.println("  [0] - sair");
			System.out.print("  Opção: ");
			opcao = Common.input.nextInt();
			System.out.println("");
			switch(opcao) {
				case 0:
					avl.desalocarArvoreDaMemoria();
					System.out.println("Programa encerrado.");
					break;
				case 1:
					System.out.print("Item a ser inserido: ");
					item = Common.input.nextInt();
					if (avl.inserirItemNaAvl(item)) {
						System.out.println("Item inserido com sucesso.");
					} else { 
						System.out.println("Falha ao inserir o item.");
					}
					break;
				case 2:
					System.out.print("Item a ser removido: ");
					item = Common.input.nextInt();
					if (avl.removerItemDaAvl(item)) {
						System.out.println("Item removido com sucesso.");
					} else { 
						System.out.println("Falha ao remover o item.");
					}
					break;
				case 3:
					System.out.print("Item a ser procurado: ");
					item = Common.input.nextInt();
					if (avl.pesquisarPorItemNaAvl(item)) {
						System.out.println("Item encontrado na árvore.");
					} else {
						System.out.println("Item não encontrado.");
					}
					break;
				case 4:
					System.out.print("Item a ser procurado: ");
					item = Common.input.nextInt();
					avl.obterInformacoesDoNo(item);
					break;
				case 5:
					avl.mostrarEmTodasAsOrdens();
					break;
				case 6:
					avl.mostrarAvlEmPreOrdem();
					break;
				case 7:
					avl.mostrarAvlEmOrdem();
					break;
				case 8:
					avl.mostrarAvlEmPosOrdem();
					break;
				case 9:
					System.out.println("Número de nós: "+avl.contarNosDaArvore());
					break;
				default:
					break;
			}
		} while (opcao != 0);
	}
}
