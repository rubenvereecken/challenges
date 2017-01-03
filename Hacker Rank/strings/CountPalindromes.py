__author__ = 'ruben'

from math import sqrt

def find(n):
    s = (-1 + sqrt(1 + 8 * n)) / 2
    if s == int(s):
        return int(s)
    else:
        return int(s) + 1

'''
for _ in range(int(input())):
    k = int(input())
    minimal = find(k)
    if k % 2:
        minimal += 1
    print(minimal)
'''
