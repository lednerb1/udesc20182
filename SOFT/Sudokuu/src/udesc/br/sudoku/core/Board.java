/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package udesc.br.sudoku.core;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Vector;

/**
 * @author Caio K.
 * @author Guilherme U.
 * @author Peter B.
 */

public class Board {
    private int[][] matrix;
    int sqr;
    
    public Board(int n){
        this.sqr = n;
        matrix = new int[n][n];
    }
    
    private void generate() {
        fillDiagonal();
        fillResto();
    }
    
    private void fillDiagonal(){
        for(int i=0; i<sqr*sqr; i += i + sqr){
            fillBox(i, i);
        }
    }
    
    private void fillResto(){
        for(int i=0; i<sqr*sqr; i++){
            for(int j=0; j<sqr*sqr; j++){
                if(matrix[i][j] == 0){
                    
                }
            }
        }
    }
    
    private void fillBox(int r, int c){
        List<Integer> lista = new ArrayList<>();
        
        for(int i=1; i<=sqr; i++){
            lista.add(i);
        }
        
        Random rr = new Random();
        int i=0;
        int j=0;
        
        while(!lista.isEmpty()){
            int aux = rr.nextInt(lista.size());
            int n = lista.get(aux);
            lista.remove(aux);
            i++;
            matrix[r + (i / 3)][c + (i % 3)] = n;
        }
        
    }
}
