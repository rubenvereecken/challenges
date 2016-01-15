from graph import AMGraph

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
                

if __name__ == '__main__':
    g = AMGraph(6)
    g.addEdge(5,2)
    g.addEdge(5,0)
    g.addEdge(2,3)
    g.addEdge(3,1)
    g.addEdge(4,0)
    g.addEdge(4,1)
    print(str(g))
    print(topologicalSort(g))
