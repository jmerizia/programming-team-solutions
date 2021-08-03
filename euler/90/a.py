from itertools import combinations


def test(a, b):
    squares = [1, 4, 9, 16, 25, 36, 49, 64, 81]
    a = a.copy()
    b = b.copy()
    if 6 in a:
        a.add(9)
    if 9 in a:
        a.add(6)
    if 6 in b:
        b.add(9)
    if 9 in b:
        b.add(6)
    for s in squares:
        i, j = s % 10, s // 10
        works = (i in a and j in b) or (i in b and j in a)
        if not works:
            return False
    return True

ans = 0
sets = [set(t) for t in combinations(range(10), 6)]
for i in range(len(sets)):
    for j in range(i+1, len(sets)):
        a, b = sets[i], sets[j]
        if test(a, b):
            ans += 1
print(ans)
