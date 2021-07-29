# third time's the charm
from math import sqrt
from functools import lru_cache, reduce


tim = 0
K = dict()

def missing():
    global K
    return set(k for k in range(2, 12_001) if k not in K)


@lru_cache(int(1e6))
def split(nums):
    global tim
    assert nums == tuple(sorted(nums)), nums
    if len(nums) == 0:
        return set()
    uniq = {nums}
    for i in range(len(nums)):
        num = nums[i]
        for d in range(2, num // 2 + 1):
            tim += 1
            if tim % 1_000_000 == 0:
                print(tim, len(missing()), split.cache_info())
            if num % d == 0:
                # break num into d and num/d and recurse
                new = []
                for ii, num in enumerate(nums):
                    if i == ii:
                        new.append(d)
                        new.append(num // d)
                    else:
                        new.append(num)
                uniq |= split(tuple(sorted(new)))
    return uniq


def size(nums):
    n = reduce(lambda a, b: a * b, nums)
    ones = n - sum(nums)
    return ones + len(nums)


for n in range(15_000):
    for t in split( (n,) ):
        k = size(t)
        # print(t, '=>', k)
        if k not in K:
            K[k] = n
    if n % 10 == 0 and len(missing()) == 0:
        break

print(sum(set(K[k] for k in range(2, 12_001))))
