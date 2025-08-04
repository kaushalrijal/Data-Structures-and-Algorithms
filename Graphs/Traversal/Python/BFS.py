from collections import deque

graph = {
    'A': ['B', 'C'],
    'B': ['A', 'C'],
    'C': ['A', 'B', 'D'],
    'D': ['C', 'E', 'F'],
    'E': ['D', 'F'],
    'F': ['D', 'E']
}

def BFS(graph, start):
    visited = []
    queue = deque()

    queue.append(start)
    while not len(queue) == 0:
        temp = queue.popleft()
        visited.append(temp)

        for node in graph[temp]:
            if (not node in queue) and (not node in visited):
                queue.append(node)
        
    print("The order of traversal is:")
    traversal_order = start
    for item in visited[1:]:
        traversal_order += " -> " + item
    
    print(traversal_order)

BFS(graph, 'A')