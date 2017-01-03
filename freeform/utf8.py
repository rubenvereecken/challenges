__author__ = 'ruben'


def is_utf8(input):
    if input[0] == '0':
        return len(input) == 8
    bytes = 0
    i = 0
    while i < 6 and input[i] == '1':
        bytes += 1
        i += 1

    if bytes not in range(2, 4) or len(input) != bytes * 8:
        return False
    start = 0

    for byte in range(1, bytes):
        start += 8
        if input[start] != '1' or input[start+1] != '0':
            return False

    return True


if __name__ == '__main__':
    print(is_utf8('01231234'))
    print(is_utf8('111' + '0' * 5 + ('10' + '0'*6)*2))


