import numpy as np


def f(n):
    return 1 - n + n**2 - n**3 + n**4 - n**5 + n**6 - n**7 + n**8 - n**9 + n**10

def g(n):
    return n**3

def apply(poly, x):
    ans = 0
    i = 0
    e = len(poly) - 1
    while i < len(poly):
        ans += poly[i] * x ** e
        i += 1
        e -= 1
    return ans

tot = 0
for N in range(1, 100):
    X = list(range(1, N+1))
    Y = [f(x) for x in X]
    poly = np.polyfit(X, Y, N-1)
    poly = [round(c) for c in poly]
    fit = None
    for x in range(1, 10_000):
        y = f(x)
        y_hat = apply(poly, x)
        if y_hat != y:
            fit = y_hat
            break
    if fit is None:
        print('done')
        break
    else:
        print(fit)
        tot += fit

print('total FITs =', tot)