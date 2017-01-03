n = int(input())
ar = sorted(list(map(int, input().split(' '))))

last = ar[0]
count = 0

if len(ar) > 1:
    for i, el in enumerate(ar[1:]):
        if el > last + 4:
            count += 1
            last = el
    print(count+1)
else:
    print(1)