'''
Created on Jan 18, 2012

@author: ruben
'''

from itertools import combinations, permutations
from random import randint, shuffle
from copy import copy

def is_ordered (lst):
    for i in range(1, len(lst)):
        if lst[i] < lst[i - 1]: return False
    return True

def bozo (lst):
    count = 0
    while not is_ordered (lst):
        first = randint(0, len(lst) - 1)
        second = randint(0, len(lst) - 1)
        while second == first: second = randint(0, len(lst) - 1)
        firstVal = lst[first]
        lst[first] = lst[second]
        lst[second] = firstVal
        count += 1
    return count

def bozo_variant (lst):
    count = 0
    while not is_ordered (lst):
        numbers = [0, 0, 0]
        first = 0
        second = 0
        third = 0
        while (numbers[0] == numbers[1]) or (numbers[0] == numbers[2]) or (numbers[1] == numbers[2]):
            first = randint(0, len(lst) - 1)
            numbers[0] = lst[first]
            second = randint(0, len(lst) - 1)
            numbers[1] = lst[second]
            third = randint(0, len(lst) - 1)
            numbers[2] = lst[third]
        #print('FIRST', numbers[0], 'SECOND', numbers[1], 'THIRD', numbers[2])
        shuffle(numbers)
        lst[first] = numbers[0]
        lst[second] = numbers[1]
        lst[third] = numbers[2]
        count += 1
    return count
        
     
def average_bozo_variant (lst, n):
    total = 0
    for i in range(n):
        total += bozo_variant(copy(lst))
    total /= n
    return total


def total_bozo_average_variant (rng, n):
    total = 0
    amnt = 0
    for i in permutations(list(range(rng))):
        print(i)
        total += average_bozo_variant (list(i), n)
        amnt += 1
    total /= amnt
    return total 
     
        

def average_bozo (lst, n):
    total = 0
    for i in range(n):
        total += bozo(copy(lst))
    total /= n
    return total


def total_bozo_average (rng, n):
    total = 0
    amnt = 0
    for i in permutations(list(range(rng))):
        total += average_bozo (list(i), n)
        amnt += 1
    total /= amnt
    return total
        

if __name__ == '__main__':
    print(total_bozo_average_variant (5, 200))