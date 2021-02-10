#include "noAvl.h"

#include <stdlib.h>

No * newNo(int item) {
	No * no = (No *) malloc(sizeof(No));
	no->item = item;
	no->esq = NULL;
	no->dir = NULL;
	no->fator = 0;
	return no;
}
