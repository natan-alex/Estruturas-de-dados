class Celula {
    public int item;
    public Celula prox;

    public Celula() {
        this(-1, null);
    }

    public Celula(int item, Celula prox) {
        this.item = item;
        this.prox = prox;
    }
}

class Stack{
    private int qtd;
    private Celula topo;
    
    public Stack() {
        qtd = 0;
        topo = null;
    }

    public void empilhar(int e) {
        Celula tmp = new Celula(e, topo);
        topo = tmp;
        tmp = null;
        qtd++;
    }

    public int desempilhar() {
        int retorno = topo.item;
        Celula tmp = topo;
        topo = topo.prox;
        tmp.prox = null;
        tmp = null;
        qtd--;
        return retorno;
    }

    public void mostrarPilha() {
        for (Celula c = topo; c != null; c = c.prox) 
            System.out.println("|\t"+c.item+"\t|");
        System.out.println();
    }
}

class PilhaDinamica {
    public static void main(String[] args) {
        Stack p = new Stack();

        p.empilhar(10);
        p.empilhar(2);
        p.empilhar(30);
        p.mostrarPilha();
        System.out.println(p.desempilhar());
        p.mostrarPilha();
    }
}
