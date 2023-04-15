package Chayan;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.util.*;

public class CopyFileHandling {
    public static void main(String[] args) throws Exception{
        File testfile = new File(args[0]); 
        File newfile = new File(args[1]); 
        if (newfile.createNewFile()) {
        System.out.println("File is created : "+ newfile.getName());
        FileInputStream reader = new FileInputStream(testfile); 
        FileOutputStream writer = new FileOutputStream(newfile); 
        int flag; 
        while (true) {
         flag = reader.read();
        if(flag != -1){
            writer.write((char)flag);
             }
        else 
            break;
        }
        System.out.println("File Copied"); 
            reader.close(); 
            writer.close();
        } 
        else { 
         System.out.println("File Already exist NAME : "+newfile.getName()+" location : "  +newfile.getAbsolutePath());
        }
        } 
        } 
