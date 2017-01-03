__author__ = 'ruben'

from itertools import *

def is_palindrome(s):
    n = len(s)
    for i in range(n // 2):
        if s[i] != s[n-i-1]:
            return False
    return True

def perms(s):
    return list(set(map(lambda x: ''.join(x), list(permutations(s)))))

def amount_of_palindrome_perms(s):
    return sum([1 for p in perms(s) if is_palindrome(p)])

print(amount_of_palindrome_perms('aab'))
