package main;

import arvore_binaria.ArvoreBinaria;
import arvore_binaria.MenuArvoreBinaria;
import hash_simples.Hash;
import hash_simples.MenuHash;
import fila_dinamica.MenuFila;
import fila_dinamica.FilaDinamica;
import pilha_dinamica.PilhaDinamica;
import pilha_dinamica.MenuPilha;
import matriz_dinamica.MatrizDinamica;
import matriz_dinamica.MenuMatriz;

public class Main {
    public static void main(String[] args) {
		if (args.length == 0) {
			System.out.println("Necessário passar um argumento ao programa.");
			System.out.println("Argumentos possíveis:");
			System.out.println("  * arvore");
			System.out.println("  * fila");
			System.out.println("  * hash");
			System.out.println("  * matriz");
			System.out.println("  * pilha");
		} else {
			if (args[0].equals("arvore")) {
				MenuArvoreBinaria.menu();
			} else if (args[0].equals("hash")) {
				MenuHash.menu();
			} else if (args[0].equals("matriz")) {
				MenuMatriz.menu();
			} else if (args[0].equals("pilha")) {
				MenuPilha.menu();
			} else if (args[0].equals("fila")) {
				MenuFila.menu();
			}
		}
    }
}

