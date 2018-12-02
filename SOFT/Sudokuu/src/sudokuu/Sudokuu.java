package sudokuu;

import java.lang.*;
import java.util.Random;

public class Sudokuu {

    int[] mat[];
    int N; // number of columns/rows. 
    int SRN; // square root of N 
    int K; // No. Of missing digits 

    // Constructor 
    Sudokuu(int N, int K) {
        this.N = N;
        this.K = K;

        // Compute square root of N 
        Double SRNd = Math.sqrt(N);
        SRN = SRNd.intValue();

        mat = new int[N][N];
    }

    // Sudoku Generator 
    public void fillValues() {
        // Fill the diagonal of SRN x SRN matrices 
        fillDiagonal();

        // Fill remaining blocks 
        fillRemaining(0, SRN);

        // Remove Randomly K digits to make game
        printSudoku();
        removeKDigits();
    }

    // Fill the diagonal SRN number of SRN x SRN matrices 
    void fillDiagonal() {

        for (int i = 0; i < N; i = i + SRN) // for diagonal box, start coordinates->i==j 
        {
            fillBox(i, i);
        }
    }

    // Returns false if given 3 x 3 block contains num. 
    boolean unUsedInBox(int rowStart, int colStart, int num) {
        for (int i = 0; i < SRN; i++) {
            for (int j = 0; j < SRN; j++) {
                if (mat[rowStart + i][colStart + j] == num) {
                    return false;
                }
            }
        }

        return true;
    }

    // Fill a 3 x 3 matrix. 
    void fillBox(int row, int col) {
        int num;
        for (int i = 0; i < SRN; i++) {
            for (int j = 0; j < SRN; j++) {
                do {
                    num = randomGenerator(N);
                } while (!unUsedInBox(row, col, num));

                mat[row + i][col + j] = num;
            }
        }
    }

    // Random generator 
    int randomGenerator(int num) {
        return (int) Math.floor((Math.random() * num + 1));
    }

    // Check if safe to put in cell 
    boolean CheckIfSafe(int i, int j, int num) {
        return (unUsedInRow(i, num)
                && unUsedInCol(j, num)
                && unUsedInBox(i - i % SRN, j - j % SRN, num));
    }

    // check in the row for existence 
    boolean unUsedInRow(int i, int num) {
        for (int j = 0; j < N; j++) {
            if (mat[i][j] == num) {
                return false;
            }
        }
        return true;
    }

    // check in the row for existence 
    boolean unUsedInCol(int j, int num) {
        for (int i = 0; i < N; i++) {
            if (mat[i][j] == num) {
                return false;
            }
        }
        return true;
    }

    // A recursive function to fill remaining 
    // matrix 
    boolean fillRemaining(int i, int j) { 
        if (j >= N && i < N - 1) {
            i = i + 1;
            j = 0;
        }
        if (i >= N && j >= N) {
            return true;
        }

        if (i < SRN) {
            if (j < SRN) {
                j = SRN;
            }
        } else if (i < N - SRN) {
            if (j == (int) (i / SRN) * SRN) {
                j = j + SRN;
            }
        } else {
            if (j == N - SRN) {
                i = i + 1;
                j = 0;
                if (i >= N) {
                    return true;
                }
            }
        }
//        System.out.println("2- " + i + " " + j);
        for (int num = 1; num <= N; num++) {
            if (CheckIfSafe(i, j, num)) {
                mat[i][j] = num;
//                System.out.println("---> "+mat[i][j]);
                if (fillRemaining(i, j + 1)) {
                    return true;
                }

                mat[i][j] = 0;
            }
        }
        return false;
    }

    // Remove the K no. of digits to 
    // complete game 
    public void removeKDigits() {
        int count = K;
        Random r = new Random();
        while (count != 0) {
            int i = r.nextInt(N);
            int j = r.nextInt(N);
            if(mat[i][j] != 0){
                mat[i][j] = 0;
                count--;
            }
        }
    }

    // Print sudoku 
    public void printSudoku() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(mat[i][j] != 0)
                    System.out.print(mat[i][j] + " ");
                else
                    System.out.print("_ ");
            }
            System.out.println();
        }
        System.out.println();
    }

    // Driver code 
    public static void main(String[] args) {
        int N = 16, K = 20;
        Sudokuu sudoku = new Sudokuu(N, K);
        sudoku.fillValues();
        sudoku.printSudoku();
    
    }
}
