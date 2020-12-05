# 7:25, 7:17 -- must be faster...
from collections import defaultdict
n = int(input())
par = dict()
orbs = set()
adj = defaultdict(lambda: [])

def dist(x):
    if x == 'COM':
        return 0
    return 1 + dist(par[x])

for i in range(n):
    orb = input()
    a, b = orb.split(')')
    par[b] = a
    orbs.add(a)
    orbs.add(b)
    adj[a].append(b)
    adj[b].append(a)

def bfs():
    Q = ['YOU']
    vis = set()
    dist = dict()
    dist['YOU'] = 0
    while len(Q):
        u = Q[0]
        Q = Q[1:]
        if u == 'SAN':
            return dist['SAN']
        for v in adj[u]:
            if v not in vis:
                vis.add(v)
                Q.append(v)
                dist[v] = dist[u]+1

#ans = 0
#for orb in orbs:
#    d = dist(orb)
#    print(orb, d)
#    ans += d
#print(ans)

print(bfs())

