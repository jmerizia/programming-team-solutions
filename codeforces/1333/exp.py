n = 3
grid = [[0]*n for _ in range(n)]
tim = 0

def find(v):
    for i in range(n):
        for j in range(n):
            if grid[i][j] == v:
                return (i, j)
    return None, None

def test_rook():
    vis = set()
    x, y = find(1)
    vis.add(1)
    left = n*n-1
    cnt = 0
    while left > 0:
        best = 10000

        # find best option in rows:
        k = 0
        while (k < n):
            if k != x and grid[k][y] not in vis:
                best = min(best, grid[k][y])
            k += 1
        k = 0
        while (k < n):
            if k != y and grid[x][k] not in vis:
                best = min(best, grid[x][k])
            k += 1

        # if there was no best available option:
        if best == 10000:
            # find the first available option:
            tele_best = 10000
            for i in range(n):
                for j in range(n):
                    if grid[i][j] not in vis:
                        tele_best = min(tele_best, grid[i][j])
            vis.add(tele_best)
            x, y = find(tele_best)
            cnt += 1
        else:
            x, y = find(best)
            vis.add(best)
        left -= 1
    return cnt

def test_queen():
    vis = set()
    x, y = find(1)
    vis.add(1)
    left = n*n-1
    cnt = 0
    while left > 0:
        best = 10000

        # find best option in rows:
        k = 0
        while (k < n):
            if k != x and grid[k][y] not in vis:
                best = min(best, grid[k][y])
            k += 1
        k = 0
        while (k < n):
            if k != y and grid[x][k] not in vis:
                best = min(best, grid[x][k])
            k += 1
        k = 0
        while (x+k < n and y+k < n):
            if k != 0 and grid[x+k][y+k] not in vis:
                best = min(best, grid[x+k][y+k])
            k += 1
        k = 0
        while (x-k >= 0 and y-k >= 0):
            if k != 0 and grid[x-k][y-k] not in vis:
                best = min(best, grid[x-k][y-k])
            k += 1
        k = 0
        while (x-k >= 0 and y+k < n):
            if k != 0 and grid[x-k][y+k] not in vis:
                best = min(best, grid[x-k][y+k])
            k += 1
        k = 0
        while (x+k < n and y-k >= 0):
            if k != 0 and grid[x+k][y-k] not in vis:
                best = min(best, grid[x+k][y-k])
            k += 1

        # if there was no best available option:
        if best == 10000:
            # find the first available option:
            tele_best = 10000
            for i in range(n):
                for j in range(n):
                    if grid[i][j] not in vis:
                        tele_best = min(tele_best, grid[i][j])
            vis.add(tele_best)
            x, y = find(tele_best)
            cnt += 1
        else:
            x, y = find(best)
            vis.add(best)
        left -= 1
    return cnt

def bt(cur):
    global tim
    tim += 1
    if tim % 1000 == 0:
        print(tim)
    if cur > n*n:
        if test_rook() < test_queen():
            ans = [[0]*n for _ in range(n)]
            for i in range(n):
                for j in range(n):
                    ans[i][j] = grid[i][j]
            return ans
    else:
        for i in range(n):
            for j in range(n):
                if grid[i][j] == 0:
                    grid[i][j] = cur
                    res = bt(cur+1)
                    if res != None:
                        return res
                    grid[i][j] = 0
    return None

print(bt(1))
