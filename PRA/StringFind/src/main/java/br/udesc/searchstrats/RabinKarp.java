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
 * @author Meu Bom
 */
public class RabinKarp implements ISearchStrategy {
    
    final int caracteres = 256;
    final int moduloPrimo = 997;
    
    private ArrayList<String[]> temp;
    private String word;
    private ArrayList<Integer> strSize;
    
    public RabinKarp(File file, String word){
        temp = new ArrayList<>();
        strSize = new ArrayList<>();
        this.word = word;
        BufferedReader read = null;
        String line;
        int i=0;
        
        try {
            read = new BufferedReader(new FileReader(file));
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(RabinKarp.class.getName()).log(Level.SEVERE, null, ex);
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
    
    public boolean buscar(String txt, String padrao){
        txt = txt.replace(",", "");
        return (padrao.hashCode() == txt.hashCode());
    }
    
    private long hash(String padrao, int tam){
        //Algoritmo de Horner
        long aux = 0;
        for(int j = 0; j < tam; j++)
            aux = (aux * caracteres + padrao.charAt(j)) % moduloPrimo;
        return aux;
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
