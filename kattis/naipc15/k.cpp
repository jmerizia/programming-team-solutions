#include <bits/stdc++.h>
using namespace std;

class DSU {
  public:
    int sz, ar[N];
    DSU(int _sz)
    {
      sz=_sz;
      for (int i=0; i<sz; ++i) ar[i] = i;
    }
    int leader(int a)
    {
      while (a != ar[a]) a = ar[a];
      return a;
    }
    void UNION(int a, int b)
    {
      ar[leader(b)] = leader(a);
    }
    int FIND(int a, int b)
    {
      compress(a);
      compress(b);
      return leader(a) == leader(b);
    }
    void compress(int a)
    {
      int leader_a = leader(a);
      while (a != ar[a]) {
        int prev = a;
        a = ar[a];
        ar[prev] = leader_a;
      }
    }
    string str()
    {
      stringstream ss;
      ss << '[';
      for(int i = 0; i<sz; i++) ss << ar[i] << (i == sz-1?']':' ');
      return ss.str();
    }
    int operator[] (int a) {return ar[a];}
};

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
#define f first
#define s second

int n;
piii c[205];

int main()
{
  cin >> n;
  DSU dsu(n+5);
  for (int i = 1; i <= n; i++) {
    int x, y, r; cin >> x >> y >> r;
    piii pr = {r, {x, y}};
    c[i] = pr;
  }
  // n+1 is the left wall
  // n+2 is the right wall
  for (int i = 1; i <= n; i++) {
    // add left wall
    if (!dsu.FIND(n+1, i)) dsu.UNION(n+1, i);
    // check if left and right walls are connected
    if (dsu.FIND(n+1, n+2)) 
  }
  return 0;
}
