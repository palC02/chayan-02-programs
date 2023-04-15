import java.util.*;
public class Calculate {
    int Sum,Sub,Mul;
        double Div;
        void Sum(int x,int y){
        Sum = x + y;
   }
    void Subtraction(int x, int y){
    Sub = Math.abs(x-y);
    }
    void Multiply(int x, int y){
        Mul = x * y;
    }
    void Division(int x, int y) {
        Div = Math.max(x, y)/ Math.min(x, y); 
    }
    void Display(){
    System.out.println("The sum  of two numbers is : " +Sum);
    System.out.println("The sub  of two numbers is : " +Sub);
    System.out.println("The Div  of two numbers is : " +Div);
    System.out.println("The Mul  of two numbers is : " +Mul);
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter first number: ");
         int x = sc.nextInt();
         System.out.print("Enter Second number: ");
         int y = sc.nextInt();
       Calculate ob = new Calculate();
       ob.Sum(x,y);
       ob.Subtraction(x,y);
       ob.Multiply(x,y);
       ob.Division(x,y);
      ob.Display();


}
}
