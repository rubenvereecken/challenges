'''
Created on Dec 29, 2011

@author: ruben
'''

from PrimeSieve import find_primes_until
from itertools import combinations


def trial_division (n):
    """Return a list of the prime factors for a natural number."""
    if n == 1: return [1]
    primes = find_primes_until(int(n**0.5) + 1)
    prime_factors = []
 
    for p in primes:
        if p*p > n: break
        while n % p == 0:
            prime_factors.append(p)
            n //= p
    if n > 1: prime_factors.append(n)
 
    return prime_factors

        
def product (someList):
    result = 1
    for i in someList:
        result *= i
    return result


def clean_duplicates (lst):
    clean = []
    for i in lst: 
        if i not in clean: clean.append(i)
    return clean


def complete_factors (n):
    prime_factors = trial_division(n)
    complete_factors = clean_duplicates(prime_factors) + [1]
    for i in range(2, len(prime_factors) + 1):
        print(i)
        for j in combinations(prime_factors, i):
            prod = product(j)
            if prod not in complete_factors: complete_factors.append(prod)
    complete_factors.sort()
    return complete_factors


if __name__ == '__main__':
    print(complete_factors(9))