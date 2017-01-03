__author__ = 'ruben'


def search(array, n):
    l = 0
    h = len(array)
    while l < h:
        # m = (l + h) // 2 # may cause overflow
        m = (h - l) // 2 + l
        print l, m, h
        if array[m] == n:
            return m
        elif array[m] < n:
            l = m + 1
        else:
            h = m
    return -1


if __name__ == '__main__':
    a = list(range(6))
    print(search(a, 6))
    print(search(a, -1))
    print(search(a, 5))
    print(search(a, 0))
    print(search(a, 3))
    print(search(range(3), 2))