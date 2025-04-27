#UCS
import heapq
def ucs(graph, start, goal):
    visited = set()
    pq = [(0, start, [start])]
    
    while pq:
        cost, node, path = heapq.heappop(pq)
        
        if node in visited:
            continue
        
        print(f"Visiting node {node} Cost: {cost}")
        visited.add(node)
        
        if node == goal:
            print("\nGoal node found!")
            print(f"Path: {' -> '.join(path)}")
            print(f"Total cost: {cost}")
            return  # exit after finding the goal
        
        for neighbour, edge_cost in graph.get(node, []):
            if neighbour not in visited:
                heapq.heappush(pq, (cost+edge_cost, neighbour, path+[neighbour]))


graph = {}

n=int(input("Enter the number of nodes in the graph "))

for _ in range(n):
    node = input("Enter the node ")
    neighbours = []
    num_neighbours = int(input(f"Enter the number of neighbours of {node}"))
    for _ in range(num_neighbours):
        neighbour = input(f"Enter the neighbour of {node} ")
        edge_cost = int(input(f"Enter the cost from {node} to {neighbour} "))
        neighbours.append((neighbour, edge_cost))
    graph[node] = neighbours

start = input("Enter the starting node ")
goal = input("Enter the goal node ")
ucs(graph, start, goal)
