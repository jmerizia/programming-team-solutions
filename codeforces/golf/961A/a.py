n,_=map(int,input().split())
a=list(map(int,input().split()))
print(min(a.count(x+1) for x in range(n)))
