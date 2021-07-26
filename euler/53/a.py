from functools import lru_cache


@lru_cache(int(1e6))
def choose(n, k):
    # 1
    # 1 1
    # 1 2 1
    # 1 3 3 1
    if n < 0 or k < 0 or n < k:
        return 0
    if n == 0:
        return 1
    return choose(n-1, k) + choose(n-1, k-1)

ans = 0
for n in range(1, 101):
    for k in range(1, 101):
        if choose(n, k) > int(1e6):
            ans += 1

print(ans)
