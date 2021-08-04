def check(x):
    n = 18
    x2 = x * x
    for m in range(1, 9+1):
        if (x2 // (10 ** n)) % 10 != m:
            return False
        n -= 2
    return True

tim = 0
for x in range(int(1e9), int(2e9), 10):
    if check(x):
        print('ans =', x)
        break
    tim += 1
    if tim % 1_000_000 == 0:
        print(f'{(x-int(1e9))/int(1e9)*100:.2f}% ', tim, 'iters')
print(tim)