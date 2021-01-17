#!/bin/bash

clean() {
	rm *.class
}

if [ $# -eq 0 ]; then
	echo "Nenhum parâmetro passado, nada a compilar."
	echo "Parâmetros possíveis:"
	echo "arvore, ArvoreBinaria"
	echo "hash, Hash"
	echo "matriz, Matriz"
	echo "pilha, Pilha, PilhaDinamica"
	echo "limpar, Limpar, clean"
else
	if [ $1 == "arvore" ] || [ $1 == "ArvoreBinaria" ]; then
		javac -d . arvore_binaria/*.java
		java Main
	elif [ $1 == "hash" ] || [ $1 == "Hash" ]; then
		javac -d . hash/*.java
		java Main
	elif [ $1 == "matriz" ] || [ $1 == "Matriz" ]; then
		javac -d . matriz_dinamica/*.java
		java Main
	elif [ $1 == "pilha" ] || [ $1 == "Pilha" ] || [ $1 == "PilhaDinamica" ]; then
		javac -d . pilha_dinamica/*.java
		java Main
	elif [ $1 == "limpar" ] || [ $1 == "Limpar" ] || [ $1 == "clean" ]; then
		clean
	fi
fi

