from itertools import permutations

def solve(s):
    subs = [s[i:i+3] for i in range(1, 8)]
    divs = [2, 3, 5, 7, 11, 13, 17]
    return int(s) if all(map(lambda p: int(p[0]) % p[1] == 0, zip(subs, divs))) else 0

s = '0123456789'
print( sum(solve(''.join(perm)) for perm in permutations(s)) )

