from functools import lru_cache
den = [1, 2, 5, 10, 20, 50, 100, 200]

@lru_cache(int(1e6))
def dp(c, highest=1):
    if c == 0:
        return 1
    if c < 0:
        return 0
    return sum(dp(c-d, d) for d in den if d >= highest)

print(dp(200))
