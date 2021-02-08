package pilha_dinamica;

import main.Common;
import main.MenuInterface;

public class MenuPilha implements MenuInterface {
	@Override	
	public void menu() {
		PilhaDinamica pilha = new PilhaDinamica();
		int opcao;
		int item;
		do {
			System.out.println("\n\tMENU: PILHA DINAMICA");
			System.out.println("[1] - empilhar um item");
			System.out.println("[2] - empilhar vários itens");
			System.out.println("[3] - desempilhar");
			System.out.println("[4] - mostrar itens da pilha");
			System.out.println("[0] - sair");
			System.out.print("Opção: ");
			opcao = Common.input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser empilhado: ");
					item = Common.input.nextInt();
					pilha.empilhar(item);
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
					pilha.empilharList(Common.lista);
					Common.lista.clear();
					System.out.println("Itens inseridos.");
					break;
				case 3:
					System.out.println("Item desempilhado: "+pilha.desempilhar());
					break;
				case 4:
					System.out.println("Itens: ");
					pilha.mostrarPilha();
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
