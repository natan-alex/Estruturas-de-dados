package arvore_binaria;

import main.Common;

public class MenuArvoreBinaria {
	public static void menu() {
		ArvoreBinaria arvore = new ArvoreBinaria();
		int opcao, item;
		do {
			System.out.println("\n\tMENU => ARVORE BINARIA DE PESQUISA");
			System.out.println("[1] - inserir um item");
			System.out.println("[2] - inserir vários itens");
			System.out.println("[3] - remover item da árvore");
			System.out.println("[4] - mostrar em pré ordem");
			System.out.println("[5] - mostrar em ordem crescente");
			System.out.println("[6] - mostrar em pós ordem");
			System.out.println("[7] - mostrar em todas as ordens");
			System.out.println("[0] - sair");
			System.out.print("Opção: ");
			opcao = Common.input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser inserido na árvore: ");
					item = Common.input.nextInt();
					arvore.inserir(item);
					System.out.println("Item inserido.");
					break;
				case 2:
					int cont = 1;
					do {
						System.out.print("Item "+cont+": ");
						cont++;
						item = Common.input.nextInt();
						Common.lista.add(item);
					} while (Common.continuar() != 'n');
					arvore.inserirList(Common.lista);
					Common.lista.clear();
					System.out.println("Itens inseridos.");
					break;
				case 3:
					System.out.print("Item a ser removido: ");
					item = Common.input.nextInt();
					arvore.remover(item);
					break;
				case 4:
					arvore.mostrarPreOrdem();
					break;
				case 5:
					arvore.mostrarEmOrdemCrescente();
					break;
				case 6:
					arvore.mostrarPosOrdem();
					break;
				case 7:
					arvore.mostrarTodasOrdens();
					break;
				case 0:
					System.out.println("Encerrado.");
					break;
				default:
					System.out.println("Opção inválida.");
					break;
			}
		} while (opcao != 0);
	}
}
