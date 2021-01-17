import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	private static Scanner input = new Scanner(System.in);

	public static void cleanBuffer() {
		String s = "";
		if (input.hasNext()) {
			s = input.nextLine();
		}
	}

	public static char continuar() {
		char opcao;
		do {
			System.out.println("Continuar?");
			System.out.println("[s] - sim");
			System.out.println("[n] - não");
			System.out.print("Opção: ");
			cleanBuffer();
			opcao = input.nextLine().charAt(0);
			opcao = Character.toLowerCase(opcao);
		} while (opcao != 's' && opcao != 'n');
		return opcao;
	}

    public static void main(String[] args) {
		ArvoreBinaria arvore = new ArvoreBinaria();
		List<Integer> lista = new ArrayList<>();
		int opcao;
		int item;
		do {
			System.out.println("MENU");
			System.out.println("[1] - inserir um item");
			System.out.println("[2] - inserir vários itens");
			System.out.println("[3] - remover item da árvore");
			System.out.println("[4] - mostrar em pré ordem");
			System.out.println("[5] - mostrar em ordem crescente");
			System.out.println("[6] - mostrar em pós ordem");
			System.out.println("[7] - mostrar em todas as ordens");
			System.out.println("[0] - sair");
			System.out.print("Opção: ");
			opcao = input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser inserido na árvore: ");
					item = input.nextInt();
					arvore.inserir(item);
					System.out.println("Item inserido.");
					break;
				case 2:
					int cont = 1;
					do {
						System.out.print("Item "+cont+": ");
						cont++;
						item = input.nextInt();
						lista.add(item);
					} while (continuar() != 'n');
					arvore.inserirList(lista);
					lista.clear();
					System.out.println("Itens inseridos.");
					break;
				case 3:
					System.out.print("Item a ser removido: ");
					item = input.nextInt();
					arvore.remover(item);
					System.out.println("Item removido.");
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
				default:
					System.out.println("Opção inválida.");
					break;
			}
		} while (opcao != 0);
    }
}

