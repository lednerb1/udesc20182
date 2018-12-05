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
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * @author Caio K.
 * @author Guilherme U.
 * @author Peter B.
 */
public class Board {

    public int[][] matrix;
    int sqr;
    private char[] letras;

    public Board(int n) {
        this.sqr = n;
        matrix = new int[n * n][n * n];
        letras = new char[17];
        for (int i = 1; i < 10 && i <= n * n; i++) {
            letras[i] = (char) (i + '0');
        }

        for (int i = 10; i <= n * n; i++) {
            letras[i] = (char) (i - 10 + 'A');
        }
        generate();
    }

    public int getPos(int i, int j) {
        return this.matrix[i][j];
    }

    public void zeraPos(int i, int j) {
        this.matrix[i][j] = 0;
    }

    public int[] getRow(int i) {
        return this.matrix[i];
    }

    public int[] getCol(int j) {
        int[] col = new int[sqr * sqr];

        for (int i = 0; i < sqr * sqr; i++) {
            col[i] = this.matrix[j][i];
        }
        return col;
    }

    public int[] getSqr(int i, int j) {
        int l = i - i % sqr;
        int c = j - j % sqr;
        int ll = l + sqr;
        int cc = c + sqr;

        int[] SQR = new int[sqr * sqr];

        int cont = 0;
        for (; l < ll; l++) {
            for (c = j - j % sqr; c < cc; c++) {
                SQR[cont++] = matrix[l][c];
            }
        }
        return SQR;
    }

    private void generate() {
        fillDiagonal();
        fillResto(0, sqr);
//        print();
    }

    private void fillDiagonal() {
        for (int i = 0; i < sqr * sqr; i += sqr) {
            fillBox(i, i);
        }
    }

    public boolean checkSurrounds(int i, int j, int m, boolean debug) {
        
        if(debug){
            System.out.println("Verifying " + m + " at " + i + " " + j);
            if(!(m > 0 && m <= sqr*sqr)){
                System.out.println("outofbounds");
                return false;
            }
            
        }
        // Checking Lines and Cols
        for (int c = 0; c < sqr * sqr; c++) {
//            System.out.print("lines ");
            if (matrix[i][c] == m && c != j) {
                return false;
            }
        }
        
        for (int c = 0; c < sqr * sqr; c++) {
//            System.out.print("cols ");
            if (matrix[c][j] == m && c != i) {
//                System.out.println("Found at" + c + " " + j + " " + matrix[c][j]);
                return false;
            }
        }
        
        // Checking Box
        int l = i - i % sqr;
        int c = j - j % sqr;
        int ll = l + sqr;
        int cc = c + sqr;
        for (; l < ll; l++) {
//            System.out.print("sqr1 ");
            for (c = j - j % sqr; c < cc; c++) {
//                System.out.print("sqr2 ");
                if (matrix[l][c] == m && (l != i || c != j)) {
                    return false;
                }
            }
        }
//        System.out.println("allg");
        return true;
    }

    private boolean fillResto(int i, int j) {
//        System.out.println(i + "," + j);
        if (j >= sqr * sqr && i < sqr * sqr - 1) {
            i++;
            j = 0;
        }
        if (i >= sqr * sqr && j >= sqr * sqr) {
            return true;
        }

        if (i < sqr) {
            if (j < sqr) {
                j = sqr;
            }
        } else if (i < sqr * sqr - sqr) {
            if (j == (int) (i / sqr) * sqr) {
                j += sqr;
            }
        } else {
            if (j == sqr * sqr - sqr) {
                i++;
                j = 0;
                if (i >= sqr * sqr) {
                    return true;
                }
            }
        }

        for (int next = 1; next <= sqr * sqr; next++) {

            if (checkSurrounds(i, j, next, false)) {
                matrix[i][j] = next;

                if (fillResto(i, j + 1)) {
                    return true;
                }

                matrix[i][j] = 0;
            }
        }
        return false;
    }

    private void fillBox(int r, int c) {
        List<Integer> lista = new ArrayList<>();

        for (int i = 1; i <= sqr * sqr; i++) {
            lista.add(i);
        }

        Random rr = new Random();
        int i = 0;
        int j = 0;

        while (!lista.isEmpty()) {
            int aux = rr.nextInt(lista.size());
            int n = lista.get(aux);
            lista.remove(aux);
            if (i == sqr) {
                i = 0;
                j++;
                if (j == sqr) {
                    break;
                }
            }
            matrix[r + j][(c + i)] = n;
            i++;
        }
    }

    public void print() {

        for (int i = 0; i < sqr * sqr; i++) {
            for (int j = 0; j < sqr * sqr; j++) {
//                System.out.println(matrix[i][j] + " ");
                if (matrix[i][j] == 0) {
                    System.out.print(". ");
                } else {
                    System.out.print(letras[matrix[i][j]] + " ");
                }
            }
            System.out.println();
        }
    }

    private void removerK(int k) {
        Random r = new Random();
        while (k != 0) {
            int i = r.nextInt(sqr * sqr);
            int j = r.nextInt(sqr * sqr);
            if (matrix[i][j] != 0) {
                matrix[i][j] = 0;
                k--;
            }
        }
    }

    // Check if safe to put in cell 
    boolean CheckIfSafe(int i, int j, int num) {
        return (unUsedInRow(i, num)
                && unUsedInCol(j, num)
                && unUsedInBox(i - i % sqr, j - j % sqr, num));
    }

    // check in the row for existence 
    boolean unUsedInRow(int i, int num) {
        for (int j = 0; j < sqr * sqr; j++) {
            if (matrix[i][j] == num) {
                return false;
            }
        }
        return true;
    }

    // check in the row for existence 
    boolean unUsedInCol(int j, int num) {
        for (int i = 0; i < sqr * sqr; i++) {
            if (matrix[i][j] == num) {
                return false;
            }
        }
        return true;
    }

    boolean unUsedInBox(int rowStart, int colStart, int num) {
        for (int i = 0; i < sqr; i++) {
            for (int j = 0; j < sqr; j++) {
                if (matrix[rowStart + i][colStart + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    public Board() {
    }

    public int[][] copia() {
        int n = sqr;
        int[][] copia = new int[n * n][n * n];

        for (int i = 0; i < n * n; i++) {
            for (int j = 0; j < n * n; j++) {
                copia[i][j] = matrix[i][j];
            }
        }

        return copia;

    }

    public void generate(int[][] principal) {

        this.matrix = principal;
        //fillDiagonal();
        fillResto(0, sqr);
//        print();
    }
}
