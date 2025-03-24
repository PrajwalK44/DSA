import java.util.Scanner;

public class MinMax {
    static int min, max;
    public static void minMax(int[] nums, int i, int j){
        if(i==j){
            min=max=nums[i];
        }
        else if (i==j-1){
            if(nums[i]>nums[j]){
                max=nums[i];
                min=nums[j];
            } else{
                max=nums[j];
                min=nums[i];
            } 
        }
        else{
            int max1, min1;
            int mid=(i+j)/2;
            minMax(nums, i, mid);
            max1=max;
            min1=min;
            minMax(nums, mid+1, j);
            if(max< max1){
                max=max1;
            }
            if(min>min1){
                min=min1;
            }
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
        minMax(nums, 0, n-1);
        // System.out.println("The sorted array is:");
        // for (int i = 0; i < n; i++) {
        //     System.out.print(nums[i]+" ");
        // }
        System.out.println("Minimum value: " + min);
        System.out.println("Maximum value: " + max);

        sc.close();
    }
}