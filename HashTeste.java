import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedWriter;
import java.io.BufferedReader;
import java.io.IOException;

class Jogador {
    private int id;
    private String nome;
    public  int altura;
    private int peso;
    private String universidade;
    private String anoNascimento;
    private String cidadeNascimento;
    private String estadoNascimento;

    public Jogador() {
        this(-1, "", -1, -1, "", "", "", "");
    }

    public Jogador(int id, String nome, int altura, int peso, String univ, String anoNasc, String cidadeNasc, String estadoNasc) {
        this.id = id;
        this.nome = nome;
        this.altura = altura;
        this.peso = peso;
        this.universidade = univ;
        this.anoNascimento = anoNasc;
        this.cidadeNascimento = cidadeNasc;
        this.estadoNascimento = estadoNasc;
    }

    // getters e setters
    public int getId() {
        return this.id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getAltura() {
        return this.altura;
    }

    public void setAltura(int altura) {
        this.altura = altura;
    }

    public int getPeso() {
        return this.peso;
    }

    public void setPeso(int peso) {
        this.peso = peso;
    }

    public String getUniv() {
        return this.universidade;
    }

    public void setUniv(String univ) {
        this.universidade = univ;
    }

    public String getAnoNasc() {
        return this.anoNascimento;
    }

    public void setAnoNasc(String ano) {
        this.anoNascimento = ano;
    }

    public String getCidade() {
        return this.cidadeNascimento;
    }

    public void setCidade(String cidade) {
        this.cidadeNascimento = cidade;
    }

    public String getEstado() {
        return this.estadoNascimento;
    }

    public void setEstado(String estado) {
        this.estadoNascimento = estado;
    }

    public Jogador clone () {
        Jogador j = new Jogador();

        j.setId(this.id);
        j.setNome(this.nome);
        j.setAltura(this.altura);
        j.setPeso(this.peso);
        j.setUniv(this.universidade);
        j.setAnoNasc(this.anoNascimento);
        j.setEstado(this.estadoNascimento);
        j.setCidade(this.cidadeNascimento);

        return j;
    }

    // insere infos nos atributos da classe
    public void montarJogador (String infos) {
        //quebrar a string
        String[] partes = infos.split(",");

        int n = partes.length; //tamanho do vetor

        //atribuicao aos atributos
        //id
        setId(Integer.parseInt(partes[0]));
        //nome
        setNome(partes[1]);
        //altura
        setAltura(Integer.parseInt(partes[2]));
        //peso
        setPeso(Integer.parseInt(partes[3]));
        //ano nascimento
        setAnoNasc(partes[5]);
        //universidade
        //checar se é nulo ou não
        if (n > 5) {
            if (partes[4].length() > 0) {
                setUniv(partes[4]);
            } else {
                setUniv("nao informado");
            }
        }
        //cidade e estado
        //se tamanho de partes == 6: cidade e estado nulos
        //se tamanho == 7: estado nao definido
        //se tamanho == 8: todos
        if (n == 6) {
            setCidade("nao informado");
            setEstado("nao informado");
        } else if (n == 7) {
            setCidade(partes[6]);
            setEstado("nao informado");
        } else if (n == 8) {
            setCidade(partes[6]);
            setEstado(partes[7]);
        }
    }

    // impressao formatada das informacoes do jogador
    public void imprimir() {
        System.out.print("[");
        System.out.print(getId());
        System.out.print(" ## ");
        System.out.print(getNome());
        System.out.print(" ## ");
        System.out.print(getAltura());
        System.out.print(" ## ");
        System.out.print(getPeso());
        System.out.print(" ## ");
        System.out.print(getAnoNasc());
        System.out.print(" ## ");
        System.out.print(getUniv());
        System.out.print(" ## ");
        System.out.print(getCidade());
        System.out.print(" ## ");
        System.out.print(getEstado());
        System.out.println("]");
    }
}

class Hash {
    public  int tableSize;
    public  int overflowSize;
    private int realsize;
    private int posOverflow; // control insertions on overflow area
    public  Jogador htable[]; // make easy to substitute the type of the table

    public Hash() {
        this(10, 10);
    }

    public Hash(int tableSize, int overflowSize) {
        this.tableSize = tableSize;
        this.overflowSize = overflowSize;
        this.realsize = tableSize + overflowSize;
        this.posOverflow = 0;
        this.htable = new Jogador[realsize];
        for (int i = 0; i < realsize; i++) 
            htable[i] = null;
    }

    public int hash(Jogador item) {
        return (item.altura % tableSize);
    }

    // return the position where item has been inserted
    public int insert(Jogador item) {
        int pInsertion = hash(item);
        int posReturn = -1;
        if (htable[pInsertion] == null) {
            htable[pInsertion] = item.clone();
            posReturn = pInsertion;
        } else {
            if (posOverflow < tableSize) {
                htable[tableSize + posOverflow] = item.clone();
                posReturn = tableSize + posOverflow;
                posOverflow++;
            } else {
                System.out.print("Área de reserva cheia! Falha ao inserir ");
                item.imprimir();
            }
        }
        return posReturn;
    }

    // return the position of the removed element
    // -1 if not found
    public int remove(Jogador toBeRemoved) {
        int pos = -1;
        int pRemotion = hash(toBeRemoved);
        if (htable[pRemotion].equals(toBeRemoved)) {
            pos = pRemotion;
            boolean hasSubstitute = false;
            for (int i = 0; i < posOverflow && !hasSubstitute; i++) {
                if (hash(htable[i + tableSize]) == pRemotion) {
                    hasSubstitute = true;
                    htable[pRemotion] = htable[i + tableSize].clone();
                    if (posOverflow > 0) 
                        posOverflow--;
                    htable[i + tableSize] = htable[tableSize + posOverflow].clone();
                    htable[tableSize + posOverflow] = null;
                }
            }
        } else {
            for (int i = 0; i < posOverflow; i++) {
                if (htable[i + tableSize].equals(toBeRemoved)) {
                    pos = i + tableSize;
                    if (posOverflow > 0)
                        posOverflow--;
                    htable[i + tableSize] = htable[posOverflow].clone();
                    htable[posOverflow] = null;
                    i = posOverflow;
                }
            }
        }
        return pos;
    }

    // return the removed item
    // null if not found
    public Jogador remove(int key) {
        if (key < 0 || key >= realsize) {
            System.out.println("Chave de remocao invalida.");
            return null;
        }

        Jogador removed = null;
        if (htable[key] != null) {
            removed = htable[key].clone();
            boolean hasSubstitute = false;
            for (int i = 0; i < posOverflow && !hasSubstitute; i++) {
                if (hash(htable[i + tableSize]) == key) {
                    hasSubstitute = true;
                    htable[key] = htable[i + tableSize].clone();
                    if (posOverflow > 0) 
                        posOverflow--;
                    htable[i + tableSize] = htable[posOverflow].clone();
                    htable[posOverflow] = null;
                }
            }
        }
        return removed;
    }

    public void showItens() {
        System.out.println("\nÁrea principal: [");
        for (int i = 0; i < tableSize; i++) {
            System.out.print("\t");
            if (htable[i] != null) 
                htable[i].imprimir();
            else
                System.out.println("null");
        }
        System.out.println("]\n");
        System.out.println("Área de reserva: [");
        for (int i = 0; i < posOverflow; i++) {
            System.out.print("\t");
            htable[tableSize + i].imprimir();
        }
        System.out.println("]\n");
    }
}

class HashTeste {
    private static Jogador[] jogadores = new Jogador[3922]; // vetor para os jogadores do arquivo

    public static void preencherVetJogadores () throws IOException {
        BufferedReader br = new BufferedReader( new FileReader("/tmp/players.csv"));
        // primeira linha do arquivo contem somente o nome das colunas
        String linha = br.readLine();

        // ids sequenciais
        for (int i=0; i<3922; i++) {
            jogadores[i] = new Jogador();
            linha = br.readLine();

            jogadores[i].montarJogador(linha);
        }

        br.close();
    }

    public static void main(String[] args) {
        try{
            preencherVetJogadores();
        } catch (IOException e) {} 

        Hash thash = new Hash();
        
        for (int i = 0; i < 20; i++)
            thash.insert(jogadores[i]);

        thash.showItens();
    }
}
