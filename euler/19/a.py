#         j   f   m   a   m   j   j   a   s   o   n   d
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def is_leap(year):
    if year % 4 == 0:
        if year % 100 == 0:
            if year % 400 == 0:
                return True
            else:
                return False
        else:
            return True
    else:
        return False

ans = 0
dow = 2  # tuesday
for year in range(1901, 2001):
    for m, days in enumerate(months):
        if m == 1 and is_leap(year):
            days += 1
        for day in range(1, days+1):
            if day == 1 and dow == 0:
                ans += 1
            dow += 1
            dow %= 7

print(ans)
