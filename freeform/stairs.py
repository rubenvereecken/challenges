__author__ = 'ruben'

from decorators import memoize


@memoize
def n_stairs(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    return n_stairs(n-2) + n_stairs(n-1)


if __name__ == '__main__':
    assert n_stairs(2) == 2
    assert n_stairs(4) == 5