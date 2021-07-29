# another brute force?
from math import cos, sqrt, pi
from turtle import *
EPS = 0.000001

def dot(a, b):
    return a[0]*b[0] + a[1]*b[1]

def norm(a):
    return sqrt(a[0]**2 + a[1]**2)

def check(a, b):
    return abs(dot(a, b) - norm(a) * norm(b) * cos(pi/2)) < EPS

def sub(a, b):
    return (a[0]-b[0], a[1]-b[1])

def check_tri(a, b, c):
    return check(sub(a, c), sub(b, c)) or check(sub(a, b), sub(c, b)) or check(sub(b, a), sub(c, a))

tim = 0
def points(n):
    global tim
    for x in range(n+1):
        for y in range(n+1):
            tim += 1
            if not x == y == 0:
                yield (x, y)

def bf(n):
    tri = set()
    for a in points(n):
        for b in points(n):
            # if ax == ay == 0 or bx == by == 0 or (ax == bx and ay == by):
            #     continue
            if a[0] == b[0] and a[1] == b[1]:
                continue
            if check_tri((0, 0), a, b):
                tri.add(tuple(sorted( [a, b] )))
    return tri

def draw_line(line, scale=1):
    a, b = line
    penup()
    goto((a[0]*scale, a[1]*scale))
    pendown()
    goto((b[0]*scale, b[1]*scale))
    penup()

def draw_lines(lines, scale=1):
    begin_poly()
    speed(10)
    for line in lines:
        draw_line(line, scale=scale)
        # time.sleep(0.01)
    end_poly()

# tri = bf(5)
# lines = []
# for t in sorted(tri):
#     lines.append(((0, 0), t[0]))
#     lines.append((t[0], t[1]))
#     lines.append((t[1], (0, 0)))
# draw_lines(lines, scale=30)
# done()

tri = bf(35)
print(tim)
print(len(tri))

# print(bf(3))