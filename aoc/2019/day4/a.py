# 5:45
def check(i):
    s = str(i)
    two = False
    for j in range(len(s)-1):
        if s[j] == s[j+1]:
            two = True
            break
    if not two:
        return False
    for j in range(len(s)-1):
        if int(s[j]) > int(s[j+1]):
            return False
    return True

a, b = 193651, 649729
ans = 0
for i in range(a, b+1):
    if check(i):
        ans += 1
print(ans)
