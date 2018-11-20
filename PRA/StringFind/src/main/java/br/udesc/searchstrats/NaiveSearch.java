package br.udesc.searchstrats;

import java.io.File;

/**
 *
 * @author Guilherme Utiama
 * @author Peter Brendel
 */

public class NaiveSearch extends AbstractSearch {
    
    public NaiveSearch(File file, String word){
        super(file, word);
    }

    @Override
    protected boolean buscar(String text, String word) {
        return text.equals(word);
    }
    
}
