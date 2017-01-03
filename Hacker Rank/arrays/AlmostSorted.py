__author__ = 'ruben'

MINF = -float('infinity')

def out_of_place(ar):
    last = MINF
    outs = []
    for i, el in enumerate(ar):
        if len(outs) % 2 and el <= outs[-1] and (i >= len(ar) - 1 or ar[i+1] != el):
            outs.append(i)
        elif el < last:
            outs.append(i)
        last = el
    return outs


n = int(input())
ar = list(map(int, input().split(' ')))
outs = out_of_place(ar)

if len(outs) == 0:
    print("yes")
elif len(outs) == 1:
    if outs[0] >= len(ar)-1 or ar[outs[0]+1] >= ar[outs[0]-1]:
        print('yes')
        print('swap {} {}'.format(outs[0], outs[0]+1))
    else:
        print('no')
elif len(outs) == 2:
    print('yes')
    print('swap {} {}'.format(outs[0], outs[1]+1))
else:
    increasing = True
    pivotStart = -1
    pivotEnd = -1
    last = MINF
    no = False

    for i, el in enumerate(ar):
        if increasing and el < last:
            #print('inc', el, last)
            if pivotStart != pivotEnd:
                no = True
                break
            pivotStart = i
            increasing = False
        elif not increasing and el > last:
            #print('dec', el, last)
            if el < ar[pivotStart-1]:
                no = True
                break
            pivotEnd = i
            increasing = True
        last = el

    if not no and not increasing:
        pivotEnd = len(ar)

    if no:
        print('no')
    else:
        print('yes')
        print('reverse {} {}'.format(pivotStart, pivotEnd))