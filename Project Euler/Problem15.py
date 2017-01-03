'''
Created on Dec 29, 2011

@author: ruben
'''

def factorial (n):
    if n <= 1: return 1
    else: return n * factorial (n - 1)


if __name__ == '__main__':
    print('Amount of possibilities in a 20 x 20 grid is (40 20) =', int(factorial(40)/(factorial(20) * factorial(20))))