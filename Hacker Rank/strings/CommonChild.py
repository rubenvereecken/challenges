
def longest_child_length(a, b):
    m = [[0 for _ in range(len(b)+1)] for _ in range(len(a)+1)]
    sofar = 0

    for i in range(1, len(a)+1):
        for j in range(1, len(b)+1):
            current = int(a[i-1] == b[j-1])
            if current:
                previous = m[i-1][j-1]
            else:
                previous = max(m[i-1][j], m[i][j-1])
            current += previous
            m[i][j] = current
            if current > sofar:
                sofar = current

    return sofar


a = input()
b = input()
print(longest_child_length(a, b))