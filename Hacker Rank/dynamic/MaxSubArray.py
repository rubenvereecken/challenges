__author__ = 'ruben'

def max_subarray(ar):
    max_ending_here = max_so_far = 0
    onlyNegative = True
    for x in ar:
        if x > 0:
            onlyNegative = False
        max_ending_here = max(0, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)

    if onlyNegative:
        return max(ar), max(ar)

    maxsub = 0
    for x in ar:
        if x >= 0:
            maxsub += x

    return max_so_far, maxsub

for _ in range(int(input())):
    input()
    ar = list(map(int, input().split(' ')))
    a, b = max_subarray(ar)
    print(a, b)