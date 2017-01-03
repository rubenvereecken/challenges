__author__ = 'ruben'

from functools import wraps
import collections

def memoize(f):
    cache = {}

    @wraps(f)
    def cached_f(*args):
        if not isinstance(args, collections.Hashable):
            return f(*args)
        if args in cache:
            print 'hit'
            return cache[args]
        result = f(*args)
        cache[args] = result
        return result

    return cached_f


@memoize
def fib(n):
    if n <= 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)


if __name__ == '__main__':
    #print fib(100)
    ''