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
public class MorrisPratt extends AbstractSearch {

    private int[] next;
    
    public MorrisPratt(File file, String word) {
        super(file, word);
        next = new int[word.length()+1];
    }
    
    @Override
    protected boolean buscar(String txt, String padrao){
        int m = 0;
        int i = 0;
        int txtSize = txt.length();
        int padSize = padrao.length();
        
        if(txtSize != padSize){
            return false;
        }
        
        int[] table = new int[padSize+1];
        
        // Filipe Ramos -- Paula Campigotto
        int j=0;
        i = 0;
        j = table[0] = -1;
        
        while(i < padSize){
            while(j > -1 && padrao.charAt(i) != padrao.charAt(j)) j = table[j];
            table[++i] = ++j;
        }
        // 
        
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
        
        // Filie Ramos -- Paula Campigotto
        /*
        int n = txtSize;
        i = 0;
        j = 0;
        while(j < n){
            while(i > -1 && padrao.charAt(i) != txt.charAt(j)) i = table[i];
            i++;
            j++;
            if(i >= padSize) return true;
        }
        // 
        */
        return false;
    }
    
}
