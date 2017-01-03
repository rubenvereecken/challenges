def swap(ar, i, j):
    t = ar[i]
    ar[i] = ar[j]
    ar[j] = ar[i]

def print_array(ar):
    for el in ar:
        print(el, end=' ')
    print()

def partition(ar, p):
    swap(ar, 0, p)
    v = ar[0]
    low = []
    high = []
    for el in ar[1:]:
        if el < v:
            low.append(el)
        else:
            high.append(el)
    return low + [v] + high

n = int(input())
ar = list(map(int, input().split(' ')))
print_array(partition(ar, 0))