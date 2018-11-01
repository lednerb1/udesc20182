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

public class NaiveSearch implements ISearchStrategy {
    
    private ArrayList<String[]> temp;
    private String word;
    private ArrayList<Integer> strSize;
    
    public NaiveSearch(File file, String word){
        temp = new ArrayList<>();
        strSize = new ArrayList<>();
        this.word = word;
        BufferedReader read = null;
        String line;
        int i=0;
        
        try {
            read = new BufferedReader(new FileReader(file));
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(NaiveSearch.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        try {
            while((line = read.readLine()) != null){
                prepareSearch(line, word);
                i++;
            }
        } catch (IOException ex) {
            Logger.getLogger(NaiveSearch.class.getName()).log(Level.SEVERE, null, ex);
        }
               
    }
    
    @Override
    public void prepareSearch(String text, String word){
        temp.add(text.split(" "));
        strSize.add(temp.get(temp.size()-1).length);
    }
    
    @Override
    public WordLocation search() {
        WordLocation returner = new WordLocation(word);
        
        long init = System.currentTimeMillis();
        int l=0;
        int c=0;
        // Logica Naive
        for(String[] arr : temp){
            c=0;
            for(int i=0; i<arr.length; i++){
                if(arr[i].equals(word)){
                    long end = System.currentTimeMillis();
                    returner.setTime(init-end);
                    returner.setLine(l);
                    returner.setColumn(c+2);
                }else{
                    c += arr[i].length();
                }
            }
            l++;
        }
        
        if(returner.getTime() == 0){
            return null;
        }
        
        return returner;
    }

    private boolean possible(int string, int word) {
        return string == word;
    }
    
}
