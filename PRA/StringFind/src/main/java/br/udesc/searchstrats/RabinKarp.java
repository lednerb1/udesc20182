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
public class RabinKarp extends AbstractSearch {
        
    public RabinKarp(File file, String word){
        super(file, word);
    }
    
    @Override
    protected boolean buscar(String txt, String padrao){
        
        return (padrao.hashCode() == txt.hashCode());
    }
  
}
