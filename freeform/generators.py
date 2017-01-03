__author__ = 'ruben'


def permutate(array):
    if len(array) == 0:
        yield []
    else:
        for i, el in enumerate(array):
            permutated = permutate(array[0:i] + array[i+1:len(array)])
            for perm in permutated:
                yield [el] + perm


# order doesn't matter so AB == BA
# Trick: don't enumerate too far, leave off the last ones
# Only pass a slice of the array
def combinate(array, r):
    if len(array) == 0 or r <= 0 or len(array) < r:
        yield []
    else:
        for i, el in enumerate(array[0:len(array) - r + 1]):
            combinations = combinate(array[i+1:len(array)], r-1)
            for comb in combinations:
                yield [el] + comb


# order doesn't matter
# Enumerate the whole array, rep is allowed
# Only pass a slice to counter duplicates, current element included
def combinate_with_rep(array, r):
    if len(array) == 0 or r <= 0 or len(array) < r:
        yield []
    else:
        for i, el in enumerate(array):
            combinations = combinate(array[i:len(array)], r-1)
            for comb in combinations:
                yield [el] + comb


def product(A, B):
    for a in A:
        for b in B:
            yield (a, b)


if __name__ == '__main__':
    print "permutate:", list(permutate(range(1)))
    print "combinate:", list(combinate(range(4), 3))
    print "combinate_with_rep:", list(combinate_with_rep(range(3), 2))
    print "product:", list(product(range(3), range(3)))
