def rev(n):
    return int(str(n)[::-1])

def is_palindrome(n):
    s = str(n)
    return s == s[::-1]

def is_lychrel(n, it=50):
    c = n
    # print(c)
    for _ in range(it):
        c += rev(c)
        # print(c)
        if is_palindrome(c):
            return False
    return True

ans = 0
for n in range(10_000):
    if is_lychrel(n, it=100):
        ans += 1
print(ans)
