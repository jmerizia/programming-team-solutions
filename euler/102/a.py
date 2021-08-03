from math import acos, sqrt, pi

triangles = []
with open('triangles.txt', 'r') as f:
    for line in f:
        a, b, c, d, e, f = list(map(int, line.split(',')))
        triangles.append(( (a, b), (c, d), (e, f) ))

def subtract(v1, v2):
    return (v1[0]-v2[0], v1[1]-v2[1])

def dot(v1, v2):
    return v1[0]*v2[0]+v1[1]*v2[1]

def norm(v):
    return sqrt(dot(v, v))

def angle(v1, v2):
    return acos(dot(v1, v2)/(norm(v1)*norm(v2)))

def cross(a, b):
    return abs(a[0]*b[1]-a[1]*b[0])

def area(triangle):
    centered = (
        subtract(triangle[1], triangle[0]),
        subtract(triangle[2], triangle[0]),
        (0, 0)
    )
    return 0.5*cross(subtract(centered[1], centered[0]), subtract(centered[2], centered[0]))

def close(a, b):
    return abs(a - b) < 1e-6

def inside(point, triangle):
    # make triangle[0] the origin
    a = area((triangle[0], triangle[1], (0, 0)))
    b = area((triangle[0], triangle[2], (0, 0)))
    c = area((triangle[1], triangle[2], (0, 0)))
    return close(a+b+c, area(triangle))

orig = (0, 0)
t1 = ((-340,495), (-153,-910), (835,-947))
t2 = ((-175,41), (-421,-714), (574,-645))
assert inside(orig, t1)
assert not inside(orig, t2)

print(len([1 for triangle in triangles if inside(orig, triangle)]))
