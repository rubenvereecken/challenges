__author__ = 'ruben'

from numpy import uint8, uint16, uint32

ONE = uint32(1)
ZERO = uint32(0)
_32 = uint32(32)

def to_str(i):
    return "{0:032b}".format(i)

def right_mask(n):
    return (ONE << n) - 1

def left_mask(n):
    return ~uint32((ONE << (32-n)) - ONE)

def reverse(n):
    c = ZERO
    for _ in range(32):
        c |= n & ONE
        n >>= 1
        c <<= 1
    return c

def flip_least_significant(n):
    return n & (n - 1)