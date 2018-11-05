def is_palindrome(s):
    l = len(s)
    return s[:l // 2] == s[(l+1) // 2:][::-1]

largest = -1
for a in reversed(range(1000)):
    for b in reversed(range(1000)):
        c = a*b
        if is_palindrome(str(c)):
            largest = max(largest, c)

print(largest)
