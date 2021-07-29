from functools import lru_cache
from itertools import product
from math import sqrt


n = int(2e6 + 99)
is_prime = [True] * (n+1)
primes = []
spf = list(range(n+1))
is_prime[1] = False
p = 2
while p*p <= n:
    if is_prime[p]:
        i = p*p
        while i <= n:
            is_prime[i] = False
            if spf[i] == i:
                spf[i] = p
            i += p
    p += 1
for p in range(2, n+1):
    if is_prime[p]:
        primes.append(p)
print('Done sieve')

def factor(n):
    fa = []
    p = spf[n]
    while p <= n and n > 1:
        m = 0
        while n % p == 0:
            m += 1
            n //= p
        fa.append((p, m))
        p = spf[n]
    return fa


@lru_cache(int(1e6))
def P(n, m):
    if n == 0:
        return [tuple()]
    else:
        v = []
        for i in range(min(n, m), 0, -1):
            v += [(i,) + t for t in P(n - i, i)]
        return v


def ks(n):
    fa = factor(n)
    totals = set()
    for all_powers in product(*[P(m, m) for p, m in fa]):
        print(all_powers)
        # s = 0
        # total_nums = 0
        # for (p, m), powers in zip(fa, all_powers):
        #     s += sum(p ** power for power in powers)
        #     total_nums += len(powers)
        # ones = n - s
        # total_nums += ones
        # totals.add(total_nums)
    return totals

print(ks(12))

# N = 12
# K = dict()
# for n in range(2, 2_000_000):
#     for k in sums(n):
#         if k <= N and k not in K:
#             K[k] = n
#     if len(K) == N-1:
#         break
#     if n % 100_000 == 0:
#         print(n)
# print(K)
# assert len(K) == N-1

# print(sum(K.values()))
