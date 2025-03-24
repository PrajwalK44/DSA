import java.util.Scanner;
public class selection_sort {
    public void selectionSort(int arr[], int n){
        int swap=0;
       //selection sort
       for(int i=0; i<=n-2; i++){
        int min=i;
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp = arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
        swap++;
       }
       System.out.println("Number of swaps performed: "+swap);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        selection_sort ss = new selection_sort();
        System.out.println("Enter the size of array");
        n=sc.nextInt();
        int [] arr=new int[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Enter the element "+(i+1));
            arr[i]=sc.nextInt();
        }
        System.out.println("Array before sorting");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
        System.out.println("");
        ss.selectionSort(arr, n);
        System.out.println("sorted array");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+" ");
        }
    }
}

