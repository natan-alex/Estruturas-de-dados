#ifndef NO_BST_H
#define NO_BST_H

typedef struct NoBST {
	int item;
	struct NoBST * esq, * dir;
} NoBST;

NoBST * newNoBST(int item); 

#endif
