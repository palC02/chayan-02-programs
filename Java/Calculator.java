import java.util.*;
public class Calculator {
   int arr[],N;
    Calculator(){
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter total numbers to do the calculation : ");
       N = sc.nextInt();
      arr = new int[N];
    System.out.println("Enter the numbers : ");
         for (int i = 0; i < N; i++) {
             arr[i] = sc.nextInt(); }
        }
void Summation(){
            int Sum = 0;
            for(int i = 0; i< N ; i++){
                Sum = Sum + arr[i]; }
               System.out.println("Summation of the numbers: " + Sum);
        }
        void Subtraction(){
            int Sub = arr[0];
            for(int i = 1; i< N ; i++){
                Sub = Sub - arr[i]; }
               System.out.println("Subtraction of the numbers: " + Sub);
        }
        void Multiply(){
            int Mul = 1;
            for(int i = 1; i< N ; i++){
                Mul = Mul * arr[i]; }
               System.out.println("Multiplication of the numbers: " + Mul);
               }
         public static void main(String[] args) {
            Calculator k = new Calculator();
            k.Summation();
            k.Subtraction();
            k.Multiply();
            }
        }
