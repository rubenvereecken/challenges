'''
Created on Nov 6, 2011

@author: Ruben Vereecken
'''
from PrimeSieve import find_primes_until
from checkPrime import is_prime


def check_trunc(num):
    '''
    In order to save on unnecessary operations, I used a rather different approach:
    Instead of peeling off the numbers from left to right and vice versa, comparing
    the bigger numbers and afterwards the smaller ones, I changed it. The remove
    function will first check on the very first level (1-digit number) for both
    left and right side, and will peel the number back up as we go along. 
    This because it is easier and faster to reject a smaller number than a fairly large one,
    so analyzing the number 1416 can go very quick by verifying that 1 and 6 are not prime numbers,
    instead of examining 141 or 416.
    '''
    if len(str(num)) == 1: return False
    num_list = list(str(num))
    for i in range(len(num_list) - 1):
        
        sub_left = num_list[-(i + 1):]  
        sub_right = num_list[:i + 1]  
                  
        left_num = ''.join(sub_left)
        right_num = ''.join(sub_right)
        if is_prime(int(left_num)) and is_prime(int(right_num)):        # New numbers must be primes as well
            continue
        else:
            return False

    return True         # Value is truncatable!
    


def get_truncatable_primes():
    '''
    Find all 11 truncatable prime numbers. 2, 3, 5 and 7 are not treated as such.
    
    On a sidenote: I originally used my exercise 6, so it could make a huge list of primes beforehand,
    but I figured this would take a lot longer to calculate (and it did). Though this might seem a bit
    less legit, I now use a new ranged list, checking each and every number, though quickly discarding most.
    This code seems more efficient when it comes down to the required time for given operations.
    The only most inelegant part of this solution is the check_trunc function; where I've added a list
    of the four numbers illegal numbers, even though my last solution did not require said list.
    '''
    primes_list = find_primes_until(750000)
    lst = []
    
    for i in primes_list:
        if check_trunc(i):
            lst.append(i)
    
    return lst
    
if __name__ == '__main__':
    truncatablePrimes = get_truncatable_primes()
    print(truncatablePrimes)
    print('Amount of truncatable primes found:', len(truncatablePrimes))
    print('Sum of all truncatable primes:', sum(truncatablePrimes))
