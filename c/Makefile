dirs = arvore_avl arvore_binaria fila_dinamica lista_dinamica pilha_dinamica hash_com_lista
nomesDosCompilados = compiladoDinamicos arvoreAvl arvoreBinaria filaDinamica hashComLista listaDinamica pilhaDinamica filaCircular hashSimples hashComLista pilhaEstatica

define setMainAvoid = 
	for dir in $(dirs); do mv $$dir/main.c $$dir/main.avoid; done
endef

define setMainNotAvoid = 
	for dir in $(dirs); do mv $$dir/main.avoid $$dir/main.c; done
endef

all:
	$(call setMainAvoid)
	gcc arvore_avl/*.c arvore_binaria/*.c common/*.c hash_com_lista/*.c menu.c fila_dinamica/*.c lista_dinamica/*.c pilha_dinamica/*.c -Wall -pedantic -o compiladoDinamicos
	$(call setMainNotAvoid)

arvoreBinaria:
	gcc arvore_binaria/*.c -Wall -pedantic -o arvoreBinaria

arvoreAvl:
	gcc arvore_avl/*.c common/*.c -Wall -pedantic -o arvoreAvl

filaDinamica:
	gcc fila_dinamica/*.c common/*.c -Wall -pedantic -o filaDinamica

listaDinamica:
	gcc lista_dinamica/*.c common/*.c -Wall -pedantic -o listaDinamica

pilhaDinamica:
	gcc pilha_dinamica/*.c common/*.c -Wall -pedantic -o pilhaDinamica

hashComLista:
	mv lista_dinamica/main.c lista_dinamica/main.avoid
	gcc hash_com_lista/*.c lista_dinamica/*.c common/*.c -Wall -pedantic -o hashComLista
	mv lista_dinamica/main.avoid lista_dinamica/main.c

dinamicos: arvoreAvl filaDinamica listaDinamica pilhaDinamica hashComLista
	
estaticos: filaCircular hashSimples pilhaEstatica

filaCircular:
	gcc fila_circular/*.c -Wall -pedantic -o filaCircular

hashSimples:
	gcc hash_simples/*.c -Wall -pedantic -o hashSimples

pilhaEstatica:
	gcc pilha_estatica/*.c -Wall -pedantic -o pilhaEstatica

clean:
	for lixo in $$(find . -type f -name ".*~"); do rm $$lixo; done
	for lixo in $$(find . -type f -name ".*.gch"); do rm $$lixo; done
	for binario in $(nomesDosCompilados); do rm $$binario; done
