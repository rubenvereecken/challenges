'''
Created on Dec 27, 2011

@author: ruben
'''
import sys

fac = {}

def facultory (num):
    if num <= 1: return 1
    elif num not in fac:
        fac[num] = facultory (num - 1) * num
    return fac[num]


    
def is_curious (num):
    total = 0
    for i in str(num):
        total += facultory (int(i))
    return total == num


if __name__ == '__main__':
    sys.setrecursionlimit(2000)
    curiousList = []
    for i in range(3, 1000000):
        if is_curious(i):
            print('Found new curious number:', i)
            curiousList.append(i)
            print('Sum so far:', sum(curiousList))