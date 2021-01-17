import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

class Main {
	private static Scanner input = new Scanner(System.in);

	// public static void cleanBuffer() {
	// 	String s = "";
	// 	if (input.hasNext()) {
	// 		s = input.nextLine();
	// 	}
	// }

	public static char continuar() {
		char opcao;
		do {
			System.out.println("Continuar?");
			System.out.println("[s] - sim");
			System.out.println("[n] - não");
			System.out.print("Opção: ");
			opcao = input.next().charAt(0);
			opcao = Character.toLowerCase(opcao);
		} while (opcao != 's' && opcao != 'n');
		return opcao;
	}

    public static void main(String[] args) {
		PilhaDinamica pilha = new PilhaDinamica();
		List<Integer> lista = new ArrayList<>();
		int opcao;
		int item;
		do {
			System.out.println("MENU");
			System.out.println("[1] - empilhar um item");
			System.out.println("[2] - empilhar vários itens");
			System.out.println("[3] - desempilhar");
			System.out.println("[4] - mostrar itens da pilha");
			System.out.println("[0] - sair");
			System.out.print("Opção: ");
			opcao = input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser empilhado: ");
					item = input.nextInt();
					pilha.empilhar(item);
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
					pilha.empilharList(lista);
					lista.clear();
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

