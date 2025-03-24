import java.util.Scanner;

public class knapsack{
    public static void knapsackAlgo(float[] profit, float[] weight, float[] ratio, int cap, int n){
        float[] x = new float[20];
        int u = cap;
        int i;
        float totalProfit = 0;
        for ( i = 0; i < n; i++) {
            x[i]=0;
        }

        for ( i = 0; i < n; i++) {
            if(weight[i]>u){
                break;
            }
            else{
                x[i]=1;
                totalProfit+=profit[i];
                u=(int)(u-weight[i]);
            }
            
        }
        if(i<n){
            x[i]=u/weight[i];
            totalProfit+=x[i]*profit[i];
        }
        System.out.println("The max profit is: "+totalProfit);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n; //no of objects
        int cap; //cap of knapsack
        float[] profit = new float[20];
        float[] weight = new float[20];
        float[] ratio = new float[20];
        System.out.println("Enter the number of objects: ");
        n = sc.nextInt();
        System.out.println("Enter the capacity of knapsack");
        cap = sc.nextInt();
        System.out.println("Enter the profit and weight of each object");   
        for (int i = 0; i < n; i++) {
            profit[i]=sc.nextFloat();
            weight[i]=sc.nextFloat();
        }

        for (int i = 0; i < n; i++) {
            ratio[i]=profit[i]/weight[i];
        }
        float temp;
        //sort
        for (int i = 0; i < n; i++) {
            for(int j=0; j<n-i-1; j++){
                if(ratio[j]<ratio[j+1]){
                    temp = ratio[j];
                    ratio[j]=ratio[j+1];
                    ratio[j+1]=temp;

                    temp = profit[j];
                    profit[j]=profit[j+1];
                    profit[j+1]=temp;

                    temp = weight[j];
                    weight[j]=weight[j+1];
                    weight[j+1]=temp;
                }
            }
        }

        knapsackAlgo(profit, weight, ratio, cap, n);

    }
}