'''
Created on Dec 29, 2011

@author: ruben
'''
import sys
from bigfloat import *

def find_intersection (m, b, startingcoords):
    '''
    y = mx + b
    y^2 = 100 - 4x
    '''
    print('---------------------')
    print('Using m =', m)
    print('Using b =', b)
    with precision(200):
        D = 4 * (b ** 2) * (m ** 2) - 4 * ((b ** 2) - 100) * ((m ** 2) + 4)
        x1 = (-2 * b * m + (D ** 0.5)) / (2 * (m ** 2) + 8)
        x2 = (-2 * b * m - (D ** 0.5)) / (2 * (m ** 2) + 8)
        y1 = m * x1 + b
        y2 = m * x2 + b
    print('(x1, y1) =', (x1, y1))
    print('(x2, y2) =', (x2, y2))
    print('---------------------')
    if pretty_much_equal(x1, startingcoords[0], 0.001) and 
    pretty_much_equal(y1, startingcoords[1], 0.001): return (x2, y2)
    else: return (x1, y1)
    

def find_slope (coords):
    '''
    a = 5
    b = 10
    '''
    x = coords[0]
    y = coords[1]
    slope = -4 * (x / y)
    return slope


def perpendicular (slope):
    '''
    m' = -1 / m
    '''
    return -1 / slope


def calculate_new_offset (m, coords):
    x = coords[0]
    y = coords[1]
    b = (-m * x + y)
    return b
    

def pretty_much_equal (a, b, precision):
    if a - precision <= b <= a + precision:
        return True
    else: return False


def do_problem (startslope=-19.7/1.4, startoffset=10.1, startcoords=(0.0, 10.1)):
    print('Start coordinates =', startcoords)
    resulting_intersection = find_intersection(startslope, startoffset, startcoords)
    if -0.05 < resulting_intersection[0] < 0.05 and 9.5 < resulting_intersection[1] < 10.5: drawattention()
    print('Chosen intersection =', resulting_intersection)
    print()
    if pretty_much_equal (0, resulting_intersection[0], 0.01) and 
    pretty_much_equal (10, resulting_intersection[1], 0.01):
        return 0
    else:
        normslope = perpendicular (find_slope (resulting_intersection))
        newslope = calculate_next_slope (startslope, normslope)
        newoffset = calculate_new_offset (newslope, resulting_intersection)
        return 1 + do_problem (newslope, newoffset, resulting_intersection)


def calculate_next_slope (startslope, normslope):
    print('Startslope is', startslope, 'and normslope is', normslope)
    r = startslope
    n = normslope
    m1 = -(2 * r * n - (n ** 2) + 1) / (2 * n - r * (n ** 2) - r)
    m2 = -1 / m1
    if m1 > n: return m1
    else: return m2


def drawattention():
    print('\n\n\n\n\n')
    print("LOOKIE HERE")
    print('\n\n\n\n\n')

if __name__ == '__main__':
    sys.setrecursionlimit(10000)
    print(do_problem())