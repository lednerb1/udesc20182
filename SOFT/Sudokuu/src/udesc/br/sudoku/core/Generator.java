package udesc.br.sudoku.core;

/**
 * @author Caio K.
 * @author Guilherme U.
 * @author Peter B.
 */

public class Generator {
    
    private Board board;
    private int diff;
    
    public Generator(int n, int diff){
        board = new Board(n);
        this.diff = diff;
    }
    
    public Board getBoard(){
        return this.board;
    }
    
}
