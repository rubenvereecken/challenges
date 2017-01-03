__author__ = 'ruben'

import array

def unique_digits_generator(start, end):
    for n in xrange(start, end):
        tracker = [False for _ in xrange(10)]
        c = n
        unique = True
        while c > 0:
            digit = c % 10
            if tracker[digit]:
                unique = False
                break
            else:
                tracker[digit] = True
            c //= 10
        if unique:
            yield n


if __name__ == '__main__':
    print(list(unique_digits_generator(1, 100)))