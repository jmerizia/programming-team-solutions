n = 323
grid = []
for i in range(n):
    grid.append(input())

def doit(k):
    trees = 0
    for i in range(n):
        j = i*k % 31
        if grid[i][j] == '#':
            trees += 1
    return trees

def doitt():
    trees = 0
    for i in range(0, n, 2):
        j = i//2 % 31
        if grid[i][j] == '#':
            trees += 1
    return trees

print(doit(1)*doit(3)*doit(5)*doit(7)*doitt())
