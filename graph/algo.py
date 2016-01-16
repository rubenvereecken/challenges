from graph import AMGraph, Graph, WeightedAMGraph

def topologicalSort(graph):
    visited = [False for _ in range(graph.size)]
    stack = []

    def topologicalSortVisit(v):
        visited[v] = True

        for neighbor in graph.getNeighbors(v):
            if not visited[neighbor]:
                topologicalSortVisit(neighbor)

        stack.append(v)

    for v in range(graph.size):
        if not visited[v]:
            topologicalSortVisit(v)

    return stack[::-1]

def BFS(graph, start, visit=None):
    visited = [False for _ in range(graph.size)]
    queue = [start]
    if visit is None:
        visit = lambda x: print(x)

    while len(queue) > 0:
        v = queue.pop(0)
        if visited[v]:
            continue
        visit(v)
        visited[v] = True
        for neighbor in graph.getNeighbors(v):
            queue.append(neighbor)

def dijkstra(g, s):
    """
    Computes shortest past from source vertex to every other vertex
    graph must be a weighted undirected graph
    """
    # dist = [float('inf') for _ in range(graph.size)]
    # dist[s] = 0
    from queue import PriorityQueue

    # This is to keep easy track of v -> distance
    visited = [[[False, float('inf')], x] for x in range(g.size)]
    visited[s][0][1] = 0

    # The idea behind using a PQueue is that it can be faster if implemented
    # with a heap. The items are ((visited, distance), v). This way the
    # unvisited will always come up first, ordered by distance. The lowest key
    # will therefore be exactly what we want
    # This makes every lookup O(|V|), keeping it balanced
    # If the heap were built efficiently that'd just be O(|V|), but the way I
    # built it it's just O(|V|log|V|) since I do consecutive inserts
    q = PriorityQueue()
    for item in visited:
        q.put_nowait(item)

    closest = lambda: q.get_nowait()

    # Result is O(|E| + |V|log|V|) since we're handling every edge once and
    # the heapify occurs only |V| times, i.e. until the we handled all vertices
    for _ in range(g.size - 1):
        u = closest()
        u[0][0] = True
        if u[0][1] == float('inf'):
            continue
        print(g.getNeighbors(u[1]))
        for neighbor in g.getNeighbors(u[1]):
            v = visited[neighbor]
            distance = u[0][1] + g.m[u[1]][v[1]]
            if not v[0][0] and distance < v[0][1]:
                v[0][1] = distance

    
    return [entry[0][1] for entry in visited]


if __name__ == '__main__':
    g = AMGraph(6)
    g.addEdge(5,2)
    g.addEdge(5,0)
    g.addEdge(2,3)
    g.addEdge(3,1)
    g.addEdge(4,0)
    g.addEdge(4,1)
    ### TOPOLOGICAL SORTJ
    # print(topologicalSort(g))
    ### BFS
    # bfsOrder = []
    # appendor = lambda x: bfsOrder.append(x)
    # BFS(g, 5, appendor)
    # print(bfsOrder)
    ### Dijkstras
    # graph from http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
    m = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
        [4, 0, 8, 0, 0, 0, 0, 11, 0],
        [0, 8, 0, 7, 0, 4, 0, 0, 2],
        [0, 0, 7, 0, 9, 14, 0, 0, 0],
        [0, 0, 0, 9, 0, 10, 0, 0, 0],
        [0, 0, 4, 0, 10, 0, 2, 0, 0],
        [0, 0, 0, 14, 0, 2, 0, 1, 6],
        [8, 11, 0, 0, 0, 0, 1, 0, 7],
        [0, 0, 2, 0, 0, 0, 6, 7, 0]]
    print(dijkstra(WeightedAMGraph.fromMatrix(m), 0))
