import math
from queue import PriorityQueue


def init_single_source(graph, s):
    cost = dict()
    prev = dict()

    for vertex in graph.keys():
        cost[vertex] = math.inf
        prev[vertex] = " "

    cost[s] = 0
    return cost, prev


def relax(graph, source, dest, cost, prev):
    if (cost[dest] > (cost[source] + graph[source][dest])):
        cost[dest] = cost[source] + graph[source][dest]
        prev[dest] = source
    return cost, prev

def DJ(graph, s):
    cost, prev = init_single_source(graph, s)

    PQ = PriorityQueue()
    for vertex in graph.keys():
        PQ.put((cost[vertex], vertex))

    visited = []
    while(len(visited) != len(graph.keys())):
        _, currentVertex = PQ.get()
        visited.append(currentVertex)

        for chimeki in graph[currentVertex]:
            if chimeki not in visited:
                cost, prev = relax(graph, currentVertex, chimeki, cost, prev)
                PQ.put((cost[chimeki], chimeki))
            
    return cost, prev

def reconstruct_path(graph, vertex, prev):
    path = vertex
    while prev[vertex] != " ":
        path = prev[vertex] + '->' + path
        vertex = prev[vertex]
    return path


G = {
    's':{'t': 10, 'y': 5},
    't':{'x': 1, 'y': 2},
    'x':{'z': 4},
    'y':{'t': 3, 'z': 2, 'x': 9},
    'z':{'x': 6, 's': 7}
}

s = 't'

cost, prev = DJ(G, s)

print(cost)
print(prev)

for vertex in G.keys():
    print(f"Shortest path from {s} to {vertex} is {reconstruct_path(G, vertex, prev)}")
    print(f'Cost is {cost[vertex]}')