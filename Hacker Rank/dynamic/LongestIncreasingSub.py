__author__ = 'ruben'

def len_longest_increasing_subsequence(ar):
    max = 1
    current = 0
    last = -float('infinity')
    for el in ar:
        if el >= last:
            current += 1
            last = el
        else:
            if current > max:
                max = current
            current = 0
            last = -float('infinity')
    return max

ar = []
n = int(input())
for _ in range(n):
    ar.append(int(input()))
print(len_longest_increasing_subsequence(ar))