'''
Created on Dec 27, 2011

@author: ruben
'''

def is_palindrome (num):
    strng = str(num)
    for i in range(len(strng)//2):
        if strng[i] != strng[-(i + 1)]: return False
    return True


def reverse (num):
    new = ''
    strng = str(num)
    for i in range(len(strng)):
        new += strng[-(i + 1)]
    return int(new)


def is_lychrel (num):
    for i in range(50):
        num = num + reverse(num)
        if is_palindrome(num): return False
    return True

if __name__ == '__main__':
    lychrelCount = 0
    for i in range(1, 10000):
        test = is_lychrel(i)
        if test: lychrelCount += 1
        print('Checking number', i, 'tests', test)
        
    print('A total of', lychrelCount, 'Lychrel numbers have been found below 10000.')