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
        groups.resize(n);
        card.resize(n, 1);
        for (int i = 0; i < n; i++) {
            groups.push_back(i);
        }
        iota(p.begin(), p.end(), 0);
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
            //merge
            for (int i = 0; i < groups[g2].size(); i++) {
                groups[g1].push_back(groups[g2][i]);
            }
            groups[g2] = vector<int>();
        }
    }
    vector<int> get_group(int a) {
        int la = leader(a);
        return groups[la];
    }
};

void Solve()
{
    int n, r1, c1, r2, c2;
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1--; r2--; c1--; c2--;
    vector<string> G (n);
    for (int i = 0; i < n; i++) {
        cin >> G[i];
    }
    DSU dsu (8000);
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < n-1; j++) {
            if (G[i][j] == G[i+1][j]) dsu.unite(i*100+j, (i+1)*100+j);
            if (G[i][j] == G[i-1][j]) dsu.unite(i*100+j, (i-1)*100+j);
            if (G[i][j] == G[i][j+1]) dsu.unite(i*100+j, i*100+j+1);
            if (G[i][j] == G[i][j-1]) dsu.unite(i*100+j, i*100+j-1);
        }
    }
    int leader_start = dsu.leader(r1*100+c1);
    int leader_end = dsu.leader(r2*100+c2);
    if (leader_start == leader_end) {
        cout << 0;
    } else {
        // of all points on each island,
        // choose the closest manhattan distance pair
        vector<int> v1 = dsu.get_group(leader_start);
        vector<int> v2 = dsu.get_group(leader_end);
        int ans = INT_MAX;
        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                int a1 = v1[i] / 100;
                int b1 = v1[i] % 100;
                int a2 = v2[j] / 100;
                int b2 = v2[j] % 100;
                ans = min(ans, );
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

