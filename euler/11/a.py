n, m = map(int, input().split())
grid = []
for _ in range(n):
    grid.append(list(map(int, input().split())))

ans = -1

for i in range(n-3):
    for j in range(m):
        ans = max(ans, grid[i][j] * grid[i+1][j] * grid[i+2][j] * grid[i+3][j])

for i in range(n):
    for j in range(m-3):
        ans = max(ans, grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3])

for i in range(n-3):
    for j in range(m-3):
        ans = max(ans, grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3])

for i in range(3, n):
    for j in range(m-3):
        ans = max(ans, grid[i][j] * grid[i-1][j+1] * grid[i-2][j+2] * grid[i-3][j+3])

print(ans)
