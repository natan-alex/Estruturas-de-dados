all: 
	gcc arvore_avl/* common/* fila_dinamica/* hash_com_lista/* lista_dinamica/* pilha_dinamica/* menu.c -o dinamicos
	gcc tads_estaticas/filaCircular.c -o filaCircular
	gcc tads_estaticas/hash.c -o hashEstatico
	gcc tads_estaticas/pilha.c -o pilhaEstatica

dinamicos:
	gcc arvore_avl/* common/* fila_dinamica/* hash_com_lista/* lista_dinamica/* pilha_dinamica/* menu.c -o exec

fila_circular:
	gcc tads_estaticas/filaCircular.c -o exec

hash_simples:
	gcc tads_estaticas/hash.c -o exec

lista_simples:
	gcc tads_estaticas/pilha.c -o exec

clean:
	rm exec dinamicos filaCircular hashEstatico pilhaEstatica
