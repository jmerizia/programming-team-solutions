from functools import lru_cache


with open('triangle.txt', 'r') as f:
    tri = []
    for line in f:
        tri.append(list(map(int, line.split())))

@lru_cache(int(1e6))
def dp(x=0, y=0):
    if x == len(tri):
        return 0
    return max(dp(x + 1, y), dp(x + 1, y + 1)) + tri[x][y]

print(dp())
