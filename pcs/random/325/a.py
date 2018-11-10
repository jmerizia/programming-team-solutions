import math

EPS = 1e-10

def continued_fraction(x, n):
    cont_frac = []
    a = 0
    b = 0.0
    for _ in range(n):
        a = int(math.floor(x))
        b = x - a
        cont_frac.append(a)
        if b < EPS:
            break
        x = 1.0 / b
    print(cont_frac)
    return cont_frac

def nth_convergent(cont_frac, n):
    p = 1
    q = 0
    for k in reversed(cont_frac[0:n]):
        p_next = k * p + q
        q_next = p
        p = p_next
        q = q_next

    print(n, p, q)
    return (p, q)

def solve(x, M):
    p = -1
    q = -1
    mx = 40
    cont_frac = continued_fraction(x, 40)
    n = 1
    while True:
        np, nq = nth_convergent(cont_frac, n)
        if (nq > M):
            break
        if (n == mx):
            break
        p = np
        q = nq
        n += 1
    return (p, q)

p, q = solve(0.9, 10)
print("{}/{}".format(p, q))

p, q = solve(0.99997, 10000)
print("{}/{}".format(p, q))
