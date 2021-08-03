from math import sqrt, isqrt


# def check1(n):
#     a2_16 = (n+1)**2*(3*n+1)*(n-1)
#     if a2_16 % 16 != 0:
#         return False
#     a2 = a2_16 // 16
#     a = isqrt(a2)
#     return a * a == a2
    
# def check2(n):
#     a2_16 = (n-1)**2*(3*n-1)*(n+1)
#     if a2_16 % 16 != 0:
#         return False
#     a2 = a2_16 // 16
#     a = isqrt(a2)
#     return a * a == a2

def check1(n):
    m2 = (3*n+1)*(n-1)
    if m2 == 0:
        return False
    m = isqrt(m2)
    return m * m == m2
    
def check2(n):
    m2 = (3*n-1)*(n+1)
    if m2 == 0:
        return False
    m = isqrt(m2)
    return m * m == m2

def solve(m):
    print(f'Checking possibilities congruent to 5 (mod {m})')
    solutions = set()
    mx = int((1e9+1))
    for i, n in enumerate(range(m, mx, 16)):
        if check1(n) or check2(n) and n >= 5:
            solutions.add(n)
        if i % int(1e6) == 0:
            print(f'{n/mx*100:0.2f}% ({len(solutions)} solutions found)')
    return solutions

def solve2():
    solutions = set()
    mx = int((1e9+4)//3)
    for i, n in enumerate(range(5, mx)):
        if check1(n) or check2(n):
            solutions.add(n)
        if i % int(1e6) == 0:
            print(f'{n/mx*100:0.2f}% ({len(solutions)} solutions found)')
    return solutions

# solutions = list(sorted(solve(1) | solve(5)))
# solutions = list(sorted(solve2()))
solutions = [5, 17, 65, 241, 901, 3361, 12545, 46817, 174725, 652081, 2433601, 9082321, 33895685, 126500417]  #, 472105985]
print('Found solutions:', solutions)

ans = 0
for n in solutions:
    if check1(n):
        p = 3*n+1
        ans += p
        print(1, n, p)
    if check2(n):
        p = 3*n-1
        ans += p
        print(2, n, p)
print(ans)
