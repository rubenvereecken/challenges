for _ in range(int(input())):
    k = int(input())
    n = int(input())
    ar = list(map(int, input().split(' ')))

    table = {}
    for i, v in enumerate(ar):
        if table.get(v):
            table[v].append(i+1)
        else:
            table[v] = [i+1]

    if k % 2 == 0 and table.get(k/2) and len(table[k/2]) >= 2:
        print(table[k/2][0], table[k/2][1])
    else:
        for v in table.keys():
            #print(v, k-v, table.get(k-v) if table.get(k-v) else '')
            if v * 2 == k:
                continue
            if table.get(k-v):
                lower = table[v][0] if table[v][0] < table[k-v][0] else table[k-v][0]
                higher = table[v][0] if table[v][0] >= table[k-v][0] else table[k-v][0]

                print(table[v][0], table[k-v][0])
                break