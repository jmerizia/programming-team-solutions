from functools import lru_cache


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
print('Done sieve')


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


@lru_cache(int(1e7))
def sumdiv(n):
    # sumdiv is multiplicative for prime powers
    out = 1
    for p, m in factor(n):
        out *= sum(p ** i for i in range(m+1))
    return out

def proper(n):
    return sumdiv(n) - n


adj = dict()
for n in range(2, int(1e6+1)):
    s = proper(n)
    if s <= int(1e6):
        adj[n] = s
print('Done building graph')

vis = set()
par = dict()
chains = []
def dfs(u):
    vis.add(u)
    if u in adj:
        v = adj[u]
        if v in vis:  # cycle
            chain = []
            cur = u
            while cur != v:
                chain.append(cur)
                assert cur in par, (cur, par)
                cur = par[cur]
            chain.append(cur)
            chains.append(chain)
        else:
            vis.add(v)
            par[v] = u
            dfs(v)

for n in range(2, int(1e6)+1):
    dfs(n)
    vis.clear()
    par.clear()

uniq = set(tuple(sorted(chain)) for chain in chains)
longest_chain = list(sorted(uniq, key=len))[-1]
print(min(longest_chain))
