import java.util.Scanner;
public class SelectionSort{
    public static void selectionSort(int[] arr, int n){
        for(int i=0; i<=n-2; i++){
            int min = i;
            for(int j=i+1; j<=n-1; j++){
                if(arr[j]<arr[min]){
                    min=j;
                }
            }
            if(arr[min]<arr[i]){
                int temp = arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements in the array: ");
        int n = sc.nextInt();
        int[] arr=new int[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter element"+ (i+1)+": ");
            arr[i]=sc.nextInt();
        }   
        System.out.println("Array before sorting: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
        selectionSort(arr, n);
        System.out.println("Array after sorting: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }

    }
}