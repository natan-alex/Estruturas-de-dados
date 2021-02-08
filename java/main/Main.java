package main;

import arvore_binaria.ArvoreBinaria;
import arvore_binaria.MenuArvoreBinaria;
import arvore_avl.ArvoreAvl;
import arvore_avl.MenuAvl;
import hash_simples.Hash;
import hash_simples.MenuHash;
import fila_dinamica.MenuFila;
import fila_dinamica.FilaDinamica;
import lista_dinamica.ListaDinamica;
import lista_dinamica.MenuLista;
import pilha_dinamica.PilhaDinamica;
import pilha_dinamica.MenuPilha;
import matriz_dinamica.MatrizDinamica;
import matriz_dinamica.MenuMatriz;

public class Main {
    public static void main(String[] args) {
		if (args.length == 0) {
			System.out.println("Necessário passar um argumento ao programa.");
			System.out.println("Argumentos possíveis: (Todas as estruturas abaixo são flexíveis)");
			System.out.println("  * arvore_binaria");
			System.out.println("  * arvore_avl");
			System.out.println("  * fila");
			System.out.println("  * hash");
			System.out.println("  * lista");
			System.out.println("  * matriz");
			System.out.println("  * pilha");
		} else {
			MenuInterface menuClass = null; 
			if (args[0].equals("arvore_binaria")) {
				menuClass = new MenuArvoreBinaria();
			} else if (args[0].equals("arvore_avl")) {
				menuClass = new MenuAvl();
			} else if (args[0].equals("hash")) {
				menuClass = new MenuHash();
			} else if (args[0].equals("matriz")) {
				menuClass = new MenuMatriz();
			} else if (args[0].equals("pilha")) {
				menuClass = new MenuPilha();
			} else if (args[0].equals("fila")) {
				menuClass = new MenuFila();
			} else if (args[0].equals("lista")) {
				menuClass = new MenuLista();
			} else {
				System.out.println("Argumento inválido.");
			}
			if (menuClass != null)
				menuClass.menu();
			menuClass = null;
		}
		Common.finalizar();
    }
}
