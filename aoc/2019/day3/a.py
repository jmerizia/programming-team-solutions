# 55:37  -- oof!
import numpy as np
L = 10000

Ad = input().split(',')
Bd = input().split(',')

def inter(v, h):
    (vl, vr), x = v
    (hl, hr), y = h
    return vl <= y <= vr and hl <= x <= hr

cx, cy = L//2, L//2
vs, hs = [], []
for d in Ad:
    k = int(d[1:])
    if d[0] == 'R':
        cy += k
        bar = ((cy-k,cy),cx)
        vs.append(bar)
    if d[0] == 'L':
        cy -= k
        bar = ((cy,cy+k),cx)
        vs.append(bar)
    if d[0] == 'U':
        cx += k
        bar = ((cx-k,cx),cy)
        hs.append(bar)
    if d[0] == 'D':
        cx -= k
        bar = ((cx,cx+k),cy)
        hs.append(bar)

inters = []
cx, cy = L//2, L//2
for d in Bd:
    k = int(d[1:])

    if d[0] == 'R':
        cy += k
        v = ((cy-k,cy),cx)
        for h in hs:
            pt = (v[1], h[1])
            if inter(v, h) and pt != (L//2, L//2):
                inters.append(pt)
    if d[0] == 'L':
        cy -= k
        v = ((cy,cy+k),cx)
        for h in hs:
            pt = (v[1], h[1])
            if inter(v, h) and pt != (L//2, L//2):
                inters.append(pt)
    if d[0] == 'U':
        cx += k
        h = ((cx-k,cx),cy)
        for v in vs:
            pt = (v[1], h[1])
            if inter(v, h) and pt != (L//2, L//2):
                inters.append(pt)
    if d[0] == 'D':
        cx -= k
        h = ((cx,cx+k),cy)
        for v in vs:
            pt = (v[1], h[1])
            if inter(v, h) and pt != (L//2, L//2):
                inters.append(pt)

def dist(a, b):
    ax, ay = a
    bx, by = b
    return abs(ax - bx) + abs(ay - by)

ans = 100000000
for a in inters:
    ans = min(ans, dist(a, (L//2, L//2)))

print(ans)
