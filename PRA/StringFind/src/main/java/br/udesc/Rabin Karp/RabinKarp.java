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
public class RabinKarp {
    final int caracteres = 256;
    final int moduloPrimo = 997;
    
    public Boolean buscar(String txt, String padrao){
        int tamPad = padrao.length();
        int tamTxt = txt.length();
        long hashPadrao = hash(padrao, tamPad);
        

        for(int cont = 0; cont <= tamTxt - tamPad; cont ++){
            long hashTxt = hash(txt.substring(cont, cont  + tamPad), tamPad);
            if(hashPadrao == hashTxt)
                return true;
        }
        return false;
    }
    
    private long hash(String padrao, int tam){
        //Algoritmo de Horner
        long aux = 0;
        for(int j = 0; j < tam; j++)
            aux = (aux * caracteres + padrao.charAt(j)) % moduloPrimo;
        return aux;
    }
}
