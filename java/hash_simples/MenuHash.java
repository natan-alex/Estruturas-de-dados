package hash_simples;

import main.Common;
import main.MenuInterface;

public class MenuHash implements MenuInterface {
	@Override	
	public void menu() {
		System.out.print("Tamanho da área principal da tabela: ");
		int tam = Common.input.nextInt();
		System.out.print("Tamanho da área de reserva da tabela: ");
		int tamReserva = Common.input.nextInt();
		Hash hash = new Hash(tam, tamReserva);
		int opcao, item, pos;
		do {
			System.out.println("\n\tMENU: HASH SIMPLES");
			System.out.println("[1] - inserir um item");
			System.out.println("[2] - inserir vários itens");
			System.out.println("[3] - remover um item específico");
			System.out.println("[4] - remover de uma posição");
			System.out.println("[5] - pesquisar por um item");
			System.out.println("[6] - pesquisar pela posição de um item");
			System.out.println("[7] - mostrar itens da tabela");
			System.out.println("[0] - sair");
			System.out.print("Opção: ");
			opcao = Common.input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser inserido: ");
					item = Common.input.nextInt();
					if (hash.insert(item) >= 0)
						System.out.println("Item inserido com sucesso. ");
					break;
				case 2:
					int cont = 1;
					do {
						System.out.print("Item "+cont+": ");
						cont++;
						item = Common.input.nextInt();
						Common.lista.add(item);
					} while (Common.continuar() != 'n');
					hash.insertList(Common.lista);
					Common.lista.clear();
					break;
				case 3:
					System.out.print("Item a ser removido: ");
					item = Common.input.nextInt();
					pos = hash.remove((Object) item);
					if (pos >= 0) 
						System.out.println("Item removido da posição "+pos);
					else 
						System.out.println("Falha ao remover item.");
					break;
				case 4:
					System.out.print("Posição do item a ser removido: ");
					pos = Common.input.nextInt();
					Object removido = hash.removeFromPosition(pos);
					if (removido != null)
						System.out.println("Item removido: "+(int) removido);
					else 
						System.out.println("Falha ao remover na posição especificada.");
					break;
				case 5:
					System.out.print("Item a ser pesquisado: ");
					item = Common.input.nextInt();
					if (hash.search((Object) item))
						System.out.println("Item encontrado."); 
					else 
						System.out.println("Item não encontrado.");
					break;
				case 6:
					System.out.print("Item a ser pesquisado: ");
					item = Common.input.nextInt();
					pos = hash.searchPos((Object) item);
					if (pos >= 0)
						System.out.println("Item encontrado na posição "+pos); 
					else 
						System.out.println("Item não encontrado.");
					break;
				case 7:
					System.out.println("Itens: ");
					hash.showItens();
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
