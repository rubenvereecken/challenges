__author__ = 'ruben'


def flatten(array):
    result = []
    for el in array:
        if type(el) == list:
            for flat in flatten(el):
                result.append(flat)
        else:
            result.append(el)
    return result


def flatten2(array):
    r = []
    flatten2_h(array, r)
    return r


def flatten2_h(array, out):
    for el in array:
        if type(el) == list:
            flatten2_h(el, out)
        else:
            out.append(el)


if __name__ == '__main__':
    print flatten([1, 2, [[2, 3], 4]])
    print flatten2([1, 2, [[2, 3], 4]])