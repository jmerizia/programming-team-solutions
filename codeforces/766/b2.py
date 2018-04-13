input()
a=sorted(map(int,input().split()))
print(("NO","YES")[any(x+y>z for x,y,z in zip(a,a[1:],a[2:]))])
