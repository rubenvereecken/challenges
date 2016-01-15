import itertools
from graph.graph import AJGraph as Graph

def flatten(listOfLists):
    "Flatten one level of nesting"
    return itertools.chain.from_iterable(listOfLists)

# http://www.careercup.com/question?id=15380670
def findBasinSizes(m):
    # The goal is to find a forest
    s = len(m)
    visited = [[None for _ in range(s)] for _ in range(s)]

    def getNeighbors(x, y):
        n = []
        if y > 0:
            n.append((x,y-1))
        if y < s - 1:
            n.append((x,y+1))
        if x > 0:
            n.append((x-1,y))
        if x < s - 1:
            n.append((x+1,y))
        return n
                    
    # The below code, both DFS and the main loop, work as follows
    # Every time you start a DFS you create a graph and take that on your
    # journey. Keep adding edges onto that as you flow down towards the sink.
    # As soon as you encounter a node that is already part of some tree, merge
    # the newer tree into the older one and call quits. This way all trees will
    # merge into the resulting basins. All that's left is to fetch their sizes.
    # Problem: Merging is a bit on the expensive side. It's looking ok though.

    def DFS(x, y, gp):
        visited[x][y] = gp
        val = m[x][y]
        neighbors = getNeighbors(x,y)
        lowest = min(map(lambda cell: (cell, m[cell[0]][cell[1]]), neighbors),
                key=lambda neigh: neigh[1])
        (nextX, nextY), lowestVal = lowest
        if lowestVal > m[x][y]:
            print ('sink at', x, y)
        else:
            existingTreeP = visited[nextX][nextY]
            # Join the two trees 
            if existingTreeP:
                # Just my hack to have pointers in Python
                existingTree = existingTreeP[0]
                gp[0] = existingTree
                existingTree.merge(g)
                existingTree.addEdge((x,y), (nextX, nextY))
            else:
                gp[0].addVertex((nextX, nextY))
                gp[0].addEdge((x,y), (nextX, nextY))
                DFS(nextX, nextY, gp)


    for x, row in enumerate(m):
        for y, cell in enumerate(row):
            # Perform a DFS on every heretofore unvisited node
            if visited[x][y] is None:
                g = Graph()
                g.addVertex((x, y))
                DFS(x, y, [g])

    forest = set(gp[0] for gp in flatten(visited))
    basinSizes = sorted((len(tree) for tree in forest), reverse=True)
    return basinSizes


if __name__ == '__main__':
    m = []
    s = int(input())
    for _ in range(s):
        m.append(list(map(int, input().split(' '))))
    print(findBasinSizes(m))
