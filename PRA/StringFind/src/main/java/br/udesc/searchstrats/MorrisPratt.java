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
public class MorrisPratt implements ISearchStrategy {

    private ArrayList<String[]> temp;
    private String word;
    private ArrayList<Integer> strSize;
    

    
    public MorrisPratt(File file, String word) {
        temp = new ArrayList<>();
        strSize = new ArrayList<>();
        this.word = word;
        BufferedReader read = null;
        String line;
        int i=0;
        
        try {
            read = new BufferedReader(new FileReader(file));
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(MorrisPratt.class.getName()).log(Level.SEVERE, null, ex);
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
        System.out.println("chegando");
        System.out.println(txt + " x " + padrao);
        int m = 0;
        int i = 0;
        int txtSize = txt.length();
        int padSize = padrao.length();
        
        if(txtSize != padSize){
            System.out.println("voltano1");
            return false;
        }
        
        int[] table = new int[padSize+1];
        table[0] = 0;
        
        i=1;
        int j=0;
        while(i<padSize){
            System.out.println("tabelando");
            if(padrao.charAt(i) == padrao.charAt(j)){
                table[i] = j+1;
                i++;
                j++;
            }else if(j>0){
                j = table[j-1];
            }else {
                table[i] = 0;
                i++;
            }
        }
        System.out.println("vazano");
        i=0;
        while((m + i) < txtSize){
            System.out.println(m + " : " + i);
            if(padrao.charAt(i) == txt.charAt(m+i)){
                if(i == (padSize-1))
                    return true;
                i++;
            }else{
                if(table[i] > -1){
                    m = m + i - table[i];
                    i = table[i];
                }else{
                    m++;
                    i=0;
                }
            }
            
        }
        
        System.out.println("saindo");
        return false;
    }
    
    @Override
    public void prepareSearch(String text, String word) {
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
                if(buscar(arr[i], word)){
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
    
}
