from collections import defaultdict


with open('keylog.txt', 'r') as f:
    ns = f.read().split('\n')

def check(m):
    for n in ns:
        a, b, c = n
        flag = 0
        for k in str(m):
            if flag == 0 and k == a:
                flag = 1
            if flag == 1 and k == b:
                flag = 2
            if flag == 2 and k == c:
                flag = 3
        if flag != 3:
            print(n)
            return False
    return True

# easy enough by hand
ans = 73162890
assert check(ans)
print(ans)
