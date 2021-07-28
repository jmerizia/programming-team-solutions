# attempt 2

ans = set()
for n in range(100):
    K = [(i, n, i ** n) for i in range(1, 100)]
    for i, n, k in K:
        if len(str(k)) == n:
            ans.add((i, n, k))
for i, n, k in sorted(ans, key=lambda x: x[2]):
    print(f'{i} ** {n} = {k} ({len(str(k))} digits)')
print('ans =', len(ans))

# I must have messed up entering the answer...