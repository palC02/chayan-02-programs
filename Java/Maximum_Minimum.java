import java.util.*;
public class Largest_{
    public static void main(String[] args) {
        int s,i,min,max;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array: ");
        s=sc.nextInt();
        int arr[]=new int[s];
        System.out.println("Enter the array elements: ");
        for(i=0;i<s;i++){
            arr[i]=sc.nextInt();
        }
        min=max=arr[0];
        for(i=1;i<s;i++){
            if(max<arr[i]){
                max=arr[i];
            }
            else if(min>arr[i]){
                min=arr[i];
            }
        }
        System.out.println("Largest element is: "+max);
        System.out.println("Smallest element is: "+min);
        sc.close();
    }
}
