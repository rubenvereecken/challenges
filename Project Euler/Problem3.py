'''
Created on Dec 27, 2011

@author: ruben
'''

def find_largest_prime_factor (num):
    start = 1
    found = True
    while found:
        found = False
        for i in range(start, num):
            if num % i == 0:
                num = num // i
                start = i + 1
                found = True
                break
    return num
    

if __name__ == '__main__':
    print("Largest prime factor of 600851475143 is", find_largest_prime_factor (600851475143))