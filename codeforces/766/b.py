input()
a,c=sorted(map(int,input().split())),0
[a[i] for i in range(a)-2: ]
for i in range(len(a)-2):
 if a[i]+a[i+1]>a[i+2]:c=1
print(("NO","YES")[c])
