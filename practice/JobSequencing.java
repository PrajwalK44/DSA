import java.util.Scanner;

class JobSequencing {

    static int n;
    static String[] jobId;
    static int[] profit;
    static int[] deadline;
    static Scanner sc = new Scanner(System.in);    
        static void input(){
            System.out.println("Enter number of jobs");
            n = sc.nextInt();
            System.out.println("Enter the job id, profit and deadline for each job");
            jobId = new String[n];
            profit = new int[n];
            deadline = new int[n];
            for (int i = 0; i < n; i++) {
                jobId[i]=sc.next();
                profit[i]=sc.nextInt();
                deadline[i]=sc.nextInt();
            } 

            System.out.println("Arranged Order of Jobs: ");
        System.out.print("Jobs:     ");
        for (int i = 0; i < n; i++) {
            System.out.print(jobId[i] + " ");
        }
        System.out.println();

        System.out.print("Profit:    ");
        for (int i = 0; i < n; i++) {
            System.out.print(profit[i] + " ");
        }
        System.out.println();

        System.out.print("Deadline:   ");
        for (int i = 0; i < n; i++) {
            System.out.print(deadline[i] + " ");
        }
        System.out.println();
    }
    static void sort(){
        int temp;
        String temp1;
        for (int i = 0; i < n; i++) {
            for(int j=0; j<n-i-1; j++){
                if(profit[j]<profit[j+1]){
                    temp = profit[j];
                    profit[j]=profit[j+1];
                    profit[j+1]=temp;

                    temp = deadline[j];
                    deadline[j]=deadline[j+1];
                    deadline[j+1]=temp;

                    temp1 = jobId[j];
                    jobId[j]=jobId[j+1];
                    jobId[j+1]=temp1;
                }
            }
        }
        System.out.println();
        System.out.println("Sorted Order of Jobs: ");
        System.out.print("Jobs:     ");
        for (int i = 0; i < n; i++) {
            System.out.print(jobId[i] + " ");
        }
        System.out.println();

        System.out.print("Profit:    ");
        for (int i = 0; i < n; i++) {
            System.out.print(profit[i] + " ");
        }
        System.out.println();

        System.out.print("Deadline:  ");
        for (int i = 0; i < n; i++) {
            System.out.print(deadline[i] + " ");
        }
        System.out.println();
    }

    static void job_sequencing(){
        int max;
        int totalProfit=0;
        max=deadline[0];
        for (int i = 0; i < n; i++) {
            if(max<deadline[i]){
                max=deadline[i];
            }
        }
        String[] res = new String[max];
        for (int i = 0; i < n; i++) {
            int p=deadline[i];
            p=p-1;
            
            if(res[p]==null){
                res[p]=jobId[i];
                totalProfit+=profit[i];
            }
            else{
                while(p!=-1){
                    if(res[p]==null){
                        res[p]=jobId[i];
                        totalProfit+=profit[i];
                        break;
                    }
                    p--;
                }
            } 
            
        }
        for (int i = 0; i < max; i++) {
            System.out.print("    " + res[i]);
        }
        System.out.println();
        System.out.print("Profit Earned " + totalProfit);  

    }

    public static void main(String[] args) {
        JobSequencing jb = new JobSequencing();
        jb.input();
        jb.sort();
        jb.job_sequencing();
    }
    
}
