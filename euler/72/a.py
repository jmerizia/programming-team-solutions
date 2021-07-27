# I think this has to do with prime factors of
# numbers in (1, 1e6).

#       -- n --
#     1 2 3 4 5 6 7 8
#   1
#   2 x
# | 3 x x
# d 4 x   x
# | 5 x x x x
#   6 x       x
#   7 x x x x x x
#   8 x   x   x   x

# We count a fraction if n < d and n and d are coprime.
# So ans is sum of totients

n = int(1e6 + 99)
is_prime = [True] * (n+1)
primes = []
spf = list(range(n+1))
is_prime[1] = False
p = 2
while p*p <= n:
    if is_prime[p]:
        i = p*p
        while i <= n:
            is_prime[i] = False
            if spf[i] == i:
                spf[i] = p
            i += p
    p += 1
for p in range(2, n+1):
    if is_prime[p]:
        primes.append(p)


def factor(n):
    fa = []
    p = spf[n]
    while p <= n and n > 1:
        m = 0
        while n % p == 0:
            m += 1
            n //= p
        fa.append((p, m))
        p = spf[n]
    return fa

def phi(n):
    ans = 1
    fa = factor(n)
    for p, m in fa:
        ans *= (p ** m - p ** (m - 1))
    return ans

print(sum(map(phi, range(2, 1_000_000+1))))
