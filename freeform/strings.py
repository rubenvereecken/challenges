__author__ = 'ruben'


def longest_common_substring(A, B):
    m = [[0 for _ in range(len(B)+1)] for _ in range(len(A)+1)]
    max = 0
    b_i = 0

    for i in range(len(A)):
        for j in range(len(B)):
            if A[i] == B[j]:
                m[i+1][j+1] = m[i][j] + 1
                max = m[i+1][j+1] if m[i+1][j+1] > max else max
                b_i = j
            else:
                m[i+1][j+1] = 0
    return B[b_i - max + 1: b_i + 1]


if __name__ == '__main__':
    print longest_common_substring('abcab', 'bcab')
    print longest_common_substring('monster', 'hag')
    print longest_common_substring('cabbage', 'manbag')
