import java.util.*;
public class Grade{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the marks");
        int m = sc.nextInt();

        if(m>= 95 & m<=100){
            System.out.println("The Grade is O");
        }
        else if(m>=85 & m<=94){
            System.out.println("The Grade is A+");
        }
        else if(m>=75 & m<=84){
            System.out.println("The Grade is A");
        }
        else if(m>=60 & m<=74){
            System.out.println("The Grade is B");
        }
        else if(m>=50 & m<=59){
            System.out.println("The Grade is C");
        }
        else if(m>=40 & m<=49){
            System.out.println("The Grade is D");
        }
        else if(m<40){
            System.out.println("The Grade is F");
        }


    }
}
