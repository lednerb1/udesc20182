/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package buscaemtexto;

/**
 *
 * @author lucas
 */
public class BuscaEmTexto {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String a = "abacaxi é um bone da tua tia porque ela tem asa";
        String b = "é um bone";
        String c = "abx";
        RabinKarp teste = new RabinKarp();
        
        teste.buscar(a, b);
        if(teste.buscar(a, b))
            System.out.println("DALE MEU BOM");
        if(teste.buscar(a, c))
            System.out.println("DEU RUIM MEU BOM");
    }
}
