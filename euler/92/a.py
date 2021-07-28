# so paths are really short

from functools import lru_cache

N = int(1e7)

def nxt(n):
    s = 0
    while n > 0:
        s += (n % 10) ** 2
        n //= 10
    return s

@lru_cache(N)
def chain(n):
    if n == 1:
        return 0
    if n == 89:
        return 1
    return chain(nxt(n))

print(sum(chain(n) for n in range(1, N)))
print(chain.cache_info())
