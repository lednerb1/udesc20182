package udesc.br.sudoku.core;

/**
 * @author Caio K.
 * @author Guilherme U.
 * @author Peter B.
 */

public class Generator {
    
    private Board board;
    private int diff; // a ideia é, mandar 0-25, 1-50 ou 2-75... Seriam as representacoes em porcentagem para se tirar
    public int n;                   // ex: 9x9 = 81 celulas de matriz, se escolher a opcao media, pegaria 81 x 0.5 = 40 celulas
                        // para deixar em branco(usuario completar)
    
    public Generator(int n, int diff){
        board = new Board(n);
        this.diff = diff;
        this.n = n;
    }
    
    public Board getBoard(){
        return this.board;
    }
    
    
    
}
