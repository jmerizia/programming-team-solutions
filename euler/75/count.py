def count(L):
    tri = set()
    for a in range(1, L // 3 + 1):
        n = L*L-2*L*a
        d = 2*L-2*a
        if n % d == 0 and n > 0 and d > 0:
            b = n // d
            c = L - a - b
            assert a*a+b*b == c*c
            assert a+b+c == L
            tri.add(tuple(sorted((a, b, c))))
    # print(tri)
    return tri

ans = 0
# for L in range(1_500_000):
mx = -1
tot = 0
zero = 0
for L in range(10000):
    tri = count(L)
    cnt = len(tri)
    mx = max(mx, cnt)
    tot += cnt
    if cnt == 0:
        zero += 1
    if cnt == 10:
        print(L, tri)
    # print(L, cnt)
print('max', mx)
print('avg', tot / 10000)
print('zero', zero)
print(ans)

# most are zero