package Chayan;
public class Arithmatic {
    void all_Divisors(int n);
}
public class Arithmatic implements Special_Arithmatic1 {
public void all_Divisors(int n){
    int i;
for(i=1;i<=n;i++)  {
if(n%i==0)
System.out.println(i); }
}
public static void main(String args[]) {
Scanner sc=new Scanner(System.in);
int n;
System.out.print("Enter a number : ");
n=sc.nextInt();
System.out.print("Divisors of the number is : ");
Arithmatic ar = new Arithmatic();
ar.all_Divisors(n);

}
}
