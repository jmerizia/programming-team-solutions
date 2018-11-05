import math

powers = set(x*x for x in range(0, 1000))

for a in range(1, 1000):
    for b in range(a+1, 1000):
        c2 = a*a + b*b
        if c2 in powers:
            c = math.floor(math.sqrt(c2) + 0.1)
            if a + b + c == 1000:
                print("{} * {} * {} = {}".format(a, b, c, a*b*c))
