#ifndef HASH_SIMPLES_H
#define HASH_SIMPLES_H

typedef struct Hash {
	int tableSize;
	int overflowSize;
	int realSize;
	int posOverflow; // control insertions in overflow area
	int ** tabela;
} Hash;

Hash * newHash(int tamTable, int tamOverflow);

int hash(Hash * th, int key);

int inserir(Hash * th, int item);

int removerPos(Hash * th, int key);

int removerItem(Hash * th, int item);

void mostrar(Hash * th);

void desalocarTabela(Hash * th);

#endif
