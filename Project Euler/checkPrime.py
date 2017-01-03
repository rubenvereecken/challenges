'''
Created on Nov 3, 2011

@author: Ruben Vereeckens
'''

def factorial(number):
    '''
    An adapted version of the factorial function from ex5.py,
    not using the recursive definition. This does not result
    in Python complaining about recursion depths (if the
    required depth is now known beforehand)
    '''
    total = 1
    
    for i in range(2, number + 1):
        total *= i
        
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
