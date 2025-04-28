#astar
import heapq
def a_star(graph, start, goal, heuristics):
    visited = set()
    open_list = [(heuristics[start], 0, start, [start])]
    
    while open_list:
        f, g, node, path = heapq.heappop(open_list)
        
        if node in visited:
            continue
        print(f"Visiting node {node} of heuristics: {heuristics[node]} of cost {g}")
        visited.add(node)
        if node == goal:
            print("\nGoal found")
            print(f"Path: {' -> '.join(path)}")
            print("Total cost ",cost)
            return
        
        for neighbour, cost in graph.get(node, []):
            if neighbour not in visited:
                g_new = g+cost
                f_new = g_new+ heuristics[neighbour]
                heapq.heappush(open_list, (f_new, g_new, neighbour, path+[neighbour]))


graph = {}
n=int(input("Enter the number of nodes "))

for _ in range(n):
    node = input("Enter the node ")
    neighbours = []
    num_neighbours = int(input("Enter the number of neighbours "))
    
    for _ in range(num_neighbours):
        neighbour = input("Enter the neighbour ")
        cost = int(input(f"Enter the cost from {node} to {neighbour}"))
        neighbours.append((neighbour, cost))
    graph[node] = neighbours

heuristics = {}
for node in graph.keys():
    heuristics[node] = int(input(f"Enter the heuristics value for {node}"))

start = input("Enter the starting node ")
goal = input("Enter the goal node ")

a_star(graph, start, goal, heuristics)
