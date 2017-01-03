__author__ = 'ruben'

def near_knapsack_rep(array, k):
    close = []

    for el in array:
        print(el)
        if el > k:
            break
        mod = k % el
        if mod == 0:
            return k
        close.append(k-el)
        for i in range(len(close)-1):
            if close[i] - el == 0:
                return k
            elif close[i] - el > 0:
                close.append(close[i] - el)

    return close


for _ in range(int(input())):
    n, k = map(int, input().split(' '))
    array = map(int, input().split(' '))
    result = near_knapsack_rep(array, k)
    print(result)