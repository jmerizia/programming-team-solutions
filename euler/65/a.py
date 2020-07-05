from fractions import Fraction as Frac

# gotta love python default big integers

def cf(seq):
    n = Frac(0, 1)
    for idx, x in enumerate(reversed(seq)):
        n += Frac(x, 1)
        if idx != len(seq)-1:
            n **= -1
    return n

n = 100
seq = [2]
idx = 0
t = 2
while len(seq) < n:
    if (idx % 3 == 1):
        seq.append(t)
        t += 2
    else:
        seq.append(1)
    idx += 1

num = cf(seq).numerator
ans = sum(map(int, str(num)))
print(ans)
