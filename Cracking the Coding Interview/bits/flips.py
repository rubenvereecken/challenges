from numpy import uint8, uint16, uint32

ONE = uint32(1)
ZERO = uint32(0)

f = lambda x: '{0:032b}'.format(x)

def count_bits(n):
    c = 0
    while n:
        c += n & 1
        n >>= 2
    return c

def amount_of_flips_needed(a, b):
    r = a ^ b
    return count_bits(r)


a = uint32(int('0011010110', 2))
b = uint32(int('0110010010', 2))
print(amount_of_flips_needed(a, b))
