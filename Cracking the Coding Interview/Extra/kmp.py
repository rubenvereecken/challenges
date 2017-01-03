__author__ = 'ruben'

"""
http://en.wikipedia.org/wiki/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm
"""


def failure_function(s):
    T = [0 for x in range(len(s))]
    if len(s) <= 2:
        return T
    T[0] = -1

    cnd = 0
    pos = 2
    while pos < len(s):
        if s[pos-1] == s[cnd]:
            cnd += 1
            T[pos] = cnd
            pos += 1
        elif cnd > 0:
            cnd = T[cnd]
        else:
            T[pos] = 0
            pos += 1
    return T


def kmp_search(S, W):
    m = 0
    i = 0
    T = failure_function(W)

    while m + i < len(S):
        if W[i] == S[m + i]:
            if i == len(W) - 1:  # string matched
                return m
            i += 1  # char matched, continuing
        else:
            if T[i] > -1:  # table says we have a partial match
                m = m + i - T[i]
                i = T[i]
            else:  # no character match whatsoever, continue
                i = 0
                m += 1
    return -1


if __name__ == '__main__':
    print(failure_function("aabbaaba"))
    print(kmp_search("there's a banana in the tree", "banana"))