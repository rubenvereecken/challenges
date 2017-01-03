'''
Created on Dec 27, 2011

@author: ruben
'''

def fac (num):
    if num == 1:
        return num
    else:
        return num * fac (num - 1)


if __name__ == '__main__':
    strng = str(fac(100))
    result = 0
    print(strng)
    for i in strng:
        result += int(i)
    print("Total of all digits in 100! is", result)