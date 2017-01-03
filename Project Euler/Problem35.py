'''
Created on Dec 29, 2011

@author: ruben
'''

from PrimeSieve import find_primes_until


def permutate(strng):
    '''
    Makes a list of a given number's circulations.
    Number must be in string format.
    '''
    temp = list(strng)
    permutated_list = []
    result_list = []

        
    for i in range(len(temp)):
        permutated_list.append(temp)
        temp = temp[1:] + temp[:1]
    
    for i in permutated_list:
        result_list.append(int(''.join(i)))
    
    return result_list
        


def count_circular_primes(primes):
    '''
    Counts all circular primes up to given maximum
    '''
    count = 0
    
    for i in primes:
        temp_list = permutate(str(i))
        allprime = True
        
        for j in temp_list:
            if j in primes:
                continue
            else:
                allprime = False
                
        if allprime:
            print(i)
            count += 1
            
    return count
    
    

if __name__ == '__main__':
    primes = find_primes_until (1000000)
    print('I found', count_circular_primes(primes), 'circular primes smaller than 1 million.')