package superfatorial;

import java.math.BigInteger;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/*
 * SuperFatorial usando BigInteger nÃ£o recursivo
 */
public class SuperFatorial {
	
    /**
     *  @Key key
     *  @Val result of sf(key)
     */
    public HashMap<BigInteger, BigInteger> sdp;
    public HashMap<BigInteger, BigInteger> fdp;
    
    public SuperFatorial(){
        this.sdp = new HashMap <>();
        this.fdp = new HashMap <>();
    }
    
    public BigInteger getSuperFatorial(BigInteger n, boolean cache){
        
        if (sdp.containsKey(n) && cache){
            System.out.println("Pegou");
            return sdp.get(n);
        }
        
        if(n.equals(BigInteger.ZERO) || n.equals(BigInteger.ONE)){
            if(cache)
                sdp.put(n, BigInteger.ONE);
            return BigInteger.ONE;
        }
        
        return getSuperFatorial(n.subtract(BigInteger.ONE), cache).multiply(factorial(n, cache));

    }
    
    public BigInteger getDiscaoDaMassa(BigInteger n) throws  Exception {
        String path = "saida.txt";
//        BufferedReader bf = new BufferedReader(new FileReader(path));
        File arquivo = new File(path);
//        FileReader fr = new FileReader( arquivo );
//        String linha = null;
        boolean existe = arquivo.exists();
        if (!existe) {
//            System.out.println("criado");
            arquivo.createNewFile();
        }
        //escreve no arquivo
        FileWriter fw = new FileWriter(arquivo, true);
        BufferedWriter bw = new BufferedWriter(fw);
        //faz a leitura do arquivo
        FileReader fr = new FileReader(arquivo);
        BufferedReader br = new BufferedReader(fr);
        //enquanto houver mais linhas
        while (br.ready()) {
        //lê a proxima linha
            String linha = br.readLine();
            if(new BigInteger(linha).equals(n)){
                br.ready();
                linha = br.readLine();
//                System.out.println("achou leitura");
                return new BigInteger(linha);
            }
            linha = br.readLine();
                
        }
        BigInteger bigg = getSuperFatorial(n, false);
//        String aux = bigg.toString();
        bw.write(n.toString());
        bw.newLine();
        bw.write(bigg.toString());
//        System.out.println("escreve arquivo");
        bw.newLine();
        bw.close();
        br.close();
        fr.close();
        return bigg;
    }
	//////////////////////////
    public BigInteger factorial(BigInteger n, boolean cache){
        
        if(fdp.containsKey(n) && cache)
            return fdp.get(n);
        

        if(n.equals(BigInteger.ONE) || n.equals(BigInteger.ZERO)){
            if(cache){
                fdp.put(n, BigInteger.ONE);
            }
            return BigInteger.ONE;
        }
        
        if(cache){
            fdp.put(n, n.multiply(factorial(n.subtract(BigInteger.ONE), cache)));
        }
        else{
            return n.multiply(factorial(n.subtract(BigInteger.ONE), cache));
        }

        return fdp.get(n);
    }
    
}