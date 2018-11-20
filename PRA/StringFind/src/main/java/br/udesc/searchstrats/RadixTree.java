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
public class RadixTree extends AbstractSearch {
    
    RadixTree(File file, String word) {
        super(file, word);
    }

    @Override
    protected boolean buscar(String word, String other) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
}
