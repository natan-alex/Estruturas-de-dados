class Hash {
    public  int tableSize;
    public  int overflowSize;
    private int realsize;
    private int posOverflow; // control insertions on overflow area
    public  Object htable[]; // make easy to substitute the type of the table

    public Hash() {
        this(10, 10);
    }

    public Hash(int tableSize, int overflowSize) {
        this.tableSize = tableSize;
        this.overflowSize = overflowSize;
        this.realsize = tableSize + overflowSize;
        this.posOverflow = 0;
        this.htable = new Object[realsize];
        for (int i = 0; i < realsize; i++) 
            htable[i] = null;
    }

    public int hash(Object item) {
        return (item.key % tableSize);
    }

    // return the position where item has been inserted
    public int insert(Object item) {
        int pInsertion = hash(item);
        int posReturn = -1;
        if (htable[pInsertion] == null) {
            htable[pInsertion] = item.clone();
            posReturn = pInsertion;
        } else {
            if (posOverflow < tableSize) {
                htable[tableSize + posOverflow] = item.clone();
                posReturn = tableSize + posOverflow;
                posOverflow++;
            } else {
                System.out.print("Área de reserva cheia! Falha ao inserir ");
                item.imprimir();
            }
        }
        return posReturn;
    }

    // return the position of the removed element
    // -1 if not found
    public int remove(Object toBeRemoved) {
        int pos = -1;
        int pRemotion = hash(toBeRemoved);
        if (htable[pRemotion].equals(toBeRemoved)) {
            pos = pRemotion;
            boolean hasSubstitute = false;
            for (int i = 0; i < posOverflow && !hasSubstitute; i++) {
                if (hash(htable[i + tableSize]) == pRemotion) {
                    hasSubstitute = true;
                    htable[pRemotion] = htable[i + tableSize].clone();
                    if (posOverflow > 0) 
                        posOverflow--;
                    htable[i + tableSize] = htable[tableSize + posOverflow].clone();
                    htable[tableSize + posOverflow] = null;
                }
            }
        } else {
            for (int i = 0; i < posOverflow; i++) {
                if (htable[i + tableSize].equals(toBeRemoved)) {
                    pos = i + tableSize;
                    if (posOverflow > 0)
                        posOverflow--;
                    htable[i + tableSize] = htable[posOverflow].clone();
                    htable[posOverflow] = null;
                    i = posOverflow;
                }
            }
        }
        return pos;
    }

    // return the removed item
    // null if not found
    public Object remove(int key) {
        if (key < 0 || key >= realsize) {
            System.out.println("Chave de remocao invalida.");
            return null;
        }

        Object removed = null;
        if (htable[key] != null) {
            removed = htable[key].clone();
            boolean hasSubstitute = false;
            for (int i = 0; i < posOverflow && !hasSubstitute; i++) {
                if (hash(htable[i + tableSize]) == key) {
                    hasSubstitute = true;
                    htable[key] = htable[i + tableSize].clone();
                    if (posOverflow > 0) 
                        posOverflow--;
                    htable[i + tableSize] = htable[posOverflow].clone();
                    htable[posOverflow] = null;
                }
            }
        }
        return removed;
    }

    public void showItens() {
        System.out.println("\nÁrea principal: [");
        for (int i = 0; i < tableSize; i++) {
            System.out.print("\t");
            if (htable[i] != null) 
                htable[i].imprimir();
            else
                System.out.println("null");
        }
        System.out.println("]\n");
        System.out.println("Área de reserva: [");
        for (int i = 0; i < posOverflow; i++) {
            System.out.print("\t");
            htable[tableSize + i].imprimir();
        }
        System.out.println("]\n");
    }
}
