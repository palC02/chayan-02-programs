package Chayan;

class MyException extends Exception{
    MyException(String CP){
        super(CP)
    }
}
public class ExceptionHandling {
    public static void getValue(int n) throws MyException{
        if(n>2000){
            throw new MyException("Stop Here");
        }
        else{
        System.out.println("Your Number is"+n);
        }
    }
    public static void main(String[] args) {
        try{
            getValue(3000);
        }
        catch(MyException e){
            System.out.println(e+"Exception");
        }
    }
}