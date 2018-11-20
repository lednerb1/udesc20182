/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.udesc.searchstrats;

import java.io.File;

/**
 *
 * @author peter
 */
public class BoyerMoore extends AbstractSearch {
    
    private int[] right;
    
    public BoyerMoore(File file, String word){
        super(file, word);
        right = new int[256];
        for(int i=0; i < 256; i++){
            right[i] = -1;
        }
        for(int i=0; i < word.length(); i++){
            right[word.charAt(i)] = i;
        }
    }
    
    @Override
    protected boolean buscar(String txt, String padrao){
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
   
    
    

    
}
