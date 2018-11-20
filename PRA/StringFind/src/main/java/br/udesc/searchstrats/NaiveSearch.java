package br.udesc.searchstrats;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.time.Duration;
import java.time.temporal.Temporal;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

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
