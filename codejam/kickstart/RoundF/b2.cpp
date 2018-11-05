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
vector<pair<int, pair<int, int>>> edges;
int seen[55];

int main()
{
  cin >> T;
  DO(t, 1, T+1) {
    cin >> V >> E;
    edges.clear();
    DO(i, 1, V+1) seen[i] = 0;

    int marked_a = -1, marked_b = -1;
    DO(i, 0, E) {
      int a, b, l;
      cin >> a >> b >> l;
      if (l == 0) marked_a = a, marked_b = b;
      edges.push_back(make_pair(l, make_pair(a, b)));
    }

    sort(all(edges));

    ll ans = 1;
    for (piii edge : edges) {
      int l = edge.first, a = edge.second.first, b = edge.second.second;
      int connected_to_zero_edge = marked_a == a || marked_a == b || marked_b == a || marked_b == b;
      int not_seen = !seen[a] && !seen[b];
      if (connected_to_zero_edge || not_seen) ans *= 2, seen[a] = 1, seen[b] = 1;
    }

    printf("Case #%d: %d\n", t, ans);
  }


  return 0;
}
