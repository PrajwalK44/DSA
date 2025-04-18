import java.util.Scanner;

public class GreedyKnapsack {
    public static void knapsack(float[] profit, float[] weight, int capacity, int num){
        float tp=0;
        int u=capacity;
        float [] x = new float[num];
        int i,j;
        for(i=0; i<num; i++){
            x[i]=0.0f;
        }

        for(i=0; i<num; i++){
            if(weight[i]>u){
                break;
            }
            else{
                x[i]=1.0f;
                tp=tp+profit[i];
                u=u-(int)weight[i];
            }
        }
        if(i<num){
            x[i]=u/weight[i];    
        }
        tp=tp+profit[i]*x[i];
        System.out.println("The maximum profit is: " + tp);
        System.out.println("The fraction of each item in the knapsack is: ");
        for(i=0; i<num; i++){
            System.out.print(x[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        float[] profit = new float[20];
        float[] weight = new float[20];
        float[] ratio = new float[20];
        int capacity, num, i, j;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of items: ");
        num = sc.nextInt();
        System.out.println("Enter the capacity of the knapsack: ");
        capacity = sc.nextInt();
        System.out.println("Enter the profit and weight of each item: ");
        for (int k = 0; k < num; k++) {
            profit[k] = sc.nextFloat();
            weight[k] = sc.nextFloat();
            ratio[k] = profit[k] / weight[k];
        }
        // Sort items based on profit-to-weight ratio in descending order
        for( i=0;  i<num; i++){
            for( j=i+1; j<num; j++){
                if(ratio[i]<ratio[j]){
                    float temp = ratio[i];
                    ratio[i] = ratio[j];
                    ratio[j] = temp;

                    temp = profit[i];
                    profit[i] = profit[j];
                    profit[j] = temp;

                    temp = weight[i];
                    weight[i] = weight[j];
                    weight[j] = temp;
                }
            }  
        }
        knapsack(profit, weight, capacity, num);

    }
}
