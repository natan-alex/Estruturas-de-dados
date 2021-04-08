package arvore_red_black;

class Pessoa {
	String nome;
	int idade;

	public Pessoa(String nome, int idade) {
		this.nome = nome;
		this.idade = idade;
	}

	public int compareTo(Pessoa p) {
		return nome.compareTo(p.nome);
	}

	public String toString() {
		return "Pessoa [nome=" + nome + ", idade=" + idade + "]";
	}
}

public class RBTree<T extends Comparable<T>> {
	public static void main(String[] args) {
		RBNode<Pessoa> node = new RBNode<Pessoa>( new Pessoa("a", 10) );
		node.color = RBNode.RED;
		System.out.println(node);
	}
}
