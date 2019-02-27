#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define CONTAINS(set, x) (set.find(x) != set.end())

struct DSU {
    vector<int> p;
    vector<int> card;
    vector<vector<int>> groups;
    DSU(int n) {
        p.resize(n);
        card.resize(n, 1);
        groups.resize(n);
        iota(p.begin(), p.end(), 0);
        for (int i = 0; i < n; i++) {
            groups[i].push_back(i);
        }
    }
    int leader(int a) {
        return p[a] == a ? a : (p[a] = leader(p[a]));
    }
    void unite(int a, int b) {
        int la = leader(a);
        int lb = leader(b);
        if (la != lb) {
            int g1 = card[la] > card[lb] ? la : lb;
            int g2 = card[la] > card[lb] ? lb : la;
            p[g2] = g1;
            card[g1] += card[g2];
            //put elements in group b into group a
            for (int i = 0; i < groups[g2].size(); i++) {
                groups[g1].push_back(groups[g2][i]);
            }
            groups[g2] = vector<int>();
        }
    }
    vector<int> get_group() { return groups[leader(0)]; }
};

void Solve()
{
    int n; cin >> n;
    vector<int> A;
    DSU dsu (n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        dsu.unite(a, b);
    }
    vector<int> t = dsu.get_group();
    for (int i = 0; i < n; i++) {
        cout << t[i]+1 << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

// start      => 1 2 3 4 5
// 1 adj to 4 => 4 2 3 4 5
// 2 adj to 5 => 4 5 3 4 5
// 3 adj to 4 => 4 5 4 4 5
// 4 adj to 5 => 4 5 4 5 5
