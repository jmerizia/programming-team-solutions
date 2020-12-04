# 1:30 -- mega oof 
import numpy as np
L = 10000

Ad = input().split(',')
Bd = input().split(',')

def inter(bar1, bar2):
    (ax1, ay1), (bx1, by1) = bar1
    (ax2, ay2), (bx2, by2) = bar2
    if ax1 == bx1:
        vl = min(ay1, by1)
        vr = max(ay1, by1)
        x = ax1
    elif ax2 == bx2:
        vl = min(ay2, by2)
        vr = max(ay2, by2)
        x = ax2
    else:
        return None

    if ay1 == by1:
        hl = min(ax1, bx1)
        hr = max(ax1, bx1)
        y = ay1
    elif ay2 == by2:
        hl = min(ax2, bx2)
        hr = max(ax2, bx2)
        y = ay2
    else:
        return None
    if (x, y) == (L//2, L//2):
        return None
    if vl <= y <= vr and hl <= x <= hr:
        return x, y
    return None

def get_bars(dirs):
    cx, cy = L//2, L//2
    bars = []
    for d in dirs:
        k = int(d[1:])
        if d[0] == 'R':
            bar = ((cx, cy), (cx, cy+k))
            bars.append(bar)
            cy += k
        if d[0] == 'L':
            bar = ((cx, cy), (cx, cy-k))
            bars.append(bar)
            cy -= k
        if d[0] == 'U':
            bar = ((cx, cy), (cx+k, cy))
            bars.append(bar)
            cx += k
        if d[0] == 'D':
            bar = ((cx, cy), (cx-k, cy))
            bars.append(bar)
            cx -= k
    return bars

Abars = get_bars(Ad)
Bbars = get_bars(Bd)

inters = []
for Abar in Abars:
    for Bbar in Bbars:
        pt = inter(Abar, Bbar)
        if pt:
            inters.append(pt)

def delay(intersection, dirs):
    cx, cy = L//2, L//2
    lat = 0
    for d in dirs:
        k = int(d[1:])
        for i in range(k):
            if intersection == (cx, cy):
                return lat
            if d[0] == 'R':
                cy += 1
            if d[0] == 'L':
                cy -= 1
            if d[0] == 'U':
                cx += 1
            if d[0] == 'D':
                cx -= 1
            lat += 1
    raise 'bad intersection'

print(len(inters))
print(min(delay(inter, Ad) + delay(inter, Bd) for inter in inters))
