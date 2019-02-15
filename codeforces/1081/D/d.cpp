#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
#define c2(x, y, a) x(y(a))
#define c3(x, y, z, a) x(y(z(a)))
#define all(v) v.begin(), v.end()
#define DO(i, a, b) for (int i = (a); i < (b); ++i)
#define DOd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define CONTAINS(C, x) (C.find(x) != C.end())
#define range(v, a, b) vector<int> v((b)-(a)+1); iota(v.begin(),v.end(),a)
#define between(c, a, b) ((a) <= (c) && (c) <= (b))
#define lambda(...) [=](__VA_ARGS__)mutable

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int leader(int a) {
        return p[a] == a ? a : (p[a] = leader(p[a]));
    }
    void unite(int a, int b) {
        int la = leader(a);
        int lb = leader(b);
        if (la != lb) p[lb] = la;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> marked (n+1, 0);
    vector<tiii> edges (m);
    DO(i, 0, k) {
        int a; cin >> a;
        marked[a] = 1;
    }
    DO (i, 0, m) {
        int u, v, w;
        cin >> u >> v >> w;
        tiii edge = make_tuple(w, u, v);
        edges[i] = edge;
    }
    DSU dsu (n+1);
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (tiii &edge : edges) {
        int w, u, v;
        tie(w, u, v) = edge;
        int lu = dsu.leader(u);
        int lv = dsu.leader(v);
        if (lu != lv) {
            dsu.unite(u, v);
            marked[lu] += marked[lv];
            if (marked[lu] == k) {
                ans = w;
                break;
            }
        }
    }
    DO (i, 0, k) {
        if (i > 0) cout << ' ';
        cout << ans;
    }

    // Consider the minimum spanning tree of the graph.
    // Take any edge e not in the minimum spanning tree.
    // e cannot be the distance between any two nodes
    // in the graph, since there exist another path along
    // the MST that has a smaller largest cost.
    // So, any path with e would not be taken, and every
    // distance will be along the MST.
    //
    // Now, all special vertices have the same answer.
    // Suppose not, so let some special vertex v have an
    // answer smaller than another vertex v'.
    // Let e be the edge of highest cost in the path
    // for v'. There must be a path from v' to some other
    // special vertex that goes through e, since there
    // are special vertices on both sides of e. Thus,
    // all vertices have the same answer, which refers
    // to the same edge in the MST.
    //
    // This edge is not the highest cost edge in the MST
    // however. Note that there can be some edge in the
    // MST that does not have special vertices as descendants
    // on either the left or right. In order to guarantee
    // this edge has special vertices on both sides, we run
    // kruskals, but stop once we see a group that contains
    // all the special vertices. The final edge we add must be
    // the answer, since it must connect to groups that
    // each contain special vertices, and it is the largest
    // we have seen. Any higher cost edge will connect
    // two components, only one of which already contains
    // all special vertices.

    return 0;
}
