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
        generate();
    }
    
    public int getPos(int i, int j){
        return this.matrix[i][j];
    }
    
    public int[] getRow(int i){
        return this.matrix[i];
    }
    
    public int[] getCol(int j){
        int[] col = new int[sqr*sqr];
        
        for(int i=0; i<sqr*sqr; i++){
            col[i] = this.matrix[j][i];
        }
        return col;
    }
    
    public int[] getSqr(int i, int j){
        int l = i - i % sqr;
        int c = j - j % sqr;
        
        int[] SQR = new int[sqr*sqr];
        
        int cont=0;
        for(; l < sqr; l++){
            for(; c < sqr; c++){
                SQR[cont++] = matrix[l][c];
            }
        }
        return SQR;
    }
    
    private void generate() {
        fillDiagonal();
        fillResto(0, sqr);
        print();
    }
    
    private void fillDiagonal(){
        for(int i=0; i<sqr; i += sqr){
            System.out.println("Hmmm");
            fillBox(i, i);
        }
    }
    
    private int[] checkSurrounds(int i, int j){
        int[] temp = new int[sqr*sqr];
        
        // Checking Lines and Cols
        for(int c = 0; c < sqr*sqr; c++) {
            if(matrix[i][c] == 0) continue;
            temp[matrix[i][c]] = 1;
            if(matrix[c][j] == 0) continue;
            temp[matrix[c][j]] = 1;
        }
        // Checking Box
        int l = i - i % sqr;
        int c = j - j % sqr;
        for(; l < sqr; l++){
            for(; c < sqr; c++){
                if(matrix[l][c] == 0) continue;
                temp[matrix[l][c]] = 1;
            }
        }
        
        // Return array of available numbers
        return temp;
    }
    
    private boolean fillResto(int i, int j){
        if(j >= sqr*sqr){
            i++;
            j=0;
            if(i >= sqr*sqr){
                return true;
            }
        }
        if(matrix[i][j] == 0){
            int[] nums = checkSurrounds(i, j);
            
            for(int next = 1; next <= nums.length; next++){
                if(nums[next] == 0)
                    matrix[i][j] = nums[next];
                else continue;
                
                if(fillResto(i, j+1))
                    return true;
               
                matrix[i][j] = 0;
            }
            
        }                     
        return false;
    }
    
    private void fillBox(int r, int c){
        List<Integer> lista = new ArrayList<>();
        
        for(int i=1; i<=sqr; i++){
            lista.add(i);
        }
        
        Random rr = new Random();
        int i=0;
        int j=0;
        System.out.println("r= " + r + "\nc= " + c);
        
        while(!lista.isEmpty()){
            int aux = rr.nextInt(lista.size());
            int n = lista.get(aux);
            lista.remove(aux);
            if(i == sqr){
                i=0;
                j++;
                if(j == sqr)
                    break;
            }
            //System.out.println((r + (i / 3)) + " " + (c + (i % 3)));
            //matrix[r + (i / 3)][c + (i % 3)] = n;
            matrix[r+i][c+j] = n;
            i++;
        }   
    }
    
    private void print(){
        for(int i=0; i<sqr*sqr; i++){
            for(int j=0; j<sqr*sqr; j++){
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }
}
