__author__ = 'ruben'


"""
Find all pairs that sum <= k
"""


def find_first_smaller_than(array, k):
    start = 0
    end = len(array) - 1  # inclusive

    if k > array[end]:
        return end
    elif k < array[start]:
        return -1

    while start < end:
        m = (start + end) // 2
        if array[m] >= k:
            end = m
        else:  # elif array[m] <= k:
            start = m + 1

    return start - 1

def find_smaller_pairs(array, k):
    array.sort()  # n logn
    p = find_first_smaller_than(array, k)
    s = 0

    while s < p:
        while s < p:
            if array[s] + array[p] < k:
                yield (array[s], array[p])
                s += 1
            else:
                break
        p -= 1
        s = 0



if __name__ == '__main__':
    a = [0, 0, 0, 2, 2, 3, 4, 4, 4, 4, 4, 5]
    b = [1, 3, 5, 9, 20, 28, 30, 37, 60, 100 ]
    print(find_first_smaller_than(a, 4))
    print(find_first_smaller_than(a, 5))
    print(find_first_smaller_than(a, 6))
    print(list(find_smaller_pairs(b, 50)))
