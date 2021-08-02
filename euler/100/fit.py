import numpy as np

# The first few solutions for n, m respectively are (which I could find by just using odd squares technique)
N = [1, 3, 15, 85, 493, 2871, 16731, 97513, 568345, 3312555, 19306983, 112529341]
# seems to follow an exponential curve
M = [0, 1, 6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179]
M = M[2:]
X = list(range(len(M)))
Y = [1, 5, 29, 169, 985, 5741, 33461, 195025, 1136689]
# predicting M from X: 16511547.622050388 -7255093.929824577

def approx(x):
    M = [6, 35, 204, 1189, 6930, 40391, 235416, 1372105, 7997214, 46611179]
    X = list(range(len(M)))
    c1, c0 = np.polyfit(X, np.log(M), 1)
    y = np.exp(c1 * x + c0)
    return y

def err(a, b):
    if b == 0:
        return float('inf')
    return abs(a-b)/b

for x, m in zip(X, M):
    m_hat = int(approx(x))
    e = err(m_hat, m) * 100
    print(f'm={m}, m_hat={m_hat}, err={e:.2f}%')
