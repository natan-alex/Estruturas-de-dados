package arvore_avl;

public class ArvoreAvl {
	private NoAvl raiz;
	private boolean insercaoFeita; // diz sobre o sucesso
	// das inserções na árvore
	private boolean remocaoFeita; // diz sobre o sucesso
	// das remoções na árvore

	public ArvoreAvl() {
		raiz = null;
	}

	public boolean isAvlVazia() {
		return raiz == null;
	}

	private NoAvl realizarRotacaoSimplesAEsquerda(NoAvl no) {
		NoAvl noDir = no.dir;
		NoAvl noDirEsq = noDir.esq;
		no.dir = noDirEsq;
		noDir.esq = no;

		atualizarFatorDoNo(no);
		atualizarFatorDoNo(noDir);

		return noDir;
	}

	private NoAvl realizarRotacaoSimplesADireita(NoAvl no) {
		NoAvl noEsq = no.esq;
		NoAvl noEsqDir = noEsq.dir;
		no.esq = noEsqDir;
		noEsq.dir = no;

		atualizarFatorDoNo(no);
		atualizarFatorDoNo(noEsq);

		return noEsq;
	}

	private NoAvl realizarRotacaoDuplaAEsquerda(NoAvl no) {
		no.esq = realizarRotacaoSimplesAEsquerda(no.esq);
		return realizarRotacaoSimplesADireita(no);
	}

	private NoAvl realizarRotacaoDuplaADireita(NoAvl no) {
		no.dir = realizarRotacaoSimplesADireita(no.dir);
		return realizarRotacaoSimplesAEsquerda(no);
	}

	private static int getMaior(int n1, int n2) {
		return (n1 <= n2) ? n2 : n1;		
	}

	private static int getFatorDoNo(NoAvl no) {
		return (no == null) ? 0 : no.fator;
	}

	// fator do nó recebe o maior entre os fatores
	// da esquerda e direita -> o que faz com que os fatores
	// sejam armazenados em módulo
	public void atualizarFatorDoNo(NoAvl no) {
		no.fator = 1 + getMaior(getFatorDoNo(no.esq), getFatorDoNo(no.dir)); 
	}

	// cálculo é feito com fator do nó a esquerda
	// menos o fator do nó a direita
	private static int calcularFatorDoNo(NoAvl no) {
		int fatorEsq = getFatorDoNo(no.esq);
		int fatorDir = getFatorDoNo(no.dir);
		return fatorEsq - fatorDir;
	}

	// retorna o nó balanceado fazendo as devidas rotações
	private NoAvl balancearNo(NoAvl no) {
		if (no != null) {
			atualizarFatorDoNo(no);
			int fatorDoNo = calcularFatorDoNo(no);
			if (fatorDoNo == -2) {
				// nó mais pesado a direita
				if (calcularFatorDoNo(no.dir) == 1) {
					no = realizarRotacaoDuplaADireita(no);
				} else {
					no = realizarRotacaoSimplesAEsquerda(no);
				}
			} else if (fatorDoNo == 2) {
				// nó mais pesado a esquerda
				if (calcularFatorDoNo(no.esq) == -1) {
					no = realizarRotacaoDuplaAEsquerda(no);
				} else {
					no = realizarRotacaoSimplesADireita(no);
				}
			}
		}
		return no;
	}

	public boolean inserirItemNaAvl(int item) {
		insercaoFeita = false;
		raiz = inserirItemNaAvl(item, raiz);	
		return insercaoFeita;
	}

	private NoAvl inserirItemNaAvl(int item, NoAvl no) {
		if (no == null) {
			// encontrado o local de inserção
			no = new NoAvl(item);
			insercaoFeita = true;
		} else if (no.item < item) {
			// procura deve continuar a direita
			no.dir = inserirItemNaAvl(item, no.dir);
			// balanceamento é feito a cada recursão
			// de volta ao nó raiz, ou seja, de baixo pra 
			// cima na árvore
			no = balancearNo(no);
		} else if (no.item > item) {
			no.esq = inserirItemNaAvl(item, no.esq);
			no = balancearNo(no);
		} else {
			// item igual ao item do nó
			System.out.println("Item "+item+" já inserido na árvore.");
		}
		return no;
	}

	public boolean removerItemDaAvl(int item) {
		remocaoFeita = false;
		raiz = removerItemDaAvl(item, raiz);
		return remocaoFeita;
	}

	private NoAvl removerItemDaAvl(int item, NoAvl no) {
		if (no == null) {
			System.out.println("404 - Item não encontrado.");
		} else if (no.item > item) {
			// procura deve continuar a esquerda
			no.esq = removerItemDaAvl(item, no.esq);
			remocaoFeita = true;
		} else if (no.item < item) {
			// procura deve continuar a direita
			no.dir = removerItemDaAvl(item, no.dir);
			remocaoFeita = true;
		} else if (no.esq == null) {
			// em caso de no.dir == null, o nó 
			// recebe null, portanto tudo certo
			no = no.dir;
			remocaoFeita = true;
		} else if (no.dir == null) {
			no = no.esq;
			remocaoFeita = true;
		} else {
			// nó a ser removido receberá o maior item
			// da subárvore a sua esquerda
			NoAvl tmp = no.esq, paiTmp = no;
			if (tmp.dir != null) {
				tmp = tmp.dir;
				paiTmp = paiTmp.esq;
			}
			// caminhar até o maior nó
			for (; tmp.dir != null; tmp = tmp.dir, paiTmp = paiTmp.dir);

			no.item = tmp.item;
			if (paiTmp == no) {
				// tmp == no.esq, ou seja, não havia 
				// nenhum nó a direita de tmp
				no.esq = tmp.esq;
			} else {
				paiTmp.dir = tmp.esq;
			}
			paiTmp = null;
			tmp = null;
			remocaoFeita = true;
		}
		return balancearNo(no);
	}
	
	public boolean pesquisarPorItemNaAvl(int item) {
		return pesquisarPorItemNaAvl(item, raiz);	
	}

	private boolean pesquisarPorItemNaAvl(int item, NoAvl no) {
		boolean encontrado;

		if (no == null) {
			encontrado = false;
		} else if (no.item < item) {
			// procura deve continuar a direita
			encontrado = pesquisarPorItemNaAvl(item, no.dir);
		} else if (no.item > item) {
			encontrado = pesquisarPorItemNaAvl(item, no.esq);
		} else {
			encontrado = true;
		}

		return encontrado;
	}
	
	public void mostrarAvlEmPreOrdem() {
		System.out.print("Pré-ordem: [ ");
		mostrarAvlEmPreOrdem(raiz);
		System.out.println("]");
	}

	private void mostrarAvlEmPreOrdem(NoAvl no) {
		if (no != null) {
			System.out.print(no.item+" ");
			mostrarAvlEmPreOrdem(no.esq);
			mostrarAvlEmPreOrdem(no.dir);
		}
	}

	public void mostrarAvlEmOrdem() {
		System.out.print("Em-ordem: [ ");
		mostrarAvlEmOrdem(raiz);
		System.out.println("]");
	}

	private void mostrarAvlEmOrdem(NoAvl no) {
		if (no != null) {
			mostrarAvlEmOrdem(no.esq);
			System.out.print(no.item+" ");
			mostrarAvlEmOrdem(no.dir);
		}
	}

	public void mostrarAvlEmPosOrdem() {
		System.out.print("Pós-ordem: [ ");
		mostrarAvlEmPosOrdem(raiz);
		System.out.println("]");
	}

	private void mostrarAvlEmPosOrdem(NoAvl no) {
		if (no != null) {
			mostrarAvlEmPosOrdem(no.esq);
			mostrarAvlEmPreOrdem(no.dir);
			System.out.print(no.item+" ");
		}
	}

	public void mostrarEmTodasAsOrdens() {
		System.out.println("");
		mostrarAvlEmPreOrdem();
		mostrarAvlEmOrdem();
		mostrarAvlEmPosOrdem();
	}
}
