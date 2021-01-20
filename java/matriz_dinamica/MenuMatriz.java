package matriz_dinamica;

import main.Common;

public class MenuMatriz {
	public static MatrizDinamica construirNovaMatriz(int linhas, int colunas) {
		MatrizDinamica matriz = new MatrizDinamica(linhas, colunas);
		int item;
		for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				System.out.print("Item ["+i+"-"+j+"] da matriz: ");
				item = Common.input.nextInt();
				matriz.inserirValor(item, i, j);
			}
		}
		return matriz;
	}

	public static void menu() {
		System.out.print("Número de linhas da matriz: ");
		int linhas = Common.input.nextInt();
		System.out.print("Número de colunas da matriz: ");
		int colunas = Common.input.nextInt();
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
			opcao = Common.input.nextInt();
			switch(opcao) {
				case 1:
					System.out.print("Item a ser inserido: ");
					item = Common.input.nextInt();
					System.out.print("Linha: ");
					linha = Common.input.nextInt();
					System.out.print("Coluna: ");
					coluna = Common.input.nextInt();
					if (matriz.inserirValor(item, linha, coluna))
						System.out.println("Item inserido com sucesso. ");
					break;
				case 2:
					System.out.print("Item a ser removido: ");
					item = Common.input.nextInt();
					if (matriz.removerValor(item))
						System.out.println("Item removido com sucesso.");
					else 
						System.out.println("Falha ao remover item.");
					break;
				case 3:
					System.out.println("Posição do item a ser removido: ");
					System.out.print("Linha: ");
					linha = Common.input.nextInt();
					System.out.print("Coluna: ");
					coluna = Common.input.nextInt();
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
					coluna = Common.input.nextInt();
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
}
