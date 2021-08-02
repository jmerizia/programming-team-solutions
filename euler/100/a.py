# just exploring

# desmos graphs: https://www.desmos.com/calculator/5kre7afmpq

# (n / (n+m)) * ((n-1)/(n+m-1)) = 1/2
# => n^2 - n = m^2 + 2nm - m
# => n = 1/2(sqrt(8m^2+1)+2m+1)

from math import sqrt, isqrt, exp
import numpy as np



def dist(a, b):
    return sqrt((a[0]-b[0])**2 + (a[1]-b[1])**2)

# odd_squares = []
# for i in range(0, int(5e6)):
#     s = i ** 2
#     if i % 2 == 1:
#         odd_squares.append(s)

# nm = []
# for k2 in odd_squares:
#     if (k2 - 1) % 8 == 0:
#         m = isqrt((k2 - 1) // 8)
#         if m * m == (k2 - 1) // 8:
#             k = isqrt(k2)
#             assert k % 2 == 1
#             assert (k + 2*m + 1) % 2 == 0
#             n = (k + 2*m + 1) // 2
#             assert 2*n*n-2*n == (n+m)*(n+m-1)
#             nm.append((n, m))

# distances = [dist(a, b) for a, b in zip(nm, nm[1:])]
# diffs = [b[1] - a[1] for a, b in zip(nm, nm[1:])]
# print(diffs)
# quit()

# def approx(n):
#     # return 0.34*exp(1.7*(x-0.2))  <-- a rough first guess
#     m, b = 16511547.622050388, -7255093.929824577
#     return m * np.log10(n) + b

def approx(x):
    M = [6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179]
    X = list(range(len(M)))
    c1, c0 = np.polyfit(X, np.log(M), 1)
    y = np.exp(c1 * x + c0)
    return y

def err(a, b):
    return (a-b)/b

# for i in range(len(distances)):
#     x = i + 1
#     a = approx(x)
#     b = distances[i]
#     e = err(a, b)
    # print(x, a, b, e)

def test_one(m):
    k2 = 8*m*m+1
    if k2 % 2 == 1:
        k = isqrt(k2)
        if k * k == k2:
            assert (k + 2*m + 1) % 2 == 0
            n = (k + 2*m + 1) // 2
            assert 2*n*n-2*n == (n+m)*(n+m-1)
            return n
    return None

def odd_squares_in_range(l, r):
    # returns ~sqrt(r-l)/2 numbers
    b = isqrt(l)
    while b * b < l:
        b += 1
    while (b * b) % 2 == 0:
        b += 1
    while b * b < r:
        assert b % 2 == 1
        yield b * b
        b += 2

def first_solution_in_range(m_l, m_r):
    # takes a range of values for m and returns the first possible corresponding value of n
    odd_squares = odd_squares_in_range(8*m_l*m_l+1, 8*m_r*m_r+1)
    checked = 0
    for k2 in odd_squares:
        checked += 1
        # print(k2)
        if (k2 - 1) % 8 == 0:
            m2 = (k2 - 1) // 8
            m = isqrt(m2)
            if m * m == m2:
                k = isqrt(k2)
                assert k * k == k2
                assert (k + 2*m + 1) % 2 == 0
                n = (k + 2*m + 1) // 2
                assert 2*n*n-2*n == (n+m)*(n+m-1)
                print('checked:', checked)
                return (n, m)
    return None


# M = [6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179]
# for idx, m in enumerate(M):
#     m_hat = approx(idx)
#     t = 1.0005
#     l = int(m_hat * 1 / t)
#     r = int(m_hat * t)
#     # print(first_solution_in_range(l, r))
#     print(l / 10000, m / 10000, r / 10000)
#     print(l < m < r)

for x in range(12, 1000):
    m_hat = approx(x)
    t = 1.0005
    l = int(m_hat * 1 / t) - 1
    r = int(m_hat * t) + 1
    n, m = first_solution_in_range(l, r)
    print(n + m)
    if n + m >= int(1e12):
        print(f'{n} blue and {m} red')
        break

# print(first_solution_in_range(7997215, 4_000_000_000))

# print(int(approx(568345)), 1372105)
# print(test_one(1136689))

# l, r = int(a - a * 0.1), int(a + a * 0.1)
# print(test_range(l, r))