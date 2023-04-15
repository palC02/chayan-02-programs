//package Chayan;

import java.io.*;
public class copy{
public static void main(String[]args) throws IOException{
File main = new File(args[0]);
if(!main.exists()){
System.out.println("File does not exist");
System.exit(1);
}
File copied = new File(args[1]);
FileReader reader = new FileReader(main);
FileWriter writer = new FileWriter(copied);
int flag,i=1;
while ((flag = reader.read()) !=-1){
writer.append((char)flag);
}
reader.close();
writer.close();
System.out.println("Copied Complete");
}
}

