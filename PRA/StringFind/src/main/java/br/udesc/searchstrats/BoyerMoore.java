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
 * @author peter
 */
public class BoyerMoore implements ISearchStrategy {
    
    private ArrayList<String[]> temp;
    private String word;
    private ArrayList<Integer> strSize;
    private int[] right;
    
    public BoyerMoore(File file, String word){
        temp = new ArrayList<>();
        strSize = new ArrayList<>();
        this.word = word;
        right = new int[256];
        for(int i=0; i < 256; i++){
            right[i] = -1;
        }
        for(int i=0; i < word.length(); i++){
            right[word.charAt(i)] = i;
        }
        
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
    
    private boolean buscar(String txt, String padrao){
        int m = padrao.length();
        int n = txt.length();
        int skip;
        
        for(int i=0; i<=n-m ; i += skip){
            skip = 0;
            for(int j = m-1; j>=0; j--){
                if(padrao.charAt(j) != txt.charAt(i+j)){
                    skip = Math.max(1, j-this.right[txt.charAt(i+j)]);
                    break;
                }
            }
            if(skip == 0) return true;
        }
        return false;
    }
    
    @Override
    public void prepareSearch(String text, String word){
        temp.add(text.split(" "));
        strSize.add(temp.get(temp.size()-1).length);
    }
    
    @Override
    public ArrayList<WordLocation> search() {
        ArrayList<WordLocation> returner = new ArrayList<>();
        long init = System.currentTimeMillis();
        int l=0;
        int c=0;
        
        // Logica Naive
        for(String[] arr : temp){
            c=0;
            for(int i=0; i<arr.length; i++){
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

    private boolean possible(int string, int word) {
        return string == word;
    }
    
}
