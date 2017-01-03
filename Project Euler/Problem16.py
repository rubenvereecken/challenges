'''
Created on Dec 29, 2011

@author: ruben
'''

def sum_of_digits (n):
    result = 0
    for i in str(n):
        result += int(i)
    return result

if __name__ == '__main__':
    print('Total sum of digits in 2^1000 =', sum_of_digits(int(2 ** 1000)))