'''
Created on Dec 29, 2011

@author: ruben
'''

def sum_of_power_of_digits (num, pwr):
    total = 0
    for i in str(num):
        total += int(i) ** pwr
    return total

if __name__ == '__main__':
    total = 0
    for i in range(2, 1000000):
        if i == sum_of_power_of_digits (i, 5): total += i
    print(total)