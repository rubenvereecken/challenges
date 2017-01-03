__author__ = 'ruben'

def all_unique(str):
    occurrences = [False] * 256
    for char in str:
        if occurrences[ord(char)]:
            return False
        else:
            occurrences[ord(char)] = True
    return True

def all_unique2(str):
    b = list(str)
    b.sort()
    prev = b[0]
    for char in b[1:]:
        if prev == char:
            return False
        else:
            prev = char
    return True

if __name__ == "__main__":
    print(all_unique('sexy'))
    print(all_unique('very sexy'))
    print(all_unique2('sexy'))
    print(all_unique2('very sexy'))