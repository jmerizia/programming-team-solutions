
# 28433*(2**7830457)+1

MOD = int(1e10)
ans = 28433
for i in range(7_830_457):
    ans = (ans * 2) % MOD
ans = (ans + 1) % MOD
print(ans)
