import java.util.*;

public class DiagonalSum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length of the matrix ");
        int n = sc.nextInt();
        int[][] arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.println("Enter the [" + i + "," + j + "] element");
                arr[i][j] = sc.nextInt();
            }
        }
        System.out.println("Array is ");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.println(arr[i][j] + " ");
            }
            System.out.println();
        }
        int R_D_sum = 0;
        int L_D_sum = 0;
        for (int i = 0; i < n; i++) {
            L_D_sum += arr[i][i];
        }
        int j = n - 1;
        for (int i = 0; i < n; i++) {
            R_D_sum += arr[i][j];
            j--;
        }
        if (R_D_sum > L_D_sum) {
            System.out.print("Right Diagonal Sum is Large & it is" + R_D_sum);
        } else {
            System.out.print("Left Diagoanl Sum is Large & it is " + L_D_sum);
        }
    }

}
