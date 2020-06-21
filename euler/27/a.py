m = int(1e6)
is_prime = [True for _ in range(m+1)]
is_prime[0] = False
is_prime[1] = False
k = 2

while k * k <= m:
    if is_prime[k]:
        for i in range(k*k, m+1, k):
            is_prime[i] = False
    k += 1
primes = [p for p in range(1000) if is_prime[p]]

def longest(a, b):
    n = 0
    while is_prime[n*n+a*n+b]:
        n += 1
    return n+1

ans = -1
l = -1
idx = 0
for a in range(-999, 1000):
    for b in range(-1000, 1001):
        k = longest(a, b)
        if k > l:
            l = k
            ans = (a, b)

print(ans[0]*ans[1])
