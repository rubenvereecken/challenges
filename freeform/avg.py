__author__ = 'ruben'


def avg(array):
    r = 0
    count = 0.
    for n in array:
        r = (count / (count + 1)) * r + n / (count + 1)
        count += 1
    return r


if __name__ == '__main__':
    n = 1000 #  5 * 10 ** 9
    print(avg(xrange(n)))
    assert avg(xrange(n)), n * (n - 1) / 2