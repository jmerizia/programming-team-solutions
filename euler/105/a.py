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
    i, j = 0, len(A) - 1
    B, C = {A[i]}, {A[j]}
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

ans = 0
with open('sets.txt', 'r') as f:
    sets = [set(map(int, line.split(','))) for line in f]
    for idx, A in enumerate(sets):
        if check(A):
            # print(A)
            ans += sum(A)
        if idx % 10 == 0:
            print(idx, '/', len(sets))

print(ans)
