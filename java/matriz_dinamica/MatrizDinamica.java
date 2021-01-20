package matriz_dinamica;

import java.util.List;

public class MatrizDinamica {
    private CelulaMatriz inicio;
    private int linhas, colunas;

    public MatrizDinamica(int linhas, int colunas) {
        this.inicio = new CelulaMatriz();
		if (!isSizeValid(linhas)) {
			System.out.println("Número de linhas inválido, assumindo valor 5.");
			this.linhas = 5;
		} else {
			this.linhas = linhas;
		}

		if (!isSizeValid(linhas)) {
			System.out.println("Número de colunas inválido, assumindo valor 5.");
			this.colunas = 5;
		} else {
			this.colunas = colunas;
		}

        CelulaMatriz tmp = inicio;

        // primeira linha da matriz
        for (int i = 0; i < colunas; i++) {
            tmp.dir = new CelulaMatriz();
            tmp.dir.esq = tmp;
            tmp = tmp.dir;
        }

        // linhas restantes
        for (int i = 1; i < linhas; i++) {
            tmp = inicio.dir;

            for (int j = 1; j < i; j++)
                tmp = tmp.inf;
            
            tmp.inf = new CelulaMatriz();
            tmp.inf.sup = tmp;

            // conexao em "grade"
            for (int j = 1; j < colunas; j++) {
                tmp = tmp.dir;
                CelulaMatriz tmp2 = tmp.esq.inf;
                tmp2.dir = new CelulaMatriz();
                tmp2.dir.esq = tmp2;
                tmp2 = tmp2.dir;
                tmp2.sup = tmp;
                tmp.inf = tmp2;
            }
        }
    }

	private boolean isSizeValid(int size) {
		return (size > 0);
	}

    private boolean isColunaELinhaValida(int linha, int coluna) {
        if (linha < this.linhas) 
            if (coluna < this.colunas)
                return true;
        return false;
    }

    // varre linhas, depois colunas ate o local de insercao
    public boolean inserirValor(int item, int linha, int coluna) {
		boolean result = false;
        if (!isColunaELinhaValida(linha, coluna)) {
            System.out.println("Falha ao inserir valor "+item+" em ["+linha+", "+coluna+"] -> Valores de linha ou coluna inválidos.");
        } else {
			CelulaMatriz tmp = inicio.dir;

			for (int i = 0; i < linha; i++) 
				tmp = tmp.inf;

			for (int j = 0; j < coluna; j++)
				tmp = tmp.dir;

			tmp.item = item;
			
			result = true;
		}
		return result;
    }

    public boolean removerValor(int valor) {
        CelulaMatriz tmp = inicio.dir;
		CelulaMatriz tmp2 = tmp.inf;

        for (int i = 0; i < linhas; i++) {
			for (int j = 0; j < colunas; j++) {
				if (tmp.item == valor) {
					tmp.item = Integer.MIN_VALUE;
					return true;
				}
				tmp = tmp.dir;
			}
            tmp = tmp2;
			tmp2 = tmp2.inf;
		}
		return false;
    }

    public int removerDaPosicao(int linha, int coluna) {
        if (!isColunaELinhaValida(linha, coluna)) {
            System.out.println("Falha na remocao do valor em ["+linha+", "+coluna+"] -> Valores de linha ou coluna inválidos.");
            return Integer.MIN_VALUE;
        }

        CelulaMatriz tmp = inicio.dir;

        for (int i = 0; i < linha; i++) 
            tmp = tmp.inf;

        for (int j = 0; j < coluna; j++)
            tmp = tmp.dir;

        return tmp.item;
    }

    public void mostrarItens() {
        CelulaMatriz tmp = inicio.dir;

        for (int i = 0; i < linhas; i++) {
            tmp = inicio.dir;
            for (int j = 0; j < i; j++)
                tmp = tmp.inf;
            for (int j = 0; j < colunas; j++) {
				if (tmp.item == Integer.MIN_VALUE)
					System.out.print("(vazio)\t");
				else
					System.out.print(tmp.item+"\t");
                tmp = tmp.dir;
            }
            System.out.println();
        }
    }

    // linhas e colunas caminham juntas, tanto da matriz resultado quanto 
    // das matrizes a serem somadas
    public MatrizDinamica somarMatrizes(MatrizDinamica m) {
        MatrizDinamica resultado = new MatrizDinamica(this.linhas, this.colunas);

        CelulaMatriz tmp, tmp2, tmp3;

        for (int i = 0; i < linhas; i++) {
            tmp = inicio.dir;
            tmp2 = m.inicio.dir;
            tmp3 = resultado.inicio.dir;

            // descer o numero de linhas necessarias a 
            // partir do inicio
            for (int j = 0; j < i; j++) {
                tmp = tmp.inf;
                tmp2 = tmp2.inf;
                tmp3 = tmp3.inf;
            }

            for (int j = 0; j < colunas; j++) {
                tmp3.item = tmp.item + tmp2.item;
                tmp = tmp.dir;
                tmp2 = tmp2.dir;
                tmp3 = tmp3.dir;
            }
        }

        return resultado;
    }

    public MatrizDinamica multiplicarMatrizes(MatrizDinamica m) {
        MatrizDinamica resultado = new MatrizDinamica(linhas, m.colunas);

        CelulaMatriz tmp, tmp2, tmp3;

        // System.out.println("this: ");
        // this.mostrarItens();
        // System.out.println("m: ");
        // m.mostrarItens();
        for (int k = 0; k < linhas; k++) {
            tmp = inicio.dir;
            tmp3 = resultado.inicio.dir;

            for (int i = 0; i < k; i++) {
                // System.out.println("Descendo tmp e tmp3");
                tmp = tmp.inf;
                tmp3 = tmp3.inf;
            }

            // guardar o posicao de inicio dos ponteiros, 
            // o inicio de cada linha
            CelulaMatriz inicio_tmp = tmp;
            CelulaMatriz inicio_tmp3 = tmp3;
            for (int i = 0; i < m.colunas; i++) {
                tmp2 = m.inicio.dir;

                for (int j = 0; j < i; j++) {
                    tmp2 = tmp2.dir;
                    tmp3 = tmp3.dir;
                }

                tmp3.item = 0;
                for (int j = 0; j < colunas; j++) {
                    // System.out.println("tmp.item: "+tmp.item);
                    // System.out.println("tmp2.item: "+tmp2.item);
                    tmp3.item += tmp2.item * tmp.item;
                    // System.out.println("tmp3.item: "+tmp3.item);
                    tmp = tmp.dir;
                    tmp2 = tmp2.inf;
                }

                // voltar ao inicio enquanto i < m.colunas
                tmp = inicio_tmp;
                tmp3 = inicio_tmp3;
            }
        }

        return resultado;
    }

    // elemento da diagonal principal: quando i == j
    public void mostrarDiagonalPrincipal() {
        CelulaMatriz tmp = inicio.dir;
		int cont = 0;
		String linha = "";

        for (int i = 0; i < linhas; i++) {
			cont = 0;
			linha = "";
			while (cont < i) {
				linha += "\t";
				cont++;
			}
            tmp = inicio.dir;
            for (int j = 0; j < i; j++)
                tmp = tmp.inf;
            for (int j = 0; j < colunas; j++) {
                if (i == j) {
					if (tmp.item == Integer.MIN_VALUE)
						linha += "(vazio)\t";
					else
						linha += tmp.item+"\t";
				}
                tmp = tmp.dir;
            }
			System.out.println(linha);
        }
    }

    // tendo em vista que 0 é a primeira posição
    // da linha e da coluna, elemento da diagonal 
    // secundaria ocorre quando i + j == linhas - 1
    public void mostrarDiagonalSecundaria() {
        CelulaMatriz tmp = inicio.dir;
		int cont = 0;
		String linha = "";

        for (int i = 0; i < linhas; i++) {
			cont = colunas-1;
			linha = "";
			while (cont > i) {
				linha += "\t";
				cont--;
			}
            tmp = inicio.dir;
            for (int j = 0; j < i; j++)
                tmp = tmp.inf;
            for (int j = 0; j < colunas; j++) {
                if ((i + j) == (linhas - 1)) {
					if (tmp.item == Integer.MIN_VALUE)
						linha += "(vazio)\t";
					else
						linha += ""+tmp.item;
				}
                tmp = tmp.dir;
            }
			System.out.println(linha);
        }
    }
}
