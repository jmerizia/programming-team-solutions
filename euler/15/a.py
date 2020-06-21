from functools import lru_cache
mem = {}

@lru_cache(int(1e6))
def dp(x, y):
    if (x, y) in mem:
        return mem[(x, y)]
    if x == 0 and y == 0:
        return 1
    if x == 0:
        return dp(x, y-1)
    if y == 0:
        return dp(x-1, y)
    return dp(x-1, y) + dp(x, y-1)

print(dp(20, 20))
