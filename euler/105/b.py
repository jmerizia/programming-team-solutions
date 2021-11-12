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
    for B in iter_subsets(A):
        if len(B) == 0:
            continue
        for C in iter_subsets(A - B):
            sB = sum(B)
            sC = sum(C)
            lB = len(B)
            lC = len(C)
            if lC == 0:
                continue
            if sB < sC:
                continue
            if lB == 0 or lC == 0:
                continue
            assert len(B & C) == 0
            if sB == sC:
                return False
            if lB > lC and sB <= sC:
                return False
    return True

def solve(n, low, high):
    sets = list(map(set, combinations(range(low, high+1), n)))
    sets = list(sorted(sets, key=lambda s: sum(s)))
    for i, A in enumerate(sets):
        if check(A):
            return A
        if i % 10000 == 0:
            print(i, '/', len(sets))
    return None

A = solve(7, low=20, high=45)
if A is None:
    print('Nothing found')
else:
    print(A)
    print(''.join(map(str, sorted(A))))