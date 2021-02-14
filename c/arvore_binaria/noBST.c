#include <stdlib.h>

#include "noBST.h"

NoBST * newNoBST(int item) {
	NoBST * no = (NoBST *) malloc(sizeof(NoBST));
	no->item = item;
	no->esq = NULL;
	no->dir = NULL;
	return no;
}
