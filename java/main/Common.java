package main;

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

public class Common {
	public static Scanner input = new Scanner(System.in);;
	public static List<Integer> lista = new ArrayList<>(); 

	public static char continuar() {
		char opcao;
		do {
			System.out.println("Continuar?");
			System.out.println("[s ou 1] - sim");
			System.out.println("[n ou 2] - não");
			System.out.print("Opção: ");
			opcao = input.next().charAt(0);
			opcao = Character.toLowerCase(opcao);
		} while (opcao != 's' && opcao != 'n' && opcao != '1' && opcao != '2');
		if (opcao == '1')
			opcao = 's';
		else if (opcao == '2')
			opcao = 'n';
		return opcao;
	}
}
