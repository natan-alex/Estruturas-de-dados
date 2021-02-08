package fila_dinamica;

import main.Common;
import main.MenuInterface;

public class MenuFila implements MenuInterface {
	@Override
	public void menu() {
		FilaDinamica fila = new FilaDinamica();
		int opcao;
		int item;
		do {
			System.out.println("\n\tMENU: FILA DINAMICA");
			System.out.println("[1] - enfileirar um item");
			System.out.println("[2] - enfileirar vários itens");
			System.out.println("[3] - desenfileirar");
			System.out.println("[4] - mostrar itens da fila");
			System.out.println("[0] - sair");
			System.out.print("Opção: ");
			opcao = Common.input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser enfileirado: ");
					item = Common.input.nextInt();
					fila.enfileirar(item);
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
					fila.enfileirarList(Common.lista);
					Common.lista.clear();
					System.out.println("Itens inseridos.");
					break;
				case 3:
					item = fila.desenfileirar();
					if (item != Integer.MIN_VALUE)
						System.out.println("Item desenfileirado: "+fila.desenfileirar());
					break;
				case 4:
					System.out.println("Itens: ");
					fila.mostrarFila();
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
