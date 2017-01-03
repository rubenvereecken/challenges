'''
Created on Dec 30, 2011

@author: ruben
'''

from PrimeSieve import find_primes_until
from itertools import combinations

primes = find_primes_until(1000000)
factors = {}


def trial_division (n):
    """Return a list of the prime factors for a natural number."""
    if n == 1: return [1]
    
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
    if n in factors: return factors[n]
    prime_factors = trial_division(n)
    complete_factors = clean_duplicates(prime_factors) + [1]
    for i in range(2, len(prime_factors) + 1):
        for j in combinations(prime_factors, i):
            prod = product(j)
            if prod not in complete_factors: complete_factors.append(prod)
    complete_factors.sort()
    factors[n] = complete_factors
    return complete_factors


def is_relatively_prime(first, second):
    first_factors = complete_factors(first)[1:]
    second_factors = complete_factors(second)[1:]
    for i in first_factors:
        if i in second_factors: return False
    return True


def phi(n):
    phi = 0
    for i in range(1, n):
        if is_relatively_prime(i, n): phi += 1
    return phi

if __name__ == '__main__':
    m = 0
    largest = 0
    for i in range(700000, 1000001):
        print(i)
        p = phi(i)
        if (i/p) > m: 
            m = i/p
            largest = i
    print('Found the number', i, 'with phi', m)
    