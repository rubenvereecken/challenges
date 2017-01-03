__author__ = 'ruben'


def longest_increasing(array):
    """
    Only one extra variable allowed
    :param array:
    :return:
    """

    record = 1
    for i, a in enumerate(array[1:]):
        if array[i-1] <= a:
            record += 1