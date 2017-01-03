def amount_of_combinations(total, coins, values):
    if total < 0:
        return 0
    if len(coins) == 0:
        return 0

    n = 0
    for i in range(coins[0]+1):
        v = values[0] * i
        if v == total:
            n += 1
            break
        elif v > total:
            break
        else:
            n += amount_of_combinations(total - values[0] * i, coins[1:], values[1:])
    return n

for _ in range(int(input())):
    n = int(input())
    coins = list(map(int, input().split(' ')))
    print(amount_of_combinations(n, coins, [1, 2, 5, 10]))