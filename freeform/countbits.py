__author__ = 'ruben'

from numpy import uint32, uint8

ONE = uint8(1)

def tob(b):
    return "{0:b}".format(b)

def count_uint32(n):
    print(tob(n))
    c = 0
    for _ in range(32):
        c += n & ONE
        n >>= ONE
    return c


if __name__ == '__main__':
    print(count_uint32(uint32(0) - uint8(1)))
    print(count_uint32(uint32(0) + uint8(255)))
    print(count_uint32(uint32(0) + uint8(128)))
