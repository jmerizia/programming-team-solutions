from itertools import combinations


def kth_bit(n, k):
    return (n & (1 << k)) >> k

def iter_subsets(A):
    for i in range(2**len(A)):
        B = set()
        for j, e in zip(range(len(A)), A):
            if kth_bit(i, j) == 1:
                B.add(e)
        yield B

def check(A):
    for B, C in combinations(iter_subsets(A), 2):
        if len(B) == 0 or len(C) == 0:
            continue
        if len(B & C) != 0:
            continue
        if sum(B) == sum(C):
            return False
        if len(B) > len(C) and sum(B) <= sum(C):
            return False
    return True

def solve(n, low, high):
    combs = list(map(set, combinations(range(low, high+1), n)))
    best = None
    best_s = 9999999
    for i, A in enumerate(combs):
        if check(A):
            if sum(A) < best_s:
                best_s = sum(A)
                best = A
                print(best)
        if i % 10000 == 0:
            print(i, '/', len(combs))
    return best

A = solve(7, low=19, high=45)
if A is None:
    print('Nothing found')
else:
    print(A)
    print(''.join(map(str, sorted(A))))