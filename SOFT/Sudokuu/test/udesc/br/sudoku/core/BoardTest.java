/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package udesc.br.sudoku.core;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author udesc
 */
public class BoardTest {

    public BoardTest() {
    }

    @BeforeClass
    public static void setUpClass() {
    }

    @AfterClass
    public static void tearDownClass() {
    }

    @Before
    public void setUp() {
    }

    @After
    public void tearDown() {
    }

    @Test
    public void testBoard() {
        Generator generator = new Generator(4, 0);
        Board board = generator.getBoard();

    }

    public void testunUsedInCol() {
        Board b = new Board();
        b.sqr = 3;
        b.matrix[0][0] = 1;
        b.matrix[1][0] = 2;
        b.matrix[2][0] = 3;
        b.matrix[3][0] = 4;
        b.matrix[4][0] = 5;
        b.matrix[5][0] = 6;
        b.matrix[6][0] = 7;
        b.matrix[7][0] = 8;
        assertEquals(b.unUsedInCol(0, 9), true);

    }

    public void testunUsedInRow() {
        Board b = new Board();
        b.sqr = 3;
        b.matrix[0][0] = 7;
        b.matrix[0][1] = 1;
        b.matrix[0][2] = 2;
        b.matrix[0][3] = 3;
        b.matrix[0][4] = 4;
        b.matrix[0][5] = 5;
        b.matrix[0][6] = 6;
        b.matrix[0][7] = 8;
        assertEquals(b.unUsedInRow(0, 8), false);

    }

    public void testunUsedInBox() {
        Board b = new Board();
        b.sqr = 3;

        b.matrix[0][0] = 7;
        b.matrix[0][1] = 1;
        b.matrix[0][2] = 2;
        b.matrix[1][0] = 3;
        b.matrix[1][1] = 4;
        b.matrix[1][2] = 5;
        b.matrix[2][0] = 6;
        b.matrix[2][1] = 8;
        assertEquals(b.unUsedInBox(0,0,8), false);
    }

}
