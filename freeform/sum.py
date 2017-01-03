__author__ = 'ruben'


# assume digits in the order that we write them
def sum(a, b):
    smaller = a if len(a) < len(b) else b
    larger = a if len(a) >= len(b) else b
    new_num = [None for i in range(len(larger) + 1)]  # allow extra space
    small_i = len(smaller) - 1
    large_i = len(larger) - 1
    carry = 0

    while small_i >= 0 and large_i >= 0:
        sum = smaller[small_i] + larger[large_i] + carry
        new_num[large_i + 1] = (sum) % 10
        carry = (sum) // 10
        small_i -= 1
        large_i -= 1

    while large_i >= 0:
        sum = larger[large_i] + carry
        new_num[large_i + 1] = sum % 10
        carry = sum // 10
        large_i -= 1

    if carry:
        new_num[0] = carry

    return new_num[1:] if new_num[0] is None else new_num


if __name__ == '__main__':
    print(sum([1, 1, 2], [8, 9]))
    print(sum([9, 9, 9], [1, 1, 1]))
