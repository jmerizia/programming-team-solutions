num_nuggets = 10
ar = []
for i in range(num_nuggets):
    ar.append(int(input()))

for i in range(num_nuggets-1):
    print(ar[i+1] / ar[i])

