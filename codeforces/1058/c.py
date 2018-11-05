n = int(raw_input())
d = raw_input()

def sm(a, b):
    return sum(int(c) for c in d[a:b])

for i in range(1, n):
    val = sm(0, i)
    j = i
    worked = True
    while j < n and worked:
        cur = 0
        while j < n and int(d[j]) == 0:
            j += 1
        while cur < val and j < n:
            cur += int(d[j])
            j += 1
        if cur != val:
            worked = False
    if worked:
        print "YES"
        quit()

print "NO"
