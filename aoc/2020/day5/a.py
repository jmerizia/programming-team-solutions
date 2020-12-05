n = 824
ans = -1
seats = set()
for i in range(n):
    s = input()
    #s = "BFFFBBFRRR"
    rs = s[:-3]
    cs = s[-3:]
    a, b = 0, 128
    for c in rs:
        mid = (a + b)//2
        if c == 'F':
            b = mid
        else:
            a = mid
    row = a
    a, b = 0, 8
    for c in cs:
        mid = (a + b)//2
        if c == 'L':
            b = mid
        else:
            a = mid
    col = a
    idd = row*8+col
    if idd in seats:
        print('oops', row, col)
        quit()
    seats.add(idd)
    #ans = max(ans, idd)
    #print(row, col)
    #break
print(sorted(seats))
for r in range(0, 127):
    for c in range(0, 8):
        i = r*8+c
        if i > 800:
            break
        if i not in seats:
            print(i)
print(ans)
