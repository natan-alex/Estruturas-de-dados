#ifndef NO_AVL_H
#define NO_AVL_H

typedef struct No {
	int item;
	struct No * esq, * dir;
	int fator;
} No;

No * newNo(int item); 

#endif
