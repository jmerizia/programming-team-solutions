# attempt 2

from math import gcd

def reduce(f):
    a, b = f
    g = gcd(a, b)
    return a // g, b // g

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

# We know it's going to be between
# floor(1e6*3/7)/1e6 = 428571/1e6 and 3/7
# which means we only have to check a few values
# for each denominator

best_dist = 999
best_n = None
best_d = None
tim = 0
for d in range(1, 1_000_000):
    n = bs(428571/1e6, d)
    while n/d < 3/7:
        dist = abs(n/d-3/7)
        if dist < best_dist:
            best_dist = dist
            best_n = n
            best_d = d
        n += 1
        tim += 1
# print(tim)
print(f'{best_n}/{best_d}')
