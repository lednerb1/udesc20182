/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.udesc.searchstrats;

import java.io.File;

/**
 *
 * @author udesc
 */
public class FactorySearch {
    
    public NaiveSearch naive(File file, String word){ 
        NaiveSearch naive = new NaiveSearch(file, word);
        return naive;
    }
    
}
