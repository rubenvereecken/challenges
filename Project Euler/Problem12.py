'''
Created on Dec 27, 2011

@author: ruben
'''

def find_factors (num):
    factorlist = []
    for i in range(1, num + 1):
        if num % i == 0:
            factorlist.append(i)
    return factorlist
        

def find_triangle_with_factors (amountOfFactors):
    previousTriangle = 0
    count = 1
    while True:
        currentTriangle = previousTriangle + count
        print(currentTriangle)
        if len(find_factors(currentTriangle)) > amountOfFactors:
            return currentTriangle
        previousTriangle = currentTriangle
        count += 1
        
        
if __name__ == '__main__':
    print(find_triangle_with_factors (500), "has over 500 factors.")