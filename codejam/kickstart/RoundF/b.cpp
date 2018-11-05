// F=template && g++ -std=c++1y $F.cpp -o $F.bin && ./$F.bin < 1.in
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
#define c2(x, y, a) x(y(a))
#define c3(x, y, z, a) x(y(z(a)))
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pf printf
#define DO(i, a, b) for (int i = (a); i < (b); ++i)
#define DOd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define CONTAINS(set, x) (set.find(x) != set.end())

// 2^50 assignments, so must be clever
// can preprocess all shortest paths in <= 1050*50 ops
// Is it possible to design assignment so that for any village,
// its closest neighbor is opposite food?
// Note: minimizing avg is same as minimizing total sum
// Can minimum spanning tree be used here?
// Maybe answer is number of unique minimum spanning trees of minimum size?
//  (we can calculate this)
// I think it's greedy... so use a slight modification of mst algorithm:
//  sort edges, and add them to a new graph one at a time until all villages are accounted for
//  (this removes unecessary edges)
// Ok, so I think unless there is a 0 length edge, the answer is 2 exp the number of connected
// components in the mst. However, if there is an edge of length 0, then the two villages with this edge
// must be assigned different foods, so it can be viewed as a single mega-village with both
// foods. So, remove this mega-village from the graph and add 1 to the number of connected
// components, and then count the number of connected components on this new graph.

int T, V, E;
vector<int> tree[55];
vector<pair<int, pair<int, int>>> edges;
vector<int> adj[55];
int marked[55];

class DSU {
  public:
    int sz, ar[55];
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

void kruskals()
{
  sort(edges.begin(), edges.end());
  DSU dsu(V+1);
  for (int i = 0; i < edges.size(); i++) {
    pair<int, int> cur = edges[i].second;
    if (!dsu.FIND(cur.first, cur.second)) {
      dsu.UNION(cur.first, cur.second);
      tree[cur.first].push_back(cur.second);
      tree[cur.second].push_back(cur.first);
    }
  }
}

void flood(int u) {
  if (marked[u]) return;
  marked[u] = 1;
  for (int v : adj[u]) flood(v);
}

int main()
{
  cin >> T;
  DO(t, 1, T+1) {
    cin >> V >> E;
    DO(i, 1, V+1) adj[i].clear();
    DO(i, 1, V+1) tree[i].clear();
    edges.clear();

    DO(v, 1, V+1) marked[v] = 0;
    int marked_a = -1, marked_b = -1;
    DO(i, 0, E) {
      int a, b, l;
      cin >> a >> b >> l;
      if (l == 0) marked_a = a, marked_b = b;
      edges.push_back(make_pair(l, make_pair(a, b)));
    }

    // find mst -> tree[]
    kruskals();

    int components = 0;
    if (marked_a != -1) components++;
    // remove marked vertices in tree 
    DO(i, 1, V+1)
      for (int v : tree[i])
        if (v != marked_a && v != marked_b)
          adj[i].push_back(v);

    DO(v, 1, V+1)
      if (!marked[v]) flood(v), components++;

    printf("Case #%d: %d\n", t, components == 0 ? 0 : (1 << components));
  }


  return 0;
}
