'''
Created on Dec 29, 2011

@author: ruben
'''

def generate_special_squares (lower, upper):
    squares = []
    for i in range(lower, upper, 2):
        squares.append(i ** 2)
    return squares


def generate_specials (lower, upper):
    specials = []
    for i in range(lower, upper):
        specials.append(int(4 * (i ** 2) - 8 * i + 5))
    return specials


def generate_some_more (lower, upper):
    specials = []
    for i in range(lower, upper):
        specials.append(int(4 * (i ** 2) - 10 * i + 7))
    return specials


def generate_more (lower, upper):
    specials = []
    for i in range(lower, upper):
        specials.append(int(4 * (i ** 2) - 6 * i + 3))
    return specials


if __name__ == '__main__':
    specials = generate_specials(2, 502)
    squares = generate_special_squares(3, 1003)
    more = generate_more(2, 502)
    somemore = generate_some_more(2, 502)
    print(specials)
    print(squares)
    print(more)
    print(somemore)
    print(sum(specials) + sum(squares) + sum(more) + sum(somemore) + 1)
    print(len(specials) + len(squares) + len(more) + len(somemore))