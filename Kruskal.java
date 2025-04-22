import java.util.Scanner;
public class Kruskal{
    int[][] cost;
    int[]parent;
    int n;
    public Kruskal(int[][] cost, int n){
        this.n=n;
        this.cost=cost;
        parent=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
    }
    public int find(int i){
        while(parent[i]!=i){
            i=parent[i];
        }
        return i;
    } 
    public boolean union(int i, int j){
        int rooti=find(i);
        int rootj=find(j);
        if(rooti!=rootj){
            parent[rootj]=rooti;
            return true;
        }
        return false;
    }
    public void algo(){
        int mincost=0;
        for(int count=0;count<n-1;count++){
            int min=Integer.MAX_VALUE;
            int u=-1;
            int v=-1;
            for(int i=0; i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][j]<min&&cost[i][j]!=0&&find(i)!=find(j)){
                        min=cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
            if(u!=-1&&v!=-1&&union(u,v)){
                System.out.println(u+"-"+v+":"+min);
                mincost+=min;
            }
            
        }
        System.out.println("Minimum cost:"+mincost);
        
    }
    public static void main(String[] args){
        System.out.println("Enter the number of vertices:");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[][] cost=new int[n][n];
        System.out.println("Enter the adjacency matrix:");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cost[i][j]=sc.nextInt();
            }
        }
        Kruskal k=new Kruskal(cost, n);
        k.algo();
    }   
}
