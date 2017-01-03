__author__ = 'ruben'


def permutations(array):
    if len(array) == 1:
        yield [array[0]]
    else:
        for i, el in enumerate(array):
            pre = array[0:i]
            post = array[i+1:len(array)]
            next = permutations(pre + post)
            for perm in next:
                yield [el] + perm





if __name__ == '__main__':
    print(list(permutations([x for x in range(3)])))