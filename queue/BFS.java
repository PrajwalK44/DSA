import java.util.*;

class BFS {
  
 
    static void bfs(List<List<Integer>> adj, int s) {
      
       
        Queue<Integer> q = new LinkedList<>();
        
        
        boolean[] visited = new boolean[adj.size()];
        
   
        visited[s] = true;
        q.add(s);
        

        while (!q.isEmpty()) {
          
            int curr = q.poll();
            System.out.print(curr + " ");
            
            
            for (int x : adj.get(curr)) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.add(x);
                }
            }
        }
    }

    
    static void addEdge(List<List<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u); 
    }

    public static void main(String[] args) {
        int V = 8;
        
        List<List<Integer>> adj = new ArrayList<>(V);
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        
        // Add edges to the graph
        addEdge(adj, 0, 1);
        addEdge(adj, 1, 2);
        addEdge(adj, 2, 6);
        addEdge(adj, 6, 4);
        addEdge(adj, 6, 5);
        addEdge(adj, 3, 5);
        addEdge(adj, 3, 7);
        
        // Perform BFS traversal starting from vertex 0
        System.out.println("BFS starting from 0:");
        bfs(adj, 0);
    }
}
