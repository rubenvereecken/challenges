'''
Created on Dec 29, 2011

@author: ruben
'''

from itertools import permutations



if __name__ == '__main__':
    test = permutations(range(10))
    count = 1
    for i in test:
        if count == 1000000:
            strng = ''
            for j in i:
                strng += str(j)
            print(strng)
            break
        count += 1