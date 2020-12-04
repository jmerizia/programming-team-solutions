n = 323
grid = []
for i in range(n):
    grid.append(input())

trees = 0
for i in range(n):
    j = i*3 % 31
    if grid[i][j] == '#':
        trees += 1
print(trees)
