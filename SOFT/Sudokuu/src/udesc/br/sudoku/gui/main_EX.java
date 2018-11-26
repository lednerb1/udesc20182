package udesc.br.sudoku.gui;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.BorderFactory;
import javax.swing.JOptionPane;
import javax.swing.JMenuBar;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import java.awt.GridLayout;
import java.awt.Color;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class main_EX extends JFrame implements ActionListener {

    /*Declaração de atributos da classe*/
    private JButton[][] botao = new JButton[9][9];
    private int[] novo = new int[20];
    private JFrame win = new JFrame("Sudoku");
    private JPanel[] painel = new JPanel[9];
    private JMenuBar barra = new JMenuBar();
    private JMenu menu1 = new JMenu("Opçoes");
    private JMenuItem item1 = new JMenuItem("Novo Jogo");
    private JMenuItem item2 = new JMenuItem("Sobre...");
    private JMenuItem item3 = new JMenuItem("Sair");

    /*Construtor da Classe ele faz os botoes e a janela*/
    public main_EX() {
        fazBotao();
        fazJanela();
        novoJogo();
    }
    
    public static void main(String[] args){
        new main_EX();
    }

    /*Metodo que faz o meno da Barra de Menu*/
    public JMenuBar menu() {
        item1.addActionListener(this);
        menu1.add(item1);
        item2.addActionListener(this);
        menu1.add(item2);
        item3.addActionListener(this);
        menu1.add(item3);
        barra.add(menu1);
        return barra;
    }

    /*Metodo que faz os botoes*/
    public void fazBotao() {
        for (int i = 0; i < botao.length; i++) {
            painel[i] = new JPanel(new GridLayout(3, 3));
            painel[i].setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
            for (int j = 0; j < botao.length; j++) {
                botao[i][j] = new JButton();
                botao[i][j].setText(" ");
                botao[i][j].addActionListener(this);
                painel[i].add(botao[i][j]);
            }
        }
    }

    /*Metodo que faz as janelas*/
    public void fazJanela() {
        win.setJMenuBar(menu());
        win.getContentPane().setLayout(new GridLayout(3, 3));
        win.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        for (int i = 0; i < painel.length; i++) {
            win.getContentPane().add(painel[i]);
        }
        //win.pack();
        win.setSize(390, 350);
        win.setDefaultLookAndFeelDecorated(false);
        win.setResizable(false);
        win.setVisible(true);
    }

    /*Metodo que inicia um novo Jogo*/
    public void novoJogo() {
        int lin, col;
        boolean val;
        for (int i = 0; i < novo.length; i++) {
            novo[i] = (int) (1 + (Math.random() * 9));
        }
        for (int i = 0; i < botao.length; i++) {
            for (int j = 0; j < botao.length; j++) {
                botao[i][j].setText(" ");
            }
        }
        for (int i = 0; i < novo.length; i++) {
            lin = (int) (Math.random() * 9);
            col = (int) (Math.random() * 9);
            botao[lin][col].setText(String.valueOf(novo[i]));
        }
    }

    /*Metodo que gerencia os Eventos da Classe*/
    public void actionPerformed(ActionEvent e) {
        String n = " ";
        int nro;
        /*No menu Novo Jogo*/
        if (e.getSource() == item1) {
            novoJogo();
        }
        /*No menu Sobre...*/
        if (e.getSource() == item2) {
            JOptionPane.showMessageDialog(null, "Sudoku: \n"
                    + "Um jogo de raciocinio logico com o"
                    + "\nintuito de desenvolver o raciocinio logico.\n"
                    + "Desenvolvedores:"
                    + "\nEverton José Benedicto RA. 0510688"
                    + "\nEdson Soares da Silva RA. 0711232", "Sobre Sudoku", JOptionPane.WARNING_MESSAGE);
        }
        /*No menu Sair*/
        if (e.getSource() == item3) {
            System.exit(0);
        }
        /*Aqui eu vou gerenciar os eventos de cada botao do Array*/
        for (int i = 0; i < botao.length; i++) {
            for (int j = 0; j < botao.length; j++) {
                if (e.getSource() == botao[i][j]) {
                    do {
                        /*loop de integridade de dado*/
                        nro = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite o numero", "Sudoku", JOptionPane.WARNING_MESSAGE));
                        if (nro <= 0 || nro > 9) {
                            JOptionPane.showMessageDialog(null, "Numero Inválido", "Sudoku Notifica", JOptionPane.WARNING_MESSAGE);
                        }
                    } while (nro <= 0 || nro > 9);/*Fim do loop*/
                    n = n.valueOf(nro);
                    botao[i][j].setText(n);
                    if (e.getSource() == botao[i][j]) {
                        break;
                    }
                }
            }
        }
    }
}
/*Fim dos Eventos*/
