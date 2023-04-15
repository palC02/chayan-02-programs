import java.util.*;
public class FindArray{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        int f,n=0;
        int s=sc.nextInt();
        int arr[]=new int[s];
        System.out.println("Enter the Elements");
        for(int i=0;i<s;i++){
            arr[i]=sc.nextInt();
        }
        System.out.println("Enter the Element which you are Search");
        f=sc.nextInt();
        for(int i=0;i<s;i++){
            if(f==arr[i]){
                n=1;
                break;
            }
            else
            n=0;
        }
        if(n==1){
            System.out.println("The Number Present in the list is "+f);
        }
        else{
            System.out.println("The Number is not Present in the list "+f);
        }
        
    }
}