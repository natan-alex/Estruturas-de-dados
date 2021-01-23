#include <stdio.h>
#include "sobreOpcoes.h"

int lerOpcao() {
	int opcao;
	scanf("%d", &opcao);
	return opcao;
}

int tratarOpcao(int opcao, int limiteInferior, int limiteSuperior) {
	while (opcao < limiteInferior || opcao > limiteSuperior) {
		printf("Opção inválida, tente novamente.\n");
		printf("Nova opção: ");
		opcao = lerOpcao();
	}
	return opcao;
}
