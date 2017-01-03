__author__ = 'ruben'

def is_pangram(s):
    clean = s.lower().replace(' ', '')
    alphabet = {}
    for c in clean:
        alphabet[c] = True
    return True if len(alphabet.keys()) == 26 else False

print('pangram' if is_pangram(input()) else 'not pangram')