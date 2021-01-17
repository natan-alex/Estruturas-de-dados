package matriz_dinamica;

public class MatrizDinamica {
    private CelulaMatriz inicio;
    private int linhas, colunas;

    public MatrizDinamica(int linhas, int colunas) {
        this.inicio = new CelulaMatriz();
        this.linhas = linhas;
        this.colunas = colunas;

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

    public boolean isColunaELinhaValida(int linha, int coluna) {
        if (linha < this.linhas) 
            if (coluna < this.colunas)
                return true;
        return false;
    }

    // varre linhas, depois colunas ate o local de insercao
    public void inserirValor(int item, int linha, int coluna) {
        if (!isColunaELinhaValida(linha, coluna)) {
            System.out.println("Falha ao inserir valor "+item+" em ["+linha+", "+coluna+"] -> Valores de linha ou coluna inválidos.");
            return;
        }

        CelulaMatriz tmp = inicio.dir;

        for (int i = 0; i < linha; i++) 
            tmp = tmp.inf;

        for (int j = 0; j < coluna; j++)
            tmp = tmp.dir;

        tmp.item = item;
    }

    public int removerValor(int linha, int coluna) {
        if (!isColunaELinhaValida(linha, coluna)) {
            System.out.println("Falha na remocao do valor em ["+linha+", "+coluna+"] -> Valores de linha ou coluna inválidos.");
            return -1;
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
                System.out.print(tmp.item+" ");
                tmp = tmp.dir;
            }
            System.out.println();
        }
    }

    // linhas e colunas caminham juntas, tanto da matriz resultado quanto 
    // das matrizes a serem somadas
    public MatrizDinamica soma(MatrizDinamica m) {
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

    public MatrizDinamica multiplicacao(MatrizDinamica m) {
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

        for (int i = 0; i < linhas; i++) {
            tmp = inicio.dir;
            for (int j = 0; j < i; j++)
                tmp = tmp.inf;
            for (int j = 0; j < colunas; j++) {
                if (i == j)
                    System.out.print(tmp.item+" ");
                tmp = tmp.dir;
            }
        }
        System.out.println();
    }

    // tendo em vista que 0 é a primeira posição
    // da linha e da coluna, elemento da diagonal 
    // secundaria ocorre quando i + j == linhas - 1
    public void mostrarDiagonalSecundaria() {
        CelulaMatriz tmp = inicio.dir;

        for (int i = 0; i < linhas; i++) {
            tmp = inicio.dir;
            for (int j = 0; j < i; j++)
                tmp = tmp.inf;
            for (int j = 0; j < colunas; j++) {
                if ((i + j) == (linhas - 1))
                    System.out.print(tmp.item+" ");
                tmp = tmp.dir;
            }
        }
        System.out.println();
    }
}
