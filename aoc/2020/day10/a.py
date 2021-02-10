from math import gcd, pow
from collections import defaultdict, deque
from itertools import combinations, permutations, product
from queue import Queue
import random

def mkadj(): return defaultdict(lambda: [])

x = []
with open('in1', 'r') as f:
    for line in f:
        x.append(int(line))

x = [0] + list(sorted(x))

a = 0
b = 1
for i in range(1, len(x)):
    j = x[i] - x[i-1]
    if j == 1:
        a += 1
    else:
        b += 1
print(a*b)
