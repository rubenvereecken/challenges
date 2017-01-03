'''
Created on Dec 29, 2011

@author: ruben
'''

def create_pentagonal_numbers (amount):
    numbers = []
    for i in range(1, amount + 1):
        number = i * (3 * i - 1) / 2
        numbers.append(int(number))
    return numbers


def create_triangle_numbers (amount):
    numbers = []
    for i in range(1, amount + 1):
        number = i * (i + 1) / 2
        numbers.append(int(number))
    return numbers


def create_hexagonal_numbers (amount):
    numbers = []
    for i in range(1, amount + 1):
        number = i * (2 * i - 1)
        numbers.append(int(number))
    return numbers


if __name__ == '__main__':
    pentagonals = create_pentagonal_numbers (100000)
    triangles = create_triangle_numbers (100000)
    hexagonals = create_hexagonal_numbers (100000)
    
    for i in range(len(triangles)):
        if triangles[i] in pentagonals[:i] and triangles[i] in hexagonals[:i]:
            print('Found myself a number here:', triangles[i])
            if triangles[i] > 40755: break
        print(triangles[i])