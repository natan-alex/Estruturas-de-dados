define clean_gch = 
	for gch in $(find . -type f -name "*.gch"); do rm $gch; done
endef

define clean_til = 
	for til in $(find . -type f -name ".*~"); do rm $til; done
endef

all: dinamicos estaticos

dinamicos: 
	gcc arvore_avl/* common/* menus/* fila_dinamica/* lista_dinamica/* pilha_dinamica/* hash_com_lista/* -o dinamicos
	
estaticos: 
	gcc tads_estaticas/filaCircular.c -o filaCircular
	gcc tads_estaticas/hash.c -o hashSimples
	gcc tads_estaticas/pilha.c -o listaSimples

fila_circular:
	gcc tads_estaticas/filaCircular.c -o filaCircular

hash_simples:
	gcc tads_estaticas/hash.c -o hashSimples

lista_simples:
	gcc tads_estaticas/pilha.c -o listaSimples

clean:
	$(value clean_gch)
	$(value clean_til)
	rm dinamicos filaCircular hashSimples listaSimples
