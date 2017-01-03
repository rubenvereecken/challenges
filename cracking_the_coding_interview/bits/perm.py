from numpy import uint8, uint16, uint32

ONE = uint32(1)
ZERO = uint32(0)

f = lambda x: '{0:032b}'.format(x)

def right_mask(n):
    return (ONE << n) - 1

def bigger(n):
    # find right-most non-trailing 0
    p = ZERO
    c0 = 0
    c1 = 0

    while (n >> p) & ONE ^ ONE:  # skip trailing 0's
        p += ONE
        c0 += 1
    while (n >> p) & ONE:  # skip first contiguous block of 1's
        p += ONE
        c1 += 1

    n |= ONE << p           # Set new bit
    n &= ~right_mask(p)     # Clear the right of it
    n |= right_mask(c1-1)   # Add back c1-1 1's
    return n

def smaller(n):
    p = ZERO
    c0 = 0
    c1 = 0

    while (n >> p) & ONE:  # skip trailing 0's
        p += ONE
        c1 += 1
    while (n >> p) & ONE ^ ONE:  # skip first contiguous block of 1's
        p += ONE
        c0 += 1

    n &= ~right_mask(p+1)     # Clear the right of it and the bit itself
    n |= right_mask(c1+1) << (p-c1-1)   # Add back c1+1 1's
    return n


a = uint32(int('11011001111100', 2))
b = uint32(int('10011110000011', 2))
print(f(bigger(a)))
print(f(smaller(b)))