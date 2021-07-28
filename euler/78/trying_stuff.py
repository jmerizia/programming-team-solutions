import sys
from math import sqrt, exp, pi
sys.setrecursionlimit(100_000)
# try 2
from functools import lru_cache

# 1e3 divides p(449)
# 1e4 divides p(599)
# 1e5 divides p(>3000)

MOD = 2

tim = 0
@lru_cache(int(1e8))
def dp(n, m):
    global tim
    tim += 1
    # if tim % 10000 == 0:
    #     print(tim, dp.cache_info(), n, m)
    if n == 0:
        return 1
    s = 0
    for i in range(1, min(n, m)+1):
        p = dp(n - i, i)
        s = (s + p) % MOD
    assert s < MOD
    return s

def approx(n):
    return int((1/(4*n*sqrt(3)))*exp(pi*sqrt(2*n/3)))

def bs(pn):
    # approximately what n produces the given p(n)?
    l = 0
    r = int(1e4)
    for _ in range(30):
        mid = (r + l) // 2
        pn_hat = approx(mid)
        if pn_hat < pn:
            l = mid
        else:
            r = mid
    return l

# for n in range(1, 1000):
#     pn = dp(n, n)
#     pa = approx(n)
#     err = abs(pa-pn)/pn
#     print(n, pn, pa, err)

for i in range(1, 5000):
    n = 5*i+4
    pn = dp(n, n)
    print(n, 'EVEN' if pn % 2 == 0 else '')
    # if pn == 0:
    #     print('Got it!', n)
    #     quit()
quit()

threshold = 0.1
largest = 10_000_000_000
mx_n = -1
checked_approx = set()
checked_n = set()
for pn_hat in range(MOD, largest, MOD):
    n_approx = bs(pn_hat)
    if n_approx in checked_approx:
        continue
    checked_approx.add(n_approx)
    l = max(1, int(n_approx - n_approx * threshold))
    r = int(n_approx + n_approx * threshold) + 1
    # print('Trying', pn_hat, 'which is approximately', n_approx, 'so checking the range', l, '<= n <=', r, '...')
    for n in range(l, r+1):
        if n in checked_n:
            continue
        checked_n.add(n)
        print(n)
        mx_n = max(mx_n, n)
        pn = dp(n, n)
        if pn == 0:
            print('Got it! n =', n)
            quit()
        diff = abs(pn_hat - pn)
print('nada', mx_n)

# print(dp(5000, 5000))

# for n in range(1, 5000):
#     pn = dp(n, n)
#     if pn == 0:
#         print('Got it! n =', n)
#         break
#     print(n, pn, dp.cache_info())
