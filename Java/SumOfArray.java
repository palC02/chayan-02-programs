import java.util.*;
public class SumOfArray {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        System.out.println("Enter the Size of the array:");
        int n=sc.nextInt();
        int arr[]=new int[n];
        System.out.println("Enter the Number of Elements: ");
        int sum=0;
           for(int i=0;i<n;i++){
               arr[i]=sc.nextInt();
               sum=sum+arr[i];
           }
           System.out.println("Element of the array are: "+Arrays.toString(arr));
           System.out.println("Sum of the Array is "+sum);

    }
    
}
