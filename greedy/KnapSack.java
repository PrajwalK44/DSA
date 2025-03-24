import java.util.Scanner;

public class KnapSack{
    public static void knapsackAlgo(int n, float weight[], float profit[], int capacity){
        float[] x=new float[20];
        float tp=0;
        int i, j, u;
        u=capacity;

        for (i = 0; i < n; i++) {
            x[i]=0;
        }

        for ( i = 0; i < n; i++) {
            if(weight[i]>u){
                break;
            }
            else {
                x[i]=1;
                tp=tp+profit[i];
                u=u-(int)weight[i];
            }
        }
        if(i<n){
            x[i]=u/weight[i];
        }
        tp=tp+(x[i]*profit[i]);

        System.out.println("Portion consumed for each object");
        for (i = 0; i < n; i++) {
            System.out.print(x[i]+" ");
        }
        System.out.println("Maximum Profit is "+" "+tp);
    }
    public static void main(String[] args) {
        float[] weight = new float[20];
        float[] profit = new float[20];
        int capacity, num, i, j;
        float [] ratio= new float[20];
        float temp;
        
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of objects");
        num=sc.nextInt();

        System.out.println("Enter weights and  profits of each object");
        for (i = 0; i < num; i++) {
            System.out.print("Enter object"+" "+(i+1)+" "+"weight");
            weight[i]=sc.nextInt();
            System.out.print("Enter object"+" "+(i+1)+" "+"profit");
            profit[i]=sc.nextInt();
        }
        System.out.println("Enter the capacity of knapsack");
        capacity=sc.nextInt();
        for (i = 0; i < num; i++) {
            ratio[i]=profit[i]/weight[i];
        }
        //employ bubble sort
        for (i = 0; i < num; i++) {
            for (j = i+1; j < num; j++) {
                if(ratio[i]<ratio[j]){
                    temp=ratio[j];
                    ratio[j]=ratio[i];
                    ratio[i]=temp;

                    temp=weight[j];
                    weight[j]=weight[i];
                    weight[i]=temp;

                    temp=profit[j];
                    profit[j]=profit[i];
                    profit[i]=temp;
                }
            }
            
        }
        knapsackAlgo(num, weight, profit, capacity);
        sc.close();
    }
}