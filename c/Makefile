dirs = arvore_avl fila_dinamica lista_dinamica pilha_dinamica

define hideAllMain = 
	for dir in $(dirs); do mv $$dir/main.c $$dir/.main.c; done
endef

define showAllMain = 
	for dir in $(dirs); do mv $$dir/.main.c $$dir/main.c; done
endef

all:
	$(call hideAllMain)
	gcc arvore_avl/* common/* menu.c fila_dinamica/* lista_dinamica/* pilha_dinamica/* -Wall -pedantic -o compiladoDinamicos
	$(call showAllMain)

arvoreAvl:
	gcc arvore_avl/* common/* -Wall -pedantic -o arvoreAvl

filaDinamica:
	gcc fila_dinamica/* common/* -Wall -pedantic -o filaDinamica

listaDinamica:
	gcc lista_dinamica/* common/* -Wall -pedantic -o listaDinamica

pilhaDinamica:
	gcc pilha_dinamica/* common/* -Wall -pedantic -o pilhaDinamica

dinamicos: arvoreAvl filaDinamica listaDinamica pilhaDinamica
	
estaticos: filaCircular hashSimples listaSimples

filaCircular:
	gcc tads_estaticas/filaCircular.c -Wall -pedantic -o filaCircular

hashSimples:
	gcc tads_estaticas/hash.c -Wall -pedantic -o hashSimples

listaSimples:
	gcc tads_estaticas/pilha.c -Wall -pedantic -o listaSimples

clean:
	for lixo in $$(find . -type f -name ".*~"); do rm $$lixo; done
	for lixo in $$(find . -type f -name ".*.gch"); do rm $$lixo; done
	rm compiladoDinamicos arvoreAvl filaDinamica hashComLista listaDinamica pilhaDinamica filaCircular hashSimples listaSimples
