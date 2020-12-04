# 2:00, 7:00 (each problem)
nums = map(int, input().split())

tot = 0
for num in nums:
    partial = num//3-2
    while partial >= 0:
        tot += partial
        partial = partial//3-2
        print(partial)

print(tot)
