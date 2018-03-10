#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1001;
int n, m;
vector<int> tree[N];
vector<pair<int, pair<int, int>>> edges;

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

int main()
{
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    edges.push_back(make_pair(w, make_pair(a, b)));
  }
  sort(edges.begin(), edges.end());

  DSU dsu(n+1);
  for (int i = 0; i < edges.size(); i++) {
    pair<int, int> cur = edges[i].second;
    if (!dsu.FIND(cur.first, cur.second)) {
      dsu.UNION(cur.first, cur.second);
      tree[cur.first].push_back(cur.second);
      tree[cur.second].push_back(cur.first);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < tree[i].size(); j++) {
      cout << tree[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}
