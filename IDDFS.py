def dls(graph, node, depth, goal):
    print(node, end=" ")
    
    if node == goal:
        return True
    
    if depth==0:
        return False
    
    for neighbour in graph.get(node, []):
        if dls(graph, neighbour, depth-1, goal):
            return True
    
    return False

def iddfs(graph, start, depth, goal):
    for d in range(depth+1):
        print(f"Depth level {d}", end="\n")
        
        if(dls(graph, start, d, goal)):
            print(f"Goal found at depth {d}")
            return


graph = {}
n=int(input("Enter the number of nodes "))

for _ in range(n):
    node = input("Enter the node ")
    neighbours = input("Enter the neighboours ").split()
    graph[node]=neighbours

depth = int(input("Enter the maximum depth of the tree"))
start=input("Enter the starting node ")
goal=input("Enter the goal node ")
iddfs(graph, start, depth, goal)