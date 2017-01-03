'''
Created on Dec 29, 2011

@author: ruben
'''

def factorial(number):
    total = 1
    if number == 0:
        return 1
    else:
        total *= number
        total *= factorial(number - 1)
        
    return total
    

def is_prime(number):
    if number <= 1:         # 1 Can't be a prime number
        return False
    elif factorial(number - 1) % number == number - 1:
        return True
    else:
        return False


if __name__ == '__main__':
    pass