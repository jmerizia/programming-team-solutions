# number of additional cells for loop: (2i + 1) * 4 - 4 = 8i
# where the new side length is 2i + 1
# and corner numbers are 2i + 1, 4i + 1, 6i + 1, and 8i + 1
# (offset by the number of previous cells)

import math
# from functools import lru_cache

# @lru_cache(int(1e6))
def is_prime(n):
    if n <= 1:
        return False
    for i in range(2, min(n, int(math.sqrt(n)) + 1)):
        if n % i == 0:
            return False
    return True

o = 0
tot_prime = 0
tot = 0
for i in range(20000):
    s = 2 * i + 1
    new = [2 * i + 1 + o, 4 * i + 1 + o, 6 * i + 1 + o, 8 * i + 1 + o]
    tot += len(set(new))
    tot_prime += len(list(filter(is_prime, new)))
    r = tot_prime / tot
    if i % 1000 == 0:
        print(r)
    if r < 0.1 and i > 0:
        print(s)
        break
    o += 8 * i
