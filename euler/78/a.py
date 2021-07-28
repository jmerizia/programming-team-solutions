# another recurrence formulation

from functools import lru_cache

MOD = int(1e6)

@lru_cache(int(1e7))
def sumdiv(n):
    return sum(i for i in range(1, n+1) if n % i == 0)

@lru_cache(int(1e7))
def p(n):
    # more efficient recurrence relation
    if n == 0:
        return 1
    else:
        s = 0
        for k in range(n):
            s += sumdiv(n - k) * p(k)
        s //= n
        return s


# 1e3 divides p(449)
# 1e4 divides p(599)
# 1e5 divides p(11224)
# 1e6 divides p(55374)  woo!

print('This will take a long time')

for i in range(1, 100_000):
    n = 5*i+4  # ramanujan congruence
    pn = p(n)
    if pn % MOD == 0:
        print('Got it!', n, pn)
        quit()
    if i % 1000 == 0:
        print(n, p.cache_info())
