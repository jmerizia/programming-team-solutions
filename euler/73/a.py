# O(n^2) should work

from math import gcd

def bs(target, den):
    l = 1
    r = den
    for _ in range(21):  # log_2(1e6)
        mid = (l + r) // 2
        if mid/den < target:
            l = mid
        else:
            r = mid
    return mid


ans = 0
mx = 0
tim = 0
for d in range(2, 12_000+1):
    n = bs(1/3, d)
    while n/d <= 1/3:
        n += 1
    assert n/d > 1/3
    while n/d < 1/2:
        if gcd(n, d) == 1:
            ans += 1
        n += 1
        tim += 1
# print(tim)
print(ans)