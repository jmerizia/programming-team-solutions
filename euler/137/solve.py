from decimal import Decimal, getcontext

getcontext().prec = 200

def is_square(n):
    l = 1
    r = int(1e15)
    for _ in range(100):
        mid = (l+r)//2
        if mid*mid <= n:
            l = mid
        else:
            r = mid
    return l*l == n
    #return int(n**0.5) - n**0.5 == 0

def check(m):
    p = 5*m**2 - 4
    return is_square(p) and int(p**0.5 - 1) % 5 == 0

def check_n(n):
    return is_square( 5*n**2+2*n+1 )

idx = 1
m = 5
last_m = None
while m <= int(1e13):
    if check(m):
        n = int( ((5*m**2 - 4)**0.5 - 1) / 5 )
        print("{}: m = {}, n = {}".format(idx, m, n))
        if last_m:
            ratio = Decimal(m) / Decimal(last_m)
            print("ratio = {}".format(round(ratio, 50)))
            last_m = m
            m = int(m*ratio)
            idx += 1
        else:
            last_m = m
            m += 1
            idx += 1
        print("Just verifying n... ", check_n(n))
    else:
        m += 1

#print(check_n(74049690))
#print(check_n(2665788847))
