dirs = arvore_avl arvore_binaria fila_dinamica lista_dinamica pilha_dinamica
nomesDosCompilados = compiladoDinamicos arvoreAvl arvoreBinaria filaDinamica hashComLista listaDinamica pilhaDinamica filaCircular hashSimples pilhaEstatica

define hideAllMain = 
	for dir in $(dirs); do mv $$dir/main.c $$dir/.main.c; done
endef

define showAllMain = 
	for dir in $(dirs); do mv $$dir/.main.c $$dir/main.c; done
endef

all:
	$(call showAllMain)
	$(call hideAllMain)
	gcc arvore_avl/* arvore_binaria/* common/* menu.c fila_dinamica/* lista_dinamica/* pilha_dinamica/* -Wall -pedantic -o compiladoDinamicos
	$(call showAllMain)

arvoreBinaria:
	gcc arvore_binaria/* -Wall -pedantic -o arvoreBinaria

arvoreAvl:
	gcc arvore_avl/* common/* -Wall -pedantic -o arvoreAvl

filaDinamica:
	gcc fila_dinamica/* common/* -Wall -pedantic -o filaDinamica

listaDinamica:
	gcc lista_dinamica/* common/* -Wall -pedantic -o listaDinamica

pilhaDinamica:
	gcc pilha_dinamica/* common/* -Wall -pedantic -o pilhaDinamica

dinamicos: arvoreAvl filaDinamica listaDinamica pilhaDinamica
	
estaticos: filaCircular hashSimples pilhaEstatica

filaCircular:
	gcc fila_circular/* -Wall -pedantic -o filaCircular

hashSimples:
	gcc hash.c -Wall -pedantic -o hashSimples

pilhaEstatica:
	gcc pilha_estatica/* -Wall -pedantic -o pilhaEstatica

clean:
	for lixo in $$(find . -type f -name ".*~"); do rm $$lixo; done
	for lixo in $$(find . -type f -name ".*.gch"); do rm $$lixo; done
	for binario in $(nomesDosCompilados); do rm $$binario; done
