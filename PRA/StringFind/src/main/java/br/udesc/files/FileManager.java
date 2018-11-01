/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.udesc.files;

import java.io.File;
import java.util.ArrayList;

/**
 *
 * @author udesc
 */
public class FileManager {
    private ArrayList<File> files;
    
    public FileManager(){
        files = new ArrayList<>();
    }
    
    public ArrayList<File> getFiles(){
        return files;
    }
    
    public boolean readFiles(File[] arr){
        boolean allGood=true;
        for(int i=0; i<arr.length; i++){
                if(arr[i].getName().endsWith(".txt")){
                    files.add(arr[i]);
                }else{
                    allGood=false;
                }
            }
        return allGood;
    }
    
}
