'''
Created on Dec 29, 2011

@author: ruben
'''

if __name__ == '__main__':
    result = 0
    for i in range(1, 1001):
        result += i ** i
        
    print('Last ten digits of sum are', str(result)[-10:])