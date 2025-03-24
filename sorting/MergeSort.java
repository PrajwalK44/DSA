import java.util.Scanner;

public class MergeSort
{
    
    public static void merge(int[] arr, int start, int middle, int end){
        int i, j, k;
        int n1=middle-start+1;
        int n2=end-middle;
        
        int[] L= new int[n1];
        int[] R=new int[n2];
        for(i=0; i<n1; i++){
            L[i]=arr[start+i];
        }
        for(j=0; j<n2; j++){
            R[j]=arr[middle+1+j];
        }
        i=0;
        j=0;
        k=start;
        while(i<n1 && j<n2){
            if(L[i]<=R[j]){
                arr[k]=L[i];
                i++;
            } else{
                arr[k]=R[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k]=R[j];
            j++;
            k++;
        }
    }
    
    public static void mergeSort(int[] arr, int start, int end){
        if(start<end){
            int middle =start+ (end-start)/2;
            mergeSort(arr, start, middle);
            mergeSort(arr, middle+1, end);
            merge(arr, start, middle, end);
        }
    }
	public static void main(String[] args) {
		int n;
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array");
        n=sc.nextInt();
        int[] arr=new int[n];
        System.out.println("Enter the elements of the array");
        for (int i = 0; i < n; i++) {
            arr[i]=sc.nextInt();
        }
		mergeSort(arr, 0, arr.length-1);
		System.out.println("After sorting");
		for (int i=0;i<arr.length ;i++ ){
		    System.out.print(arr[i]+" ");
		} 
	}
}