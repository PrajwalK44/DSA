// selection sort

import java.util.Scanner;

public class selectionSort{
    public static void selection_sort(int[] nums){
        int n=nums.length;
        for(int i=0; i<n-1; i++){
            int min=i;
            for(int j=i+1; j<n; j++){
                if(nums[j]<nums[min]){
                    min=j;
                }
            }
            int temp=nums[min];
            nums[min]=nums[i];
            nums[i]=temp;
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
        selection_sort(nums);
        System.out.println("The sorted array is:");
        for (int i = 0; i < n; i++) {
            System.out.print(nums[i]+" ");
        }
        sc.close();
    }
}