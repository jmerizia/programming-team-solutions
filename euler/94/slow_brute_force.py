from math import sqrt, isqrt


def bs(target, f):
    l = 1
    r = sqrt(int(1e9))
    for _ in range(30):
        mid = (l + r) / 2
        if f(mid) < target:
            l = mid
        else:
            r = mid
    return mid

def A1(n):
    return sqrt(1/16*(n+1)**2*(3*n+1)*(n-1))

def A2(n):
    return sqrt(1/16*(n-1)**2*(3*n-1)*(n+1))

# def check1(area, n):
#     return area**2 == 1/16*(n+1)**2*(3*n+1)*(n-1)
    
# def check2(area, n):
#     return area**2 == 1/16*(n-1)**2*(3*n-1)*(n+1)


def check1(n):
    a2_16 = (n+1)**2*(3*n+1)*(n-1)
    if a2_16 % 16 != 0:
        return False
    a2 = a2_16 // 16
    a = isqrt(a2)
    return a * a == a2
    
def check2(n):
    a2_16 = (n-1)**2*(3*n-1)*(n+1)
    if a2_16 % 16 != 0:
        return False
    a2 = a2_16 // 16
    a = isqrt(a2)
    return a * a == a2

# def check(n):

# ans = 0
# # for area in range(1, isqrt(int(1e9))):
# for area in range(1, int(1e7)):
#     n = round(bs(area, A1))
#     if check1(area, n):
#         print(n)
#         ans += 3*n+1
#     elif check2(area, n):
#         print(n)
#         ans += 3*n-1
# print(ans)

# oh oops this is too slow lol

ans = 0
for n in range(2, int(3e8)):
    if check1(n):
        print(n)
        ans += 3*n+1
    if check2(n):
        print(n)
        ans += 3*n-1
    if n % int(1e7) == 0:
        print(n)
print(ans)

# some solutions:
# 5
# 17
# 65
# 241
# 901
# 3361
# 12545
# 46817
# 174725
# 652081
# 2433601
# 9082321