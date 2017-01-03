def next_one(s):
    i = len(s) - 1
    l = 0
    found = False
    while i > 0:
        if s[i-1] < s[i]:
            l = i-1
            found = True
            break
        i -= 1
        
    if not found:
        return 'no answer'

    i = len(s) - 1
    h = 0
    while i > 0:
        if s[i] > s[l]:
            h = i
            break
        i -= 1
    prefix = s[:l]
    return prefix + s[h] + ''.join(sorted(s[l:h]+s[h+1:]))

for _ in range(int(input())):
    print(next_one(input()))