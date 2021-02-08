package lista_dinamica;

import main.Common;
import main.MenuInterface;

public class MenuLista implements MenuInterface {
	@Override	
	public void menu() {
		ListaDinamica list = new ListaDinamica();
		int opcao, item, pos;
		do {
			System.out.println("\n\tMENU: LISTA DINAMICA");
			System.out.println("[1] - inserir um item no inicio");
			System.out.println("[2] - inserir um item no fim");
			System.out.println("[3] - inserir um item em uma posição específica");
			System.out.println("[4] - remover do início");
			System.out.println("[5] - remover do fim");
			System.out.println("[6] - remover de uma posição específica");
			System.out.println("[7] - pesquisar por um item");
			System.out.println("[8] - mostrar itens da lista");
			System.out.println("[9] - mostrar tamanho da lista");
			System.out.println("[0] - sair");
			System.out.print("Opção: ");
			opcao = Common.input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("item a ser inserido: ");
					item = Common.input.nextInt();
					if (list.inserirNoInicio(item))
						System.out.println("item inserido com sucesso.");
					else 
						System.out.println("falha ao inserir o item.");
					break;
				case 2:
					System.out.print("Item a ser inserido: ");
					item = Common.input.nextInt();
					if (list.inserirNoFim(item))
						System.out.println("Item inserido com sucesso.");
					else 
						System.out.println("Falha ao inserir o item.");
					break;
				case 3:
					System.out.print("Item a ser inserido: ");
					item = Common.input.nextInt();
					System.out.print("Posição de inserção: ");
					pos = Common.input.nextInt();
					if (list.inserirPos(item, pos))
						System.out.println("Item inserido com sucesso.");
					break;
				case 4:
					item = list.removerDoInicio();
					if (item != Integer.MIN_VALUE)
						System.out.println("Item removido: "+item);
					break;
				case 5:
					item = list.removerDoFim();
					if (item != Integer.MIN_VALUE)
						System.out.println("Item removido: "+item);
					break;
				case 6:
					System.out.print("Posição de remoção: ");
					pos = Common.input.nextInt();
					item = list.removerPos(pos);
					if (item != Integer.MIN_VALUE)
						System.out.println("Item removido: "+item);
					break;
				case 7:
					System.out.print("Item a ser pesquisado: ");
					item = Common.input.nextInt();
					pos = list.pesquisarItem(item);
					if (pos == -1) 
						System.out.println("Item não encontrado.");
					else
						System.out.println("Item encontrado na posição: "+pos);
					break;
				case 8: 
					System.out.println("Itens: ");
					list.mostrarLista();
					break;
				case 9: 
					System.out.println("Tamanho atual da lista: "+list.getTamanhoDaLista());
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
