import java.util.Scanner;

public class Kruskal {
    int[] parent;
    int n;

    static class Edge{
        int cost, src, dest;
        Edge(int src, int dest, int cost){
            this.src = src;
            this.dest = dest;
            this.cost = cost;
        }
    }
    public Kruskal(int n){
        this.n =n;
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i]=i;
        }
    }

    public int find(int i){
        while (parent[i]!=i) {
            i=parent[i];
        }
        return i;
    }

    public boolean uni(int i, int j){
        int rootI=find(i);
        int rootJ = find(j);
        if(rootI!=rootJ){
            parent[rootJ]=rootI;
            return true;
        }
        return false;
    }

    public void kruskalAlgo(Edge[] edges){
        for (int i = 0; i < edges.length-1; i++) {
            for (int j = 0; j < edges.length-i-1; j++) {
                if(edges[j].cost>edges[j+1].cost){
                    Edge temp = edges[j];
                    edges[j]=edges[j+1];
                    edges[j+1]=temp;
                }
            }
        }

        int mincost=0;
        System.out.println("Edges in the minimum spanning tree");
        int count = 0;

        for (int i = 0; i < edges.length && count<n-1; i++) {
            Edge e = edges[i];
            if(uni(e.src, e.dest)){
                System.out.println(e.src+"-"+e.dest+":"+e.cost);
                mincost+=e.cost;
                count++;
            }
        }

        System.out.println("Minimum cost "+mincost);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices: ");    
        int n = sc.nextInt();

        System.out.println("Enter the adjacency matrix");
        int [][] cost = new int[n][n];
        int edgeCount = 0;

        for (int i = 0; i < n; i++) {
            System.out.println("Enter input for vertex "+(i+1)+": ");
            for(int j=0; j<n; j++){
                cost[i][j]=sc.nextInt();
                //checking if it is an edge (weight=0 && 1->2 is same as 2->1 hence i<j)
                if(cost[i][j]!=0 && i<j){
                    edgeCount++;
                }
            }
        }

        //store edges in the edge class
        Edge[] edges = new Edge[edgeCount];
        int idx=0;
        for (int i = 0; i < n; i++) {
            for(int j=i+1; j<n; j++){
                if(cost[i][j]!=0){
                    edges[idx]= new Edge(i, j, cost[i][j]);
                    idx++;
                }
            }
        }

        Kruskal k = new Kruskal(n);
        k.kruskalAlgo(edges);

    }
}
