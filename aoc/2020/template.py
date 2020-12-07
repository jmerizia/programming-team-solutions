from math import gcd, pow
from collections import defaultdict, deque
from itertools import combinations, permutations, product
from queue import Queue
import random

def mkadj(): return defaultdict(lambda: [])

def bfs(adj, start, target):
    Q = deque()
    depths = dict()
    tree = dict()
    Q.append(start)
    depths[start] = 0
    while len(Q):
        u = Q.popleft()
        if u == target:
            return depths, tree
        for v in adj[u]:
            if v not in depths:
                Q.append(v)
                depths[v] = depths[u] + 1
                tree[v] = u
    return depths, tree

with open('in1', 'r') as f:
    f.read()

