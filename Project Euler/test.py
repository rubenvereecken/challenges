'''
Created on Dec 27, 2011

@author: ruben
'''

if __name__ == '__main__':
    previousTriangle = 0
    count = 1
    while True:
        currentTriangle = previousTriangle + count
        print(currentTriangle, count)
        previousTriangle = currentTriangle
        count += 1