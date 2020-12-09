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

#for i in range(25, len(x)):
#    ok = False
#    for j in range(2, 26):
#        if x[i] == x[i-j]+x[i-j-1]:
#            ok = True
#    if not ok:
#        print(x[i])
#        break
#    #sm = sum(x[i-j] for j in range(1, 26))
#    #if x[i] != sm:
#    #    print(x[i])
#    #    break
#
tar = 21806024
def find():
    for i in range(len(x)):
        for j in range(len(x)):
            if sum(x[i:j]) == tar:
                return i, j

a, b = find()
print(a, b)

print(sum(x[a:b]))
print(max(x[a:b])+min(x[a:b]))

