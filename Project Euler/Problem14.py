'''
Created on Dec 29, 2011

@author: ruben
'''

sequences = {}


def process (num):
    original = num
    sequence = []
    while num != 1:
        if num in sequences:
            sequence += sequences[num]
            sequences[original] = sequence
            return sequence
        sequence.append(int(num))
        if num % 2 == 0: num /= 2
        else: num = 3 * num + 1
    sequence.append(1)
    sequences[original] = sequence
    return sequence

if __name__ == '__main__':
    longest = 0
    for i in range(1, 1000000):
        print(i)
        length = len(process(i))
        if length > longest: 
            longest = length
            print(i, 'IS LENGTHIEST')
    print('Longest one I found is of size', longest)