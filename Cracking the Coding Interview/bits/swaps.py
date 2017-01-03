from numpy import uint8, uint16, uint32

ONE = uint32(1)
ZERO = uint32(0)
odd_mask = uint32(0x55555555)

f = lambda x: '{0:032b}'.format(x)

def swapse(n):
    r = ZERO
    r |= (odd_mask & n) << 1
    r |= odd_mask & (n >> 1)
    return r

a = uint32(int('0010010110', 2))
print(f(a))
print(f(swapse(a)))