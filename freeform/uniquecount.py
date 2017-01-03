__author__ = 'ruben'


# array is expected to be sorted
def findLastIndex(array, n):
    start = 0
    end = len(array) - 1

    while start <= end:
        m = (start+end) // 2
        if array[m] == n and (m == end or array[m+1] != n):
            return m
        elif array[m] <= n:
            start = m + 1
        else:
            end = m

    return -1


def count_uniqes(array):
    start = 0
    end = len(array)
    counts = {}

    while start < end:
        current = array[start]
        nextIndex = start + findLastIndex(array[start: end], current) + 1
        counts[current] = nextIndex - start
        start = nextIndex

    return counts



if __name__ == '__main__':
    a = [0, 0, 0, 2, 2, 3, 4, 4, 4, 4, 4, 5]

    #print(findLastIndex(a, 5))
    print(count_uniqes(a))