#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p;
    DSU(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int leader(int a) {
        return p[a] == a ? a : (p[a] = leader(p[a]));
    }
    bool unite(int a, int b) {
        int la = leader(a);
        int lb = leader(b);
        if (la != lb) {
            p[lb] = la;
            return true;
        }
        return false;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, m;
    cin >> n >> m;
    vector<long long> a (n);
    for (int i = 0; i < n; i++) {
        long long w; cin >> w;
        a[i] = w;
    }
    vector<tuple<long long, int, int>> d (m);
    for (int i = 0; i < m; i++) {
        int x, y;
        long long w;
        cin >> x >> y >> w;
        d[i] = make_tuple(w, x-1, y-1);
    }
    int mn = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < a[mn])
            mn = i;
    for (int i = 0; i < n; i++)
        if (i != mn)
            d.push_back(make_tuple(a[mn]+a[i], mn, i));
    sort(d.begin(), d.end());
    DSU dsu (n);
    long long ans = 0;
    for (auto edge : d) {
        long long cost; int x, y;
        tie(cost, x, y) = edge;
        if (dsu.unite(x, y))
            ans += cost;
    }
    cout << ans;
    // Imagine a fully connected graph with all vertices.
    // The cost of an edge is the sum of vertex label,
    // unless there is a deal for that edge that is cheaper.
    // We perform kruskals on this graph to get the answer.
    // However, since there are n^2 edges, we must be clever.
    // Instead, notice that we can completely skip a whole inner
    // iteration if the first index cost + the current index cost
    // is greater than the first inner iteration of the next
    // outer iteration.
    //
    // Or, we can notice that the minimum spanning tree must
    // be the least cost vertex connected with every other
    // vertex, taking deal edges into consideration.

    return 0;
}
