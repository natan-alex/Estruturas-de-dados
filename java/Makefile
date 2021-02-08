all: 
	javac */*.java
	java main.Main

arvoreAvl:
	javac arvore_avl/*.java main/*.java
	java main.Main arvore_avl

arvoreBinaria:
	javac arvore_binaria/*.java main/*.java
	java main.Main arvore_binaria

filaDinamica:
	javac fila_dinamica/*.java main/*.java
	java main.Main fila

hashSimples:
	javac hash_simples/*.java main/*.java
	java main.Main hash

listaDinamica:
	javac lista_dinamica/*.java main/*.java
	java main.Main lista

matrizDinamica:
	javac matriz_dinamica/*.java main/*.java
	java main.Main matriz

pilhaDinamica:
	javac pilha_dinamica/*.java main/*.java
	java main.Main pilha

jarForDinamicos:
	for class in $$(find . -type f -name '*.class'); do rm $$class; done
	javac */*.java
	jar cfm EstruturasDinamicas.jar manifest.txt */*.class
	java -jar EstruturasDinamicas.jar

clean: 
	for class in $$(find . -type f -name '*.class'); do rm $$class; done
	rm *.jar
