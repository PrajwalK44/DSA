def dfs(graph, node, goal, visited=None):
    if visited is None:
        visited = set()

    if node not in visited:
        print(node, end=' ')
        if node == goal:
            print("\nGoal node found:", node)
            return True  # Stop search
        visited.add(node)
        for neighbor in graph[node]:
            if dfs(graph, neighbor, goal, visited):  # Stop further calls if goal found
                return True
    return False  # Goal not found from this path

# Taking dynamic input
graph = {}
n = int(input("Enter number of nodes: "))

for _ in range(n):
    node = input("Enter node name: ")
    neighbors = input(f"Enter neighbors of {node} (space-separated): ").split()
    graph[node] = neighbors

start_node = input("Enter start node: ")
goal_node = input("Enter goal node: ")

print("\nBFS Traversal:")
dfs(graph, start_node, goal_node)
