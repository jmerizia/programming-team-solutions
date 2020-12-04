# 
def check(i):
    s = str(i)
    mxg = 1
    g = 1
    for c, d in zip(s, s[1:]):
        if c == d:
            g += 1
            mxg = max(g, mxg)
        else:
            g = 1
    if mxg != 2:
        return False
    for c, d in zip(s, s[1:]):
        if int(c) > int(d):
            return False
    return True

a, b = 193651, 649729
print(sum(check(i) for i in range(a, b)))
