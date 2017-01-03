from functools import reduce
from itertools import combinations

n, m = map(int, input().split(' '))
ins = [input() for _ in range(n)]
topicsmap = {}
maxtopics = 0

for a, b in combinations(ins, 2):
    topics = reduce(lambda x, y: x + ('1' in [y[0], y[1]]), zip(a, b), 0)
    #print(topics, ins[i], ins[j])
    topicsmap[topics] = topicsmap.get(topics, 0) + 1
    if topics > maxtopics:
        maxtopics = topics

print(maxtopics)
print(topicsmap[maxtopics])