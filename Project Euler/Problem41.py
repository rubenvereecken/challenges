'''
Created on Dec 29, 2011

@author: ruben
'''

from PrimeSieve import find_primes_until

def is_pandigital (num):
    strnum = str(num)
    for i in range(1, len(strnum) + 1):
        if str(i) not in strnum: return False
    return True


if __name__ == '__main__':
    lotsOfPrimes = find_primes_until(10000000)
    for i in lotsOfPrimes:
        if is_pandigital(i): print('Lookie here, a pandigital prime:', i)