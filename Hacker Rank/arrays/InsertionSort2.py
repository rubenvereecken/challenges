__author__ = 'ruben'

def print_array(ar):
    for el in ar:
        print(el, end=' ')
    print()

def insertion_sort(ar):
    for vi in range(1, len(ar)):
        v = ar[vi]
        i = vi-1
        while i >= 0 and ar[i] > v:
            ar[i+1] = ar[i]
            i -= 1
        ar[i+1] = v
        print_array(ar)
    return ar

input()
ar = list(map(int, input().split(' ')))
sar = insertion_sort(ar)