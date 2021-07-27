from functools import lru_cache

@lru_cache(int(1e6))
def dp(n, m):
    return 1 if n == 0 else sum(dp(n - i, i) for i in range(1, min(n, m)+1))

print(dp(100, 100)-1)
