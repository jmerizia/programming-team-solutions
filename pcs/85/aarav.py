# A codegolf'ed revision of aarav's clever solution
import itertools as i
p,w,r,m,e="+*/-","m%(a,b,c)","int(input())","4 %s "*3+"4",eval
for _ in range(e(r)):print(dict((e(e(w)),e(w)+" = %d"%e(e(w)))for a,b,c in i.product(p,p,p)).get(e(r),"no solution"))
