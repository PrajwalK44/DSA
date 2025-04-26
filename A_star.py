import heapq


def a_star(graph, start, goal, heuristics):
    visited = set()
    open_list = [(heuristics[start], 0, start)]
    
    while open_list:
        f, g, node = heapq.heappop(open_list)
        
        if node in visited:
            continue
        print(f"Visiting {node} of heuristic: {heuristics[node]} with the cost {g} and total cost of {f}")
        visited.add(node)
        
        if node == goal:
            print(f"Goal node {node} found with the total cost {f}")
            return
        
        for neighbour, cost in graph.get(node, []):
            if neighbour not in visited:
                g_new = g+cost
                f_new = g_new + heuristics[neighbour]
                heapq.heappush(open_list, (f_new, g_new, neighbour))
    

graph = {}
n=int(input("Enter the number of nodes: "))

for _ in range(n):
    node = input("enter the node: ")
    neighbours = []
    num_neighbour = int(input(f"Enter the number of neighbours for {node}: "))
    for _ in range(num_neighbour):
        neighbour= input("Enter the neighbour node: ")
        cost = int(input(f"Enter the cost to reach from {node} to {neighbour}"))
        neighbours.append((neighbour, cost))
    
    graph[node] = neighbours

heuristics = {}
for node in graph.keys():
    heuristics[node] = int(input(f"ENter the heuristics valie of {node}: "))
    
start = input("Enter the starting node ")
goal = input("Enterh the goal node ")
a_star(graph, start, goal, heuristics)
    