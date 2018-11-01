package br.udesc.searchstrats;

/**
 *
 * @author Guilherme Utiama
 * @author Peter Brendel
 */
public interface ISearchStrategy {
    
    public default void prepareSearch(String text, String word) { 
        /* */
    }
    
    public abstract WordLocation search();
}
