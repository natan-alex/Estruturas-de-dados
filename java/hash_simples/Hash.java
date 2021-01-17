package hash_simples;

import java.util.List;

public class Hash {
    public  int tableSize;
    public  int overflowSize;
    private int realsize;
    private int posOverflow; // control insertions on overflow area
    public  Object htable[]; // make easy to substitute the type of the table

    public Hash() {
        this(10, 10);
    }

    public Hash(int tableSize, int overflowSize) {
		// if the size is invalid, both will 
		// have the value of 10
		if (isSizeValid(tableSize))
			this.tableSize = tableSize;
		else {
			System.out.println("Tamanho de área principal inválido. Assumindo o valor 10.");
			this.tableSize = 10;
		}

		if (isSizeValid(overflowSize))
			this.overflowSize = overflowSize;
		else {
			System.out.println("Tamanho de área reserva inválido. Assumindo o valor 10.");
			this.overflowSize = 10;
		}

        realsize = tableSize + overflowSize;
        posOverflow = 0;
        htable = new Object[realsize];

        for (int i = 0; i < realsize; i++) 
            htable[i] = null;
    }

	private boolean isSizeValid(int size) {
		return (size > 0);
	}

    private int hash(Object item) {
        // change the key with whatever you want
        return ((int)item % tableSize);
    }

    // return the position where item has been inserted
    public int insert(Object item) {
        int pInsertion = hash(item); 
        int posReturn = -1; 
        // if the position is free
        if (htable[pInsertion] == null) {
            htable[pInsertion] = item;
            posReturn = pInsertion;
        } else {
            if (posOverflow < (realsize - tableSize)) {
                htable[tableSize + posOverflow] = item;
                posReturn = tableSize + posOverflow;
                posOverflow++;
            } else {
                System.out.println("Área de reserva cheia! Falha ao inserir "+(int)item);
            }
        }
        return posReturn;
    }

	public void insertList(List<Integer> lista) {
		for (int item : lista) 
			insert((Object) item);
	}

    // return the position of the removed element
    // -1 if not found
    public int remove(Object toBeRemoved) {
        int pos = -1;
        int pRemotion = hash(toBeRemoved);
        // found in the main area
        if (htable[pRemotion] != null && ((int)htable[pRemotion] == (int)toBeRemoved)) {
            pos = pRemotion;
            boolean hasSubstitute = false;
            // change the item in the main area
            // with the item in the overflow area
            // with the same hash 
            for (int i = 0; i < posOverflow && !hasSubstitute; i++) {
                if (hash(htable[i + tableSize]) == pRemotion) {
                    hasSubstitute = true;
                    htable[pRemotion] = htable[i + tableSize];
                    if (posOverflow > 0) 
                        posOverflow--;
                    htable[i + tableSize] = htable[tableSize + posOverflow];
                    htable[tableSize + posOverflow] = null;
                }
            }
			if (!hasSubstitute)
				htable[pRemotion] = null;
        } else {
            // not found in main area -> search in the overflow area
            for (int i = 0; i < posOverflow; i++) {
                if ((int)htable[i + tableSize] == (int)toBeRemoved) {
                    pos = i + tableSize;
                    if (posOverflow > 0)
                        posOverflow--;
                    htable[i + tableSize] = htable[posOverflow];
                    htable[posOverflow] = null;
                    i = posOverflow;
                }
            }
        }
        return pos;
    }

    // return the removed item
    // null if not found or if the key is invalid
    public Object remove(int key) {
        if (key < 0 || key >= realsize) {
            System.out.println("Chave de remoção inválida.");
            return null;
        }
        Object removed = null;
		// if there is something in the position
        if (htable[key] != null) {
            removed = htable[key];
            boolean hasSubstitute = false;
            // again, put in the main area
            // the item with the same hash coming
            // from the overflow area
            for (int i = 0; i < posOverflow && !hasSubstitute; i++) {
                if (hash(htable[i + tableSize]) == key) {
                    hasSubstitute = true;
                    htable[key] = htable[i + tableSize];
                    if (posOverflow > 0) 
                        posOverflow--;
                    htable[i + tableSize] = htable[posOverflow];
                    htable[posOverflow] = null;
                }
            }
			if (!hasSubstitute)
				htable[key] = null;
        }
        return removed;
    }

    public void showItens() {
        System.out.println("\nÁrea principal: [");
        for (int i = 0; i < tableSize; i++) {
            if (htable[i] != null)
                System.out.println("    Índice "+i+":  "+(int)htable[i]);
            else
                System.out.println("    Índice "+i+":  vazio");
        }
        System.out.println("]\n");
        System.out.println("Área de reserva: [");
        for (int i = 0; i < (realsize - overflowSize); i++) {
            if (htable[i + tableSize] != null)
				System.out.print("    Índice "+(i+tableSize)+":  "+(int)htable[tableSize + i] + "\n");
            else
                System.out.println("    Índice "+(i+tableSize)+":  vazio");
        }
        System.out.println("]\n");
    }

    public boolean search(Object obj) {
        boolean retorno = false;
        if (obj == null) {
            System.out.println("Objeto inválido.");
        } else {
            int hashJ = hash(obj);
            if (htable[hashJ] != null && ((int)htable[hashJ] == (int)obj)) {
                retorno = true;
            } else {
                // searching on overflow 
                for (int i = 0; i < posOverflow && !retorno; i++) {
                    if (htable[i + tableSize] != null && ((int)htable[i + tableSize] == (int)obj)) {
                        retorno = true;
					}
                }
            }
        }
        return retorno;
    }

    // return the position of the item
    // -1 if not found
    public int searchPos(Object obj) {
        int pos = -1;
        if (obj == null) {
            System.out.println("Objeto inválido.");
        } else {
            int hashJ = hash(obj);
            if (htable[hashJ] != null && ((int)htable[hashJ] == (int)obj)) {
                pos = hashJ;
            } else {
                // searching in overflow area
                for (int i = 0; i < posOverflow && (pos == -1); i++) {
                    if (htable[i + tableSize] != null && ((int)htable[i + tableSize] == (int)obj)) {
                        pos = i + tableSize;
                    }
                }
            }
        }
        return pos;
    }
}
