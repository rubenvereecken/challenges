n, k = map(int, input().split(' '))
flowers = sorted(map(int, input().split(' ')))[::-1]

cost = 0
for i, flower in enumerate(flowers):
    cost += ((i // k) + 1) * flower

print(cost)