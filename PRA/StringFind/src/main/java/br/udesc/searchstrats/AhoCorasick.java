/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.udesc.searchstrats;

import java.io.File;
import java.util.HashMap;
import java.util.Map;
/**
 *
 * @author udesc
 */

public class AhoCorasick extends AbstractSearch{
    private node root;
    
     public AhoCorasick(File file, String word){
        super(file,word);
        root = init();
        inserePattern(word);
    }
    
    public int searchFile(String content, String pattern) {
        
        return quantificaOcorrencias(content);
    }
    
    
/////////////////////////////////////////////////////////
    @Override
    protected boolean buscar(String word, String other) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

  
    private class node {
        boolean fim;
        Map<Integer, node> child;
        int depth = -1;
    }
    
    private node init(){
        node nd = new node();
        nd.fim = false;
        nd.depth = 0;
        nd.child = new HashMap<Integer, node>();
        return nd;
    }
//    the letter any more
//    public boolean buscar(String txt, String padrao){
//        
//    }
    void inserePattern(String pattern){
        int d = 0;
        node current = root;
        for(int i = 0; i < pattern.length(); i++){
            int letter = (int)pattern.charAt(i);
            if(current.child.containsKey(letter) == false){
                    current.child.put(letter, init());
            }
            current = current.child.get(letter);
            current.depth = d;
        }
        current.fim = true;
    }
    
    int quantificaOcorrencias(String content){
        node current = root;
        int count = 0;
        for (int i = 0; i < content.length(); i++){
            int letter = (int)content.charAt(i);
            if (current.child.containsKey(letter))
            {
                current = current.child.get(letter);
                if (current.fim)
                {
                    count++;
                    i -= current.depth; // Cobre caso de "ll" em "lllll".
                }
            }
            else if (!current.child.containsKey(letter))
            {
                i -= current.depth - 1; // Cobre caso de "llb" em "lllllb".
                current = root;
            }
        }
        return count;
    }
    
    
    
}
