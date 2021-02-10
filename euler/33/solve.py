from math import gcd

def feq(a, b, c, d):
    d1 = gcd(a, b)
    d2 = gcd(c, d)
    return a // d1 == c // d2 and b // d1 == d // d2

nums = []
for a in range(10, 100):
    for b in range(a+1, 100):
        if str(a)[0] == str(b)[1]:
            p = int(str(a)[1])
            q = int(str(b)[0])
            if feq(a, b, p, q):
                print(a, b, p, q)
                nums.append((a, b))
        if str(a)[1] == str(b)[0]:
            p = int(str(a)[0])
            q = int(str(b)[1])
            if feq(a, b, p, q):
                print(a, b, p, q)
                nums.append((a, b))

print(len(nums))
A, B = 1, 1
for a, b in nums:
    A *= a
    B *= b
D = gcd(A, B)
print(B // D)
