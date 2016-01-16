from functools import reduce

class Graph(object):
    def __init__(self):
        pass

    @classmethod
    def fromMatrix(cls, m):
        g = cls(len(m))
        g.m = m
        return g


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


class WeightedAMGraph(AMGraph):
    def __init__(self, size, directed=True):
        self.size = size
        # [row, column]
        self.m = [[0 for _ in range(size)] for _ in range(size)]
        self.directed = directed

    def __str__(self):
        concat = lambda s, row: s + ' '.join(map(str, row)) + '\n'
        return reduce(concat, self.m, '')

    def addEdge(self, u, v, weight):
        self.m[u][v] = weight
        if not self.directed:
            self.m[v][u] = weight


class AJGraph(Graph):
    def __init__(self, size=0, directed=True):
        self.size = size
        self.vertices = []
        self.adjacency = {}

    def addVertex(self, key):
        self.vertices.append(key);
        self.size += 1

    def addEdge(self, u, v):
        l = self.adjacency.get(repr(u))
        if not l is None:
            l.append(repr(v))
        else:
            self.adjacency[repr(u)] = [repr(v)]

    def merge(self, g):
        self.vertices = self.vertices + (g.vertices)
        self.size = len(self.vertices)
        for key, val in g.adjacency.items():
            self.adjacency[key] = val
        return self

    def getVertices(self):
        return [eval(x) for x in self.vertices]

    def __len__(self):
        return self.size



if __name__ == '__main__':
    graph = AMGraph(6)
    graph.addEdge(2, 3)
    print(str(graph))
