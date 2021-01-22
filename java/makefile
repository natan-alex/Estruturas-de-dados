define clean() =
	for class in $(find . -type f -name '*.class'); do rm $class; done
endef

all: 
	javac */*.java
	java main.Main

arvore_binaria:
	javac arvore_binaria/*.java main/*.java
	java main.Main arvore

fila_dinamica:
	javac fila_dinamica/*.java main/*.java
	java main.Main fila

hash_simples:
	javac hash_simples/*.java main/*.java
	java main.Main hash

lista_dinamica:
	javac lista_dinamica/*.java main/*.java
	java main.Main lista

matriz_dinamica:
	javac matriz_dinamica/*.java main/*.java
	java main.Main matriz

pilha_dinamica:
	javac pilha_dinamica/*.java main/*.java
	java main.Main pilha

clean: ; $(value clean())
