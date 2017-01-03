for _ in range(int(input())):
    n, k = list(map(int, input().split(' ')))
    a = sorted(map(int, input().split(' ')))
    b = sorted(map(int, input().split(' ')))[::-1]
    yes = True
    for va, vb in zip(a, b):
        if va + vb < k:
            yes = False
            break
    print("YES" if yes else "NO")