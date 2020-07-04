from itertools import permutations

s = '123456789'
P = set()
cur = []

def test(l):
    for i in range(1, len(l)):
        for j in range(i+1, len(l)):
            a = int(l[:i])
            b = int(l[i:j])
            c = int(l[j:])
            if a * b == c:
                P.add(c)

def bt():
    if len(cur) == 9:
        pass
        test(''.join(cur))
    else:
        for c in s:
            if c not in cur:
                cur.append(c)
                bt()
                cur.pop()

bt()
print(P, sum(P))
