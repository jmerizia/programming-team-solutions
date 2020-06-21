layers = []

def solve(n):
    if n == 1:
        return 1
    numbers = range((2*(n-1)-1)**2+1, (2*n-1)**2+1)
    numbers = list(reversed(numbers))
    numbers = [k for i, k in enumerate(numbers) if i % (2*(n-1)) == 0]
    return sum(numbers) + solve(n-1)

print(solve(501))
