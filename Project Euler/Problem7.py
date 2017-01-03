'''
Created on Dec 27, 2011

@author: ruben
'''
facs = {}


def get_prime (n):
    count = 0
    num = 2
    while True:
        if is_prime(num):
            count += 1
            if (count == n): return num
        num += 1
    
def is_prime (n):
    return fac (n - 1) % n == n - 1

def fac (n):
    if n == 1: return 1
    elif n in facs:
        return facs[n]
    else:
        print('Checking out facs', facs)
        facs[n] = n * fac (n - 1)
        return facs[n]
    

if __name__ == '__main__':
    print(fac(950))
    print("1000th prime is", get_prime (1000))
    