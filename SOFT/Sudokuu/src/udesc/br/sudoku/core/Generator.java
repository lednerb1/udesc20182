package udesc.br.sudoku.core;

import java.util.Random;

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

    public Generator(int n, int diff) {
        board = new Board(n);
        this.diff = diff;
        this.n = n;
    }

    public Board getBoard() {
        return this.board;
    }

    public void removeBoard() {
        int quantidade_removido = 0;

        if (diff == 1) {
            double aux =  16 * 0.5;
            quantidade_removido = (int) aux;
        } else if (diff == 2) {
            double aux = 81 * 0.75;
            quantidade_removido = (int) aux;
        } else if (diff == 3) {
            double aux = 256 * 0.90;
            quantidade_removido = (int) aux;

        }
        remove(quantidade_removido);
    }

    private void remove(int quantidade_removido) {
        Random g1 = new Random();
        Random g2 = new Random();
        for (int i = 0; i < quantidade_removido; i++) {
            int auxi = g1.nextInt(n * n);
            int auxj = g2.nextInt(n * n);

            if (board.getPos(auxi, auxj) == 0) {
                quantidade_removido--;
            } else {
                board.zeraPos(auxi, auxj);

            }
        }
    }
}
