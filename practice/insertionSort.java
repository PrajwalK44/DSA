import java.util.Scanner;

public class insertionSort {
    public static void insertion_sort(int[] nums){
        int n=nums.length;
        for (int i = 1; i < n; i++) {
            int key=nums[i];
            int j=i-1;
            while(j>-1 && nums[j]>key){
                nums[j+1]=nums[j];
                j=j-1;
                for(int k=0; k<n; k++){
                    System.out.println(nums[k]+" ");
                }
            }
            nums[j+1]=key;
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the size of the array");
        int n=sc.nextInt();
        System.out.println("Enter the elements of the array");
        int nums[]=new int[n];
        for (int i = 0; i < n; i++) {
            nums[i]=sc.nextInt();
        }
        insertion_sort(nums);
        System.out.println("The sorted array is:");
        for (int i = 0; i < n; i++) {
            System.out.print(nums[i]+" ");
        }
        sc.close();
    }
}
