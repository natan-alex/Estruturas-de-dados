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

	public boolean isArvoreVazia() {
		return raiz == null;
	}

	// ===========================================================

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

	// ===========================================================

	private static int getMaior(int n1, int n2) {
		return (n1 <= n2) ? n2 : n1;		
	}

	private static int getFatorDoNo(NoAvl no) {
		return (no == null) ? 0 : 1 + no.fator;
	}

	// fator do nó recebe o maior entre os fatores
	// da esquerda e direita -> o que faz com que os fatores
	// sejam armazenados em módulo
	public void atualizarFatorDoNo(NoAvl no) {
		no.fator = getMaior(getFatorDoNo(no.esq), getFatorDoNo(no.dir)); 
	}

	// cálculo é feito com fator do nó a esquerda
	// menos o fator do nó a direita
	private static int calcularFatorDoNo(NoAvl no) {
		return getFatorDoNo(no.esq) - getFatorDoNo(no.dir);
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

	// ===========================================================

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

	// ===========================================================

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
		} else if (no.item < item) {
			// procura deve continuar a direita
			no.dir = removerItemDaAvl(item, no.dir);
		} else if (no.esq == null) {
			// em caso de no.dir == null, o nó 
			// recebe null, portanto tudo certo
			no = no.dir;
			remocaoFeita = true;
		} else if (no.dir == null) {
			no = no.esq;
			remocaoFeita = true;
		} else {
			NoAvl tmp = no.esq, paiTmp = no;
			// paiTmp deve andar primeiramente a esquerda
			if (tmp.dir != null) {
				paiTmp = no.esq;
				tmp = tmp.dir;
			}
			for (; tmp.dir != null; tmp = tmp.dir, paiTmp = paiTmp.dir);
			no.item = tmp.item;
			if (paiTmp == no) {
				// nada a direita de tmp
				no.esq = tmp.esq;
			} else {
				paiTmp.dir = tmp.esq;
				atualizarFatorDoNo(paiTmp);
			}
			paiTmp = null;
			tmp = null;
			remocaoFeita = true;
		}
		return balancearNo(no);
	}

	// ===========================================================
	
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

	private NoAvl obterInformacoesDoNo(NoAvl no, int item) {
		NoAvl result;
		if (no == null) {
			result = null;
		} else if (item == no.item) {
			result = no;
		} else if (item > no.item) {
			result = obterInformacoesDoNo(no.dir, item);
		} else {
			result = obterInformacoesDoNo(no.esq, item);
		}
		return result;
	}

	public void obterInformacoesDoNo(int item) {
		NoAvl result = obterInformacoesDoNo(raiz, item);
		if (result != null) {
			System.out.println("Item encontrado!\n");
			System.out.println("Informações sobre o nó que contém o item:");
			System.out.println("Fator: "+calcularFatorDoNo(result));
			System.out.print("Nó a esquerda: ");
			if (result.esq == null) 
				System.out.println("(Não possui)");
			else 
				System.out.println(result.esq.item);
			System.out.print("Nó a direita: ");
			if (result.dir == null) 
				System.out.println("(Não possui)\n");
			else 
				System.out.println(result.dir.item);
		} else {
			System.out.println("Item não encontrado.\n");
		}
	}
	
	// ===========================================================
	
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

	// ===========================================================
	
	public int contarNosDaArvore() {
		return contarNosDaArvore(raiz);
	}

	public int contarNosDaArvore(NoAvl no) {
		return (no == null) ? 0 : 1 + contarNosDaArvore(no.esq) + contarNosDaArvore(no.dir);
	}

	// ===========================================================
	
	public void desalocarArvoreDaMemoria() {
		desalocarArvoreDaMemoria(raiz);
	}

	public void desalocarArvoreDaMemoria(NoAvl no) {
		if (no != null) {
			desalocarArvoreDaMemoria(no.esq);
			desalocarArvoreDaMemoria(no.dir);
			no.esq = null;
			no.dir = null;
		}
	}
}
