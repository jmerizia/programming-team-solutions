from itertools import combinations, permutations
from math import gcd


def reduce(f):
    a, b = f
    g = gcd(a, b)
    a, b = a // g, b // g
    assert b != 0
    if b < 0:  # no negatives
        a *= -1
        b *= -1
    return a, b

def is_reduced(f):
    return f[0] == reduce(f[0])

def is_zero(f):
    return f[0] == 0

def is_negative(f):
    return reduce(f[0]) == -1

def add(f1, f2):
    a1, b1 = f1
    a2, b2 = f2
    num = a1 * b2 + a2 * b1
    den = b1 * b2
    return reduce((num, den))

def divide(f1, f2):
    a1, b1 = f1
    a2, b2 = f2
    num = a1 * b2
    den = a2 * b1
    return reduce((num, den))

def multiply(f1, f2):
    a1, b1 = f1
    a2, b2 = f2
    num = a1 * a2
    den = b1 * b2
    return reduce((num, den))

def subtract(a, b):
    return add(a, multiply(b, (-1, 1)))

def apply(a, b, op):
    if op == '+':
        return add(a, b)
    elif op == '-':
        return subtract(a, b)
    elif op == '*':
        return multiply(a, b)
    elif op == '/':
        assert b[0] != 0
        return divide(a, b)
    assert False

def collapse(fracs):
    assert len(fracs) > 0
    if len(fracs) == 1:
        assert fracs[0] == reduce(fracs[0])
        num, den = fracs[0]
        if num > 0 and den == 1:
            return [num]
        else:
            return []
    out = []
    for i in range(len(fracs) - 1):
        a, b = fracs[i], fracs[i+1]
        if is_zero(b):  # denominator can't be zero
            ops = ['+', '-', '*']
        else:
            ops = ['+', '-', '*', '/']
        for op in ops:
            c = apply(a, b, op)
            # print(a, b, c, op)
            fracs2 = fracs[:i] + [c] + fracs[i+2:]
            assert len(fracs2) == len(fracs) - 1
            # print(fracs, '->', fracs2, 'with', op)
            out += collapse(fracs2)
    return out


def max_consecutive_from_one(v):
    for a, b in zip(range(1, len(v)+1), v):
        if a != b:
            return a-1
    return len(v)

def get_possible_answers(comb):
    possible = set()
    for perm in permutations(comb):
        fracs = [(n, 1) for n in perm]
        possible |= set(collapse(fracs))
    return possible


ans = None
best = -1
for comb in combinations(range(10), 4):
    possible = get_possible_answers(comb)
    mx = max_consecutive_from_one(list(sorted(possible)))
    if mx > best:
        print(mx, comb, list(sorted(possible)))
        best = mx
        ans = comb
print(best)
print(''.join(map(str, ans)))
