package br.udesc.searchstrats;

import java.util.ArrayList;

/**
 *
 * @author Guilherme Utiama
 * @author Peter Brendel
 */
public interface ISearchStrategy {
    
    public default void prepareSearch(String text, String word) { 
        /* */
    }
    
    public abstract ArrayList<WordLocation> search(boolean removeGarb);
}
