'''
Created on Dec 25, 2011

@author: ruben
'''

def sum_of_multiples_of_3_and_5_until(maximum):
    total = 0
    for i in range(maximum):
        if i % 3 == 0 or i % 5 == 0:
            total += i
            
    return total


if __name__ == '__main__':
    print("Total sum:", sum_of_multiples_of_3_and_5_until(1000))