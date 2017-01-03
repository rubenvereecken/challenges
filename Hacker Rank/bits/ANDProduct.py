import math

def round_down(n):
    if int(n) == n:
        return n
    else:
        return int(n)

for _ in range(int(input())):
    a, b = map(int, input().split())
    if a == 0 or b == 0 or int(math.log(a, 2)) < round_down(math.log(b, 2)):
        print(0)
    else:
        k = 0
        i = a
        j = a + 1
        while j <= b:
            a &= j

            k += 1
            j = i + 2 ** k
        a &= b
        print(a)