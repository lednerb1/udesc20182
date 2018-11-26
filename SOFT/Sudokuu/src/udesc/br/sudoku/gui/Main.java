/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package udesc.br.sudoku.gui;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import udesc.br.sudoku.core.*;

/**
 *
 * @author udesc
 */
public class Main extends JFrame implements ActionListener {
    private Generator generator;
    private Board board;
    private JFrame menu;
    private JPanel menu_panel;

    public Main(){
        criarMenu();
    }
    
    private void criarMenu(){
        
    }
    
    @Override
    public void actionPerformed(ActionEvent e) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
    
    public static void main(String []args){
        new Main();
    }
    
    
}
