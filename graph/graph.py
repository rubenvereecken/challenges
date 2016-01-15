from functools import reduce

class Graph(object):
    def __init__(self):
        pass


class AMGraph(Graph):

    def __init__(self, size, directed=True):
        self.size = size
        # [row, column]
        self.m = [[False for _ in range(size)] for _ in range(size)]
        self.directed = directed

    def __str__(self):
        concat = lambda s, row: s + \
            ' '.join(map(lambda b: '1' if b else '0', row)) + '\n'
        return reduce(concat, self.m, '')

    def addEdge(self, u, v):
        self.m[u][v] = True
        if not self.directed:
            self.m[v][u] = True

    def removeEdge(self, u, v):
        self.m[u][v] = False
        if not self.directed:
            self.m[v][u] = False

    def getNeighbors(self, v):
        return [x for x, edge in enumerate(self.m[v]) if edge]



if __name__ == '__main__':
    graph = AMGraph(6)
    graph.addEdge(2, 3)
    print(str(graph))
