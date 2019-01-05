import math

class Rock:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):
        if isinstance(other, Rock):
            return self.x == other.x and self.y == other.y
        return False

    def __str__(self):
        return "({}, {})".format(self.x, self.y)

    def __hash__(self):
        return self.x*10000 + self.y

    def dist(self, other):
        return math.sqrt((self.x - other.x)**2 + (self.y - other.y)**2)

W, H, N, R = map(int, input().split())
rocks = []
mem_solve = dict()
for _ in range(N):
    a, b = map(int, input().split())
    rocks.append(Rock(a, b))

def can_reach(a, b, c):
    ab = a.dist(b)
    bc = b.dist(c)
    ac = a.dist(c)
    #### shoelace formula:
    ###area = abs((a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y)) / 2)
    #### radius of circumcircle:
    ###print("area:", area)
    ###rad = ab*bc*ac/(4*area) if area > 0.0 else max(ab, bc, ac)
    ###print("rad:", rad)
    #print(ab, bc, ac)
    return max(ab, bc, ac) <= R

#r1 = rocks[0]
#r2 = rocks[1]
#r3 = rocks[2]
#print(r1, r2, r3, can_reach(r1, r2, r3))

# determines if it's possible to reach the top, holding on to rocks a and b
def solve(a, b, prev):
    if (a, b) in mem_solve:
        return mem_solve[(a, b)]
    if (b, a) in mem_solve:
        return mem_solve[(b, a)]
    if R + max(a.y, b.y) >= H:
        return True
    for rock in rocks:
        if rock != prev and can_reach(a, b, rock):
            if solve(a, rock, b) or solve(b, rock, a):
                mem_solve[(a, b)] = True
                mem_solve[(b, a)] = True
                return True
    mem_solve[(a, b)] = False
    mem_solve[(b, a)] = False
    return False

solved = False
for r1 in rocks:
    for r2 in rocks:
        if r1 != r2 and r1.y <= R and r2.y <= R:
            if solve(r1, r2, None):
                print("YES")
                solved = True
                break

if not solved:
    print("NO")
