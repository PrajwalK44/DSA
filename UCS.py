import heapq

def ucs(graph, start, goal):
    visited = set()
    pq=[(0, start)]
    
    while pq:
        cost, node = heapq.heappop(pq)
        
        if node in visited:
            continue
        print(f"Visiting node {node}, Cost: {cost}")
        visited.add(node)    
        
        if node == goal:
            print(f"Goal node {node} found with cost {cost}")
            return
        
        for neighbour, edge_cost in graph.get(node, []):
            if neighbour not in visited:
                heapq.heappush(pq, (cost+edge_cost, neighbour))

graph={}
n=int(input("Enter the numebr of nodes in the graphh"))

for _ in range(n):
    node = input("Enter the node: ")
    neighbours = []
    num_neighbours = int(input("Enter the number of neighbours: "))
    
    for _ in range(num_neighbours):
        neighbour = input("Enter the neihgbor")
        edge_cost = int(input(f"Enter the cost from {node} to {neighbour} "))
        neighbours.append((neighbour, edge_cost))
    
    graph[node] = neighbours

start = input("Enter the start node ")
goal = input("Enter the goal node")

ucs(graph, start, goal)