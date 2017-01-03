'''
Created on Dec 27, 2011

@author: ruben
'''


def find_primes_until (num):
    candidates = {}
    squareMax = num ** 0.5
    for i in range(2, num):
        candidates[i] = True
    for i in candidates.keys():
        if i > squareMax: break
        if candidates[i]:
            j = i ** 2
            while j <= len(candidates) + 1:
                candidates[j] = False
                j += i
    final = []
    for i in candidates.keys():
        if candidates[i]: final.append(i)
    return final
            

if __name__ == '__main__':
    hugeprimeList = find_primes_until (2000000)
    print('10001th prime is', hugeprimeList[10000])
    print('Sum of all primes below 2 million:', sum(hugeprimeList))