import math

n, m, k = map(int, raw_input().split())

num = -1
den = 1

if (n*m) % k == 0:
    num = n*m/k
elif k % 2 == 0:
    k2 = k/2
    den = 2
    if (n*m) % k2 == 0:
        num = n*m/k2
    else:
        print "NO"
        quit()
else:
    print "NO"
    quit()

if den == 1:
    print "YES"
    print 0, 0
    print 1, 0
    print 0, num * 2
else:
    print "YES"
    print 0, 0
    print 1, 0
    print 0, num
