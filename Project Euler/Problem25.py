'''
Created on Dec 29, 2011

@author: ruben
'''

def find_fibonacci_number_with_amount_of_digits (digits):
    first = 1
    second = 1
    count = 2
    while True:
        nextnum = first + second
        count += 1
        if len(str(nextnum)) == digits:
            return count
        first = second
        second = nextnum

if __name__ == '__main__':
    print('Found the first Fibonacci number with 4 digits:', find_fibonacci_number_with_amount_of_digits (1000))