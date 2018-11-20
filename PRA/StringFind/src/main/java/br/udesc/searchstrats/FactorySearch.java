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
    
    public RabinKarp rabinkarp(File file, String word){
        RabinKarp rabinkarp = new RabinKarp(file, word);
        return rabinkarp;
    }
    
    public MorrisPratt morrispratt(File file, String word){
        MorrisPratt morrispratt = new MorrisPratt(file, word);
        return morrispratt;
    }
    
    public BoyerMoore boyermoore(File file, String word){
        BoyerMoore boyermoore = new BoyerMoore(file, word);
        return boyermoore;
    }
    
    public AhoCorasick ahocorasick(File file, String word){
        AhoCorasick ahocorasick = new AhoCorasick(file, word);
        return ahocorasick;
    }
    
    public RadixTree radixtree(File file, String word){
        RadixTree radixtree = new RadixTree(file, word);
        return radixtree;
    }
    
}
