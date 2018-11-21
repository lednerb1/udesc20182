package br.udesc.searchstrats;

/**
 *
 * @author Guilherme Utiama
 * @author Peter Brendel
 */

public class WordLocation {
    private int line;
    private int column;
    private String word;
    private long timeToFind;
    
    public WordLocation(String word){
        this.word = word;
    }
    
    public int getLine(){
        return line;
    }
    
    public int getColumn(){
        return column;
    }
    
    public void setLine(int line){
        this.line = line;
    }
    
    public void setColumn(int column){
        this.column = column;
    }
    
    public void setTime(long timeToFind){
        this.timeToFind = timeToFind;
    }
    
    public long getTime(){
        return timeToFind;
    }
    
    @Override
    public String toString(){
        return word + " encontrado na linha " + line + " coluna " + column + "\n"
                + "Found in: " + (float)timeToFind / 1000.0 + " s\n";
    }
    
}
