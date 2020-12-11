class No {
    public No esq, dir;
    public int item;

    public No() {
        this(-1, null, null);
    }

    public No(int item, No esq, No dir) {
        this.item = item;
        this.esq = esq;
        this.dir = dir;
    }
}

class ArvoreBinaria {
    private No raiz;

    public ArvoreBinaria() {
        raiz = null;
    }

    public boolean isVazia() {
        return (raiz == null);
    }

    public void inserir(int item) {
        raiz = inserir(item, raiz);
    }

    private No inserir(int item, No noAtual) {
        if (noAtual == null) {
            noAtual = new No(item, null, null);
        } else if (item > noAtual.item) {
            noAtual.dir = inserir(item, noAtual.dir);
        } else if (item < noAtual.item) {
            noAtual.esq = inserir(item, noAtual.esq);
        } else {
            System.out.println("Elemento "+item+" já inserido na árvore");
            return null;
        }
        return noAtual;
    }

    public void inserirV2(int item) {
        inserirV2(item, raiz, null);
    }

    // estabelece conexão com nó depois da sua 
    // criação por meio do pai
    private void inserirV2(int item, No noAtual, No ultimoNo) {
        if (noAtual == null) {
            noAtual = new No(item, null, null);
            if (raiz == null) {
                raiz = noAtual;
                return;
            }
            if (item < ultimoNo.item) {
                ultimoNo.esq = noAtual;
            } else {
                ultimoNo.dir = noAtual;
            }
        } else if (item < noAtual.item) {
            inserirV2(item, noAtual.esq, noAtual);
        } else if (item > noAtual.item) {
            inserirV2(item, noAtual.dir, noAtual);
        } else {
            System.out.println("Elemento "+item+" já inserido na árvore.");
            return;
        }
    }

    public void remover(int item) {
        raiz = remover(item, raiz);
    }

    private No remover(int item, No noAtual) {
        if (noAtual == null) {
            System.out.println("Item não encontrado na árvore");
            return null;
        } else if (item < noAtual.item) {
            noAtual.esq = remover(item, noAtual.esq);
        } else if (item > noAtual.item) {
            noAtual.dir = remover(item, noAtual.dir);
        } else if (noAtual.dir == null) {
            noAtual = noAtual.esq;
        } else if (noAtual.esq == null) {
            noAtual = noAtual.dir;
        } else {
            noAtual.esq = trocaPorMaiorDaEsquerda(noAtual, noAtual.esq);
        }
        return noAtual;
    }

    private No trocaPorMaiorDaEsquerda(No aSerRemovido, No noAtual) {
        if (noAtual.dir != null) {
            noAtual.dir = trocaPorMaiorDaEsquerda(aSerRemovido, noAtual.dir);
        } else {
            aSerRemovido.item = noAtual.item;
            noAtual = noAtual.esq;
        }
        return noAtual;
    }

    public void mostrarPreOrdem() {
        System.out.print("[ ");
        mostrarPreOrdem(raiz);
        System.out.println("]");
    }

    private void mostrarPreOrdem(No noAtual) {
        if (noAtual != null) {
            System.out.print(noAtual.item+" ");
            mostrarPreOrdem(noAtual.esq);
            mostrarPreOrdem(noAtual.dir);
        }
    }

    public void mostrarEmOrdemCrescente() {
        System.out.print("[ ");
        mostrarEmOrdemCrescente(raiz);
        System.out.println("]");
    }

    private void mostrarEmOrdemCrescente(No noAtual) {
        if (noAtual != null) {
            mostrarEmOrdemCrescente(noAtual.esq);
            System.out.print(noAtual.item+" ");
            mostrarEmOrdemCrescente(noAtual.dir);
        }
    }

    public void mostrarPosOrdem() {
        System.out.print("[ ");
        mostrarPosOrdem(raiz);
        System.out.println("]");
    }

    private void mostrarPosOrdem(No noAtual) {
        if (noAtual != null) {
            mostrarPosOrdem(noAtual.esq);
            mostrarPosOrdem(noAtual.dir);
            System.out.print(noAtual.item+" ");
        }
    }
}

class Main {
    public static void main(String[] args) {
        ArvoreBinaria ab = new ArvoreBinaria();

        ab.inserir(10);
        ab.inserir(3);
        ab.inserir(5);
        ab.inserir(1);
        ab.inserir(11);
        ab.inserir(9);
        ab.inserir(8);

        System.out.println("PRE-ORDEM: ");
        ab.mostrarPreOrdem();
        System.out.println("EM-ORDEM: ");
        ab.mostrarEmOrdemCrescente();
        System.out.println("POS-ORDEM: ");
        ab.mostrarPosOrdem();

        ab.remover(10);

        System.out.println("PRE-ORDEM: ");
        ab.mostrarPreOrdem();
        System.out.println("EM-ORDEM: ");
        ab.mostrarEmOrdemCrescente();
        System.out.println("POS-ORDEM: ");
        ab.mostrarPosOrdem();
    }
}
