#greedy bfs
import heapq
def greedy_bfs(graph, start, goal):
    visited = set()
    pq= [(heuristics[start], start, [start])]
    
    while pq:
        _, current, path  = heapq.heappop(pq)
        
        if current in visited:
            continue
        print(current, end=' ')
        visited.add(current)
        if current == goal:
            print("\nGoal node found ",current)
            print(f"Path: {' -> '.join(path)}")
            return
        
        for neighbour in graph.get(current, []):
            if neighbour not in visited:
                heapq.heappush(pq, (heuristics[neighbour], neighbour, path+[neighbour]))
    

graph = {}

n=int(input("Enter the number of nodes in the graph "))

for _ in range(n):
    node = input("Enter the node ")
    neighbours = input(f"Enter the neighbours of {node} ").split()
    graph[node] = neighbours

heuristics = {}
for node in graph.keys():
    heuristics[node] = int(input(f"Enter the heuristics of {node} "))

start = input("Enter the start node ")
goal = input("Enter the goal node ")

greedy_bfs(graph, start, goal)
    
