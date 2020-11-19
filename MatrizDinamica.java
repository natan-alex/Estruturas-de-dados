class Celula {
    public int item;
    public Celula inf, sup, esq, dir;

    public Celula() {
        this(-1,null,null,null,null);
    }

    public Celula(int item, Celula inf, Celula sup, Celula esq, Celula dir) {
        this.item = item;
        this.inf = inf;
        this.sup = sup;
        this.esq = esq;
        this.dir = dir;
    }
}

class MatrizDinamica {
    private Celula inicio;
    private int linhas, colunas;

    public MatrizDinamica(int linhas, int colunas) {
        this.inicio = new Celula();
        this.linhas = linhas;
        this.colunas = colunas;

        Celula tmp = inicio;

        for (int i = 0; i < linhas; i++) {
            tmp.dir = new Celula();
            tmp.dir.esq = tmp;
            tmp = tmp.dir;
        }

        for (int i = 1; i < linhas; i++) {
            tmp = inicio.dir;

            for (int j = 1; j < i; j++)
                tmp = tmp.inf;
            
            tmp.inf = new Celula();
            tmp.inf.sup = tmp;

            for (int j = 1; j < colunas; j++) {
                tmp = tmp.dir;
                Celula tmp2 = tmp.esq.inf;
                tmp2.dir = new Celula();
                tmp2.dir.esq = tmp2;
                tmp2 = tmp2.dir;
                tmp2.sup = tmp;
                tmp.inf = tmp2;
            }
        }
    }

    public void inserirValor(int item, int linha, int coluna) {
        Celula tmp = inicio.dir;

        for (int i = 0; i < linha; i++) 
            tmp = tmp.inf;

        for (int j = 0; j < coluna; j++)
            tmp = tmp.dir;

        tmp.item = item;
    }

    public int removerValor(int linha, int coluna) {
        Celula tmp = inicio.dir;

        for (int i = 0; i < linha; i++) 
            tmp = tmp.inf;

        for (int j = 0; j < coluna; j++)
            tmp = tmp.dir;

        return tmp.item;
    }

    public void mostrarItens() {
        Celula tmp = inicio.dir;

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

    public MatrizDinamica soma(MatrizDinamica m) {
        MatrizDinamica resultado = new MatrizDinamica(this.linhas, this.colunas);

        Celula tmp, tmp2, tmp3;

        for (int i = 0; i < linhas; i++) {
            tmp = inicio.dir;
            tmp2 = m.inicio.dir;
            tmp3 = resultado.inicio.dir;

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

        Celula tmp, tmp2, tmp3;

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

            Celula inicio_tmp = tmp;
            Celula inicio_tmp3 = tmp3;
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

                tmp = inicio_tmp;
                tmp3 = inicio_tmp3;
            }
        }

        return resultado;
    }

    public void mostrarDiagonalPrincipal() {
        Celula tmp = inicio.dir;

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

    public void mostrarDiagonalSecundaria() {
        Celula tmp = inicio.dir;

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

class Main{
    private static int qtdOperacoes = 0;

    public static MatrizDinamica leERetornaMatriz(int linhas, int colunas) {
        MatrizDinamica m = new MatrizDinamica(linhas, colunas);
        for (int i = 0; i < linhas; i++) {
            String s = MyIO.readLine();
            String[] linha = s.split(" ");

            for (int j = 0; j < colunas; j++) {
                m.inserirValor(Integer.parseInt(linha[j]), i, j);
            }
        }

        return m;
    }

    public static void main(String[] args) {
        String s = ""; // para leitura da entrada padrao

        s = MyIO.readLine();

        qtdOperacoes = Integer.parseInt(s);

        for (int i = 0; i < qtdOperacoes; i++) {
            s = MyIO.readLine();
            int linhas = Integer.parseInt(s);
            s = MyIO.readLine();
            int colunas = Integer.parseInt(s);
            MatrizDinamica m1 = leERetornaMatriz(linhas, colunas);
            m1.mostrarDiagonalPrincipal();
            m1.mostrarDiagonalSecundaria();
        
            s = MyIO.readLine();
            linhas = Integer.parseInt(s);
            s = MyIO.readLine();
            colunas = Integer.parseInt(s);

            MatrizDinamica m2 = leERetornaMatriz(linhas, colunas);
            MatrizDinamica resultado = m2.soma(m1);
            resultado.mostrarItens();;

            MatrizDinamica resultado2 = m1.multiplicacao(m2);
            resultado2.mostrarItens();
        }
    }
}
