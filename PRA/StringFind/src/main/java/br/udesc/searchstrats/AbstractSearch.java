/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.udesc.searchstrats;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author udesc
 */
public abstract class AbstractSearch implements ISearchStrategy {
    
    protected ArrayList<String[]> temp;
    protected String word;
    protected ArrayList<Integer> strSize;
    
    public AbstractSearch(File file, String word){
        temp = new ArrayList<>();
        strSize = new ArrayList<>();
        this.word = word;
        
        BufferedReader read = null;
        String line;
        
        try {
            read = new BufferedReader(new FileReader(file));
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(NaiveSearch.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        try {
            while((line = read.readLine()) != null){
                prepareSearch(line, word);
            }
        } catch (IOException ex) {
            Logger.getLogger(NaiveSearch.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    protected abstract boolean buscar(String word, String other);
    
    @Override
    public void prepareSearch(String text, String word) {
        temp.add(text.split(" "));
        strSize.add(temp.get(temp.size()-1).length);
    }

    @Override
    public ArrayList<WordLocation> search(boolean removeGarb) {
        ArrayList<WordLocation> returner = new ArrayList<>();
        long init = System.currentTimeMillis();
        int l=0;
        int c=0;
        
        // Logica Naive
        for(String[] arr : temp){
            c=0;
            for(int i=0; i<arr.length; i++){
                String txt = arr[i];
                txt = removeGarbage(txt);
                if(buscar(arr[i],word)){
                    long end = System.currentTimeMillis();
                    WordLocation temp = new WordLocation(word);
                    temp.setTime(end-init);
                    temp.setLine(l+1);
                    temp.setColumn(c+1);
                    returner.add(temp);
                    init = System.currentTimeMillis();
                }else{
                    c += arr[i].length();
                }
            }
            l++;
        }
        
        return returner;
    }
    
    private String removeGarbage(String txt){
        txt = txt.replace(",", "");
        txt = txt.replace("[", "");
        txt = txt.replace("]", "");
        txt = txt.replace("(", "");
        txt = txt.replace(")", "");
        txt = txt.replace(".", "");
        txt = txt.replace("!", "");
        txt = txt.replace("?", "");
        return txt;
    }
    
}
