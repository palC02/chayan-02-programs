import java.util.*;;
public class Concatinate {
    public static void main(String[] args) {
        String a;
        String b;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your string a :");
        a=sc.nextLine();
        System.out.println("Enter your string b :");
        b=sc.nextLine();
        String c = a.concat(b);
        System.out.println("First String after Concatination :"+c);

    }
    
}
