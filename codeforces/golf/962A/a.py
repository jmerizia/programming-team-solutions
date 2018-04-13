input()
a=list(map(int,input().split()))
t=sum(a)/2
print([sum(a[:i+1])>=t for i in range(len(a))].index(1)+1)
