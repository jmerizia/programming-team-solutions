template,string,Set,ImplicitEdgeGraph
// https://codeforces.com/contest/653/problem/E

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    Set<pii> edges;
    DO (i, 0, n) {
        int u, v;
        cin >> u >> v;
        edges.insert({u, v});
    }
    auto f = [edges](int a, int b) {
        return !(edges.contains({a, b}) || edges.contains({b, a}));
    };
    ImplicitEdgeGraph<int> IG (f);
    auto C1 = IG.disjoint_components(rng(1, n+1));
    if (C1.size() > 1)
        cout << "impossible", exit(0);
    auto C2 = IG.disjoint_components(rng(2, n+1)); // connected by 1
    int d = 0;
    for (int node : rng(2, n+1)) if (f(1, node)) d++;
    if (between(k, C2.size(), d))
        cout << "possible";
    else
        cout << "impossible";
}
