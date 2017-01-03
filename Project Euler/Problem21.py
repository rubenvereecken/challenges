'''
Created on Dec 27, 2011

@author: ruben
'''

def d (num):
    total = 0
    for i in range(1, num // 2 + 1):
        if num % i == 0:
            total += i
    return total

def is_amicable(first, second):
    return d(first) == second and d(second) == first

if __name__ == '__main__':
    numbers = list(range(200, 10001))
    amicables = []
    for i in numbers:
        for j in range(i + 1, i + 545):
            print(i, j)
            if is_amicable(i, j):
                amicables.append(i)
                amicables.append(j)
    
    sum = 0
    for i in amicables:
        print(i)
        sum += i
        
    print('Sum of found amicables is', sum)