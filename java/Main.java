import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;

import arvore_binaria.ArvoreBinaria;
import hash_simples.Hash;
import pilha_dinamica.PilhaDinamica;
import matriz_dinamica.MatrizDinamica;

public class Main {
	private static Scanner input;
	private static List<Integer> lista; 

	public static char continuar() {
		char opcao;
		do {
			System.out.println("Continuar?");
			System.out.println("[s ou 1] - sim");
			System.out.println("[n ou 2] - não");
			System.out.print("Opção: ");
			opcao = input.next().charAt(0);
			opcao = Character.toLowerCase(opcao);
		} while (opcao != 's' && opcao != 'n' && opcao != '1' && opcao != '2');
		if (opcao == '1')
			opcao = 's';
		else if (opcao == '2')
			opcao = 'n';
		return opcao;
	}


	public static MatrizDinamica construirNovaMatriz(int linhas, int colunas) {
		MatrizDinamica matriz = new MatrizDinamica(linhas, colunas);
		int item;
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				System.out.print("Item ["+i+"-"+j+"] da matriz: ");
				item = input.nextInt();
				matriz.inserirValor(item, i, j);
			}
		}
		return matriz;
	}

	public static void menuArvore() {
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

	public static void menuHash() {
		System.out.print("Tamanho da área principal da tabela: ");
		int tam = input.nextInt();
		System.out.print("Tamanho da área de reserva da tabela: ");
		int tamReserva = input.nextInt();
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
			opcao = input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser inserido: ");
					item = input.nextInt();
					if (hash.insert(item) >= 0)
						System.out.println("Item inserido com sucesso. ");
					break;
				case 2:
					int cont = 1;
					do {
						System.out.print("Item "+cont+": ");
						cont++;
						item = input.nextInt();
						lista.add(item);
					} while (continuar() != 'n');
					hash.insertList(lista);
					lista.clear();
					break;
				case 3:
					System.out.print("Item a ser removido: ");
					item = input.nextInt();
					pos = hash.remove((Object) item);
					if (pos >= 0) 
						System.out.println("Item removido da posição "+pos);
					else 
						System.out.println("Falha ao remover item.");
					break;
				case 4:
					System.out.print("Posição do item a ser removido: ");
					pos = input.nextInt();
					Object removido = hash.removeFromPosition(pos);
					if (removido != null)
						System.out.println("Item removido: "+(int) removido);
					else 
						System.out.println("Falha ao remover na posição especificada.");
					break;
				case 5:
					System.out.print("Item a ser pesquisado: ");
					item = input.nextInt();
					if (hash.search((Object) item))
						System.out.println("Item encontrado."); 
					else 
						System.out.println("Item não encontrado.");
					break;
				case 6:
					System.out.print("Item a ser pesquisado: ");
					item = input.nextInt();
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


	public static void menuMatriz() {
		System.out.print("Número de linhas da matriz: ");
		int linhas = input.nextInt();
		System.out.print("Número de colunas da matriz: ");
		int colunas = input.nextInt();
		MatrizDinamica matriz = new MatrizDinamica(linhas, colunas);
		int opcao, item, pos, linha, coluna;
		do {
			System.out.println("\n\tMENU: MATRIZ DINAMICA");
			System.out.println("[1] - inserir um item");
			System.out.println("[2] - remover um item");
			System.out.println("[3] - remover de uma posição");
			System.out.println("[4] - mostrar diagonal principal da matriz");
			System.out.println("[5] - mostrar diagonal secundária da matriz");
			System.out.println("[6] - mostrar itens da matriz");
			System.out.println("[7] - somar matrizes");
			System.out.println("[8] - multiplicar matrizes");
			System.out.println("[0] - sair");
			System.out.print("Opção: ");
			opcao = input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser inserido: ");
					item = input.nextInt();
					System.out.print("Linha: ");
					linha = input.nextInt();
					System.out.print("Coluna: ");
					coluna = input.nextInt();
					if (matriz.inserirValor(item, linha, coluna))
						System.out.println("Item inserido com sucesso. ");
					break;
				case 2:
					System.out.print("Item a ser removido: ");
					item = input.nextInt();
					if (matriz.removerValor(item))
						System.out.println("Item removido com sucesso.");
					else 
						System.out.println("Falha ao remover item.");
					break;
				case 3:
					System.out.println("Posição do item a ser removido: ");
					System.out.print("Linha: ");
					linha = input.nextInt();
					System.out.print("Coluna: ");
					coluna = input.nextInt();
					item = matriz.removerDaPosicao(linha, coluna);
					if (item != Integer.MIN_VALUE)
						System.out.println("Item removido: "+item);
					break;
				case 4:
					matriz.mostrarDiagonalPrincipal();
					break;
				case 5:
					matriz.mostrarDiagonalSecundaria();
					break;
				case 6:
					matriz.mostrarItens();
					break;
				case 7:
					matriz.somarMatrizes(construirNovaMatriz(linhas, colunas)).mostrarItens();
					break;
				case 8:
					System.out.print("Número de colunas da matriz a ser multiplicada: ");
					coluna = input.nextInt();
					matriz.multiplicarMatrizes(construirNovaMatriz(colunas, coluna)).mostrarItens();
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

	public static void menuPilha() {
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

    public static void main(String[] args) {
		input = new Scanner(System.in);
		lista = new ArrayList<>();

		if (args.length == 0) {
			System.out.println("Necessário passar um argumento ao programa.");
			System.out.println("Argumentos possíveis:");
			System.out.println("  * arvore");
			System.out.println("  * hash");
			System.out.println("  * matriz");
			System.out.println("  * pilha");
		} else {
			if (args[0].equals("arvore")) {
				menuArvore();
			} else if (args[0].equals("hash")) {
				menuHash();
			} else if (args[0].equals("matriz")) {
				menuMatriz();
			} else if (args[0].equals("pilha")) {
				menuPilha();
			}
		}
    }
}

