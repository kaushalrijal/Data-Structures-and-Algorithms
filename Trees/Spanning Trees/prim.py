import math
from queue import PriorityQueue

graph = {
    'a': {
        'b': 1,
        'd': 4
    },
    'b': {
        'a': 1,
        'c': 3, 
        'e': 3
    },
    'c': {
        'b': 3,
        'e': 1, 
        'f': 2
    },
    'd': {
        'a': 4,
        'e': 1,
    },
    'e': {
        'c': 1,
        'd': 1,
        'f': 4
    },
    'f': {
        'c': 2,
        'e': 4
    }
}

def init_graph(graph, start):
    key = dict()
    parent = dict()

    for vertex in graph.keys():
        key[vertex] = math.inf
        parent[vertex] = None
    
    key[start] = 0

    return key, parent

def prim(graph, start):
    key, parent = init_graph(graph, start)

    q = PriorityQueue()
    queue_items = []

    for vertex in graph.keys():
        q.put((key[vertex], vertex))
        queue_items.append(vertex)
    

    while not q.empty():
        _, temp = q.get()
        for neighbor in graph[temp].keys():
            weight = graph[temp][neighbor]
            if (neighbor in queue_items) and (weight < key[neighbor]):
                parent[neighbor] = temp
                key[neighbor] = weight
            
    return key, parent

s = 'a'
key, parent = prim(graph, s)

print(key)
print(parent)