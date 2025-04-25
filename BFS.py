from collections import deque
def bfs(graph, start, goal):
    visited = set()
    queue = deque([start])
    while queue:
        node = queue.popleft()
        if node not in visited:
            print(node, end=' ')
            if node == goal:
                print("\nGoal node found:", node)
                return
            visited.add(node)
            queue.extend(graph[node])
    print("\nGoal node not found.")

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
bfs(graph, start_node, goal_node)
