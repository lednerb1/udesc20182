/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package udesc.br.sudoku.gui;

import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Point;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.HashMap;
import java.util.Map;
import java.util.Objects;
import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.Border;
import udesc.br.sudoku.core.Board;
import udesc.br.sudoku.core.Generator;

/**
 *
 * @author guilhermeutiama , caio
 */
public class InterJogo extends javax.swing.JFrame {

    private Generator gerador;
    private int[][] referencia;
    static final Border DIVISAO = BorderFactory.createLineBorder(Color.BLACK);
    Botao selecionado;
    private final JTextField[][] grid;
    private final Map<JTextField, Point> mapFieldToCoordinates
            = new HashMap<>();

    private Botao_menu botao_teste;
    private Botao_menu botao_resolver;
    private int dimension;
    private JPanel gridPanel;
    // private Cronometro cronometro;

    /**
     * Creates new form InterJogo
     */
    public InterJogo(Generator gerador) {
        this.gerador = gerador;
        gerador.removeBoard();
        
        referencia = gerador.getBoard().copia();
        
        this.grid = new JTextField[dimension][dimension];
        this.dimension = gerador.n;
        init();

    }

    private void init() {
        JPanel p = new JPanel();
        JPanel painel_botao = new JPanel();
        JPanel root = new JPanel(new GridLayout(dimension, dimension));

        for (int i = 0; i < dimension * dimension; i++) {
            JPanel divisao = new JPanel(new GridLayout(dimension, dimension));
            divisao.setBorder(DIVISAO);
            System.out.println(i % (dimension * dimension) + " " + i * dimension % (dimension * dimension));
            int[] sqr = this.gerador.getBoard().getSqr(i % (dimension * dimension), i * dimension % (dimension * dimension));
            for (int j = 0; j < dimension * dimension; j++) {
                divisao.add(new Botao(i, j, sqr[j]));
            }
            root.add(divisao);
        }

        //p.add(new Cronometro());
        //adicionem no P outras coisas VLW!!
        //botao
        painel_botao.setLayout(new BoxLayout(painel_botao, BoxLayout.Y_AXIS));
        botao_teste = new Botao_menu("Testar", 0);
        botao_resolver = new Botao_menu("Resolver Sudoku", 1);

        painel_botao.add(botao_resolver);
        painel_botao.setBorder(DIVISAO);
        painel_botao.add(botao_teste);
        botao_teste.setAlignmentX(Component.LEFT_ALIGNMENT);
        botao_resolver.setAlignmentX(Component.LEFT_ALIGNMENT);
        p.add(root);
        p.add(painel_botao);
        getContentPane().add(p);

        initKeyListener();
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        pack();
    }

    private void initKeyListener() {
        addKeyListener(new KeyAdapter() {
            @Override
            public void keyReleased(KeyEvent e) {
                if (selecionado != null) {

                    if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                        selecionado.setBackground(COR_NORMAL);
                        selecionado.setBorder(BORDA_NORMAL);
                        selecionado = null;
                    } else {
                        String aux = Objects.toString(e.getKeyChar());
                        selecionado.setText(aux);
                        selecionado.valor = Integer.parseInt(aux);
                        System.out.println(selecionado.valor);
                    }
                }
            }
        });
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    public void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(InterJogo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(InterJogo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(InterJogo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(InterJogo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new InterJogo(gerador).setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
    static final Border BORDA_NORMAL = BorderFactory.createLineBorder(Color.GRAY);
    static final Border BORDA_SELECIONADO = BorderFactory.createLineBorder(Color.RED);
    static final Color COR_NORMAL = Color.WHITE;
    static final Color COR_SELECIONADO = Color.YELLOW;

    class Botao extends JLabel {

        /*
        *   Ideias:
        *   Provavelmente vamos ter que fazer um listener pra teclado
        *   Toda vez que tiver um carinha selecionado e o jogador tentar
        *   Atualizar o valor com o teclado chama a funcao que pega o i,j
        *   do Botao atual e atribui ao valor digitado (o Listener muda o valor)
        *   Talvez n seja um bom approach pro problema, mas vai que.
         */
        public int i;
        public int j;
        public int valor;

        public Botao(int i, int j, int valor) {
            super();
            String aux;
            if (valor == 0) {
                aux = "";
            } else {
                aux = Integer.toString(valor);
            }
            super.setText(aux);
            this.i = i;
            this.j = j;
            this.valor = valor;
            init();
        }

        private void init() {
            setBackground(COR_NORMAL);
            setBorder(BORDA_NORMAL);
            setPreferredSize(new Dimension(32, 32));
            setOpaque(true);
            Botao esteBotao = this;
            addMouseListener(new MouseAdapter() {
                @Override
                public void mouseReleased(MouseEvent e) {
                    selecionaBotao(esteBotao);
                }
            });
        }
    }

    void selecionaBotao(Botao botao) {
        // se tem selecionado
        if (selecionado != null) {
            selecionado.setBackground(COR_NORMAL);
            selecionado.setBorder(BORDA_NORMAL);
        }
        // seleciona o novo se não for nulo
        if (botao != null) {
            botao.setBackground(COR_SELECIONADO);
            botao.setBorder(BORDA_SELECIONADO);

        }
        selecionado = botao;
        System.out.println(selecionado.valor);
    }

    /* class Cronometro extends JLabel {

        void init() {

            setBackground(COR_NORMAL);
            setBorder(BORDA_NORMAL);
            setPreferredSize(new Dimension(180, 64));
            setOpaque(true);
            setVisible(true);
        }

        Cronometro() {
            super();
            super.setText("Tempo :" + S_tempo());
            init();
        }

        private String S_tempo() {
            return "";
        }

    }
     */
    class Botao_menu extends JLabel {

        int tipo; //0 para teste 1 para resolver

        private Botao_menu(String nome, int tipo) {
            super();
            super.setText(nome);
            this.tipo = tipo;
            init();
        }

        void init() {
            setBorder(DIVISAO);
            setOpaque(true);
            Botao_menu esteBotao = this;
            addMouseListener(new MouseAdapter() {
                @Override
                public void mouseClicked(MouseEvent e) {
                    System.out.println(".mouseClcked()");
                    seleciona(esteBotao);
                }

            });
        }

        private void seleciona(Botao_menu esteBotao) {
            if (esteBotao.tipo == 0) {
                //testa
            } else {
                //resolve
                resolve_board();
            }
        }

        private void resolve_board() {
            
        
        }
    }

}
