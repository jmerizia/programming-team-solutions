def count(num):
    n = 0
    for i in range(len(num)):
        if num[i] == 'I':
            n += 1
        elif num[i] == 'V':
            if i > 0 and num[i-1] == 'I':
                n += 4 - 1
            else:
                n += 5
        elif num[i] == 'X':
            if i > 0 and num[i-1] == 'I':
                n += 9 - 1
            else:
                n += 10
        elif num[i] == 'L':
            if i > 0 and num[i-1] == 'X':
                n += 40 - 10
            else:
                n += 50
        elif num[i] == 'C':
            if i > 0 and num[i-1] == 'X':
                n += 90 - 10
            else:
                n += 100
        elif num[i] == 'D':
            if i > 0 and num[i-1] == 'C':
                n += 400 - 100
            else:
                n += 500
        elif num[i] == 'M':
            if i > 0 and num[i-1] == 'C':
                n += 900 - 100
            else:
                n += 1000
        else:
            assert False
    return n

def roman(n):
    unit = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M'}
    s = ''
    place = 10 ** (len(str(n)) - 1)
    for d in map(int, str(n)):
        if place == 1000:
            s += 'M' * d
        else:
            if d == 0:
                pass
            elif d == 1:
                s += unit[place]
            elif d == 2:
                s += unit[place] * 2
            elif d == 3:
                s += unit[place] * 3
            elif d == 4:
                s += unit[place] + unit[place * 5]
            elif d == 5:
                s += unit[place * 5]
            elif d == 6:
                s += unit[place * 5] + unit[place]
            elif d == 7:
                s += unit[place * 5] + unit[place] * 2
            elif d == 8:
                s += unit[place * 5] + unit[place] * 3
            elif d == 9:
                s += unit[place] + unit[place * 10]
        place //= 10
    return s

for i in range(10_000):
    assert count(roman(i)) == i, i


ans = 0
with open('roman.txt', 'r') as f:
    lines = [line.strip() for line in f.readlines()]
    for line in lines:
        l = len(line)
        n = count(line)
        optimal = roman(n)
        saved = len(line) - len(optimal)
        assert saved > -1
        ans += saved
print(ans)
