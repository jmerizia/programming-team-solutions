L = 2019
A = [['.']*L for _ in range(L)]
B = [['.']*L for _ in range(L)]

Ad = input()# .split(',')
Bd = input()#.split(',')
quit()

cx, cy = 1000, 1000
for d in Ad:
    mv = 0
    while mv < int(d[1:]):
        grid[cx, cy] = '#'
        if d[0] == 'R':
            cy += 1
        if d[0] == 'L':
            cy -= 1
        if d[0] == 'U':
            cx += 1
        if d[0] == 'D':
            cx -= 1
        mv += 1

cx, cy = 1000, 1000
for d in Bd:
    mv = 0
    while mv < int(d[1:]):
        if grid[cx, cy] == '#':
            grid[cx, cy] = 'x'
        if d[0] == 'R':
            cy += 1
        if d[0] == 'L':
            cy -= 1
        if d[0] == 'U':
            cx += 1
        if d[0] == 'D':
            cx -= 1
        mv += 1

for i in range(L):
    for j in range(L):
        if grid[i, j] == 'x':
            print('x')
