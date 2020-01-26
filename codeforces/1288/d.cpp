#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

const int MAXA = 1e9+10;
const int MAXN = 3e5;
const int MAXM = 8;
int N, M, G[MAXN+1][MAXM+1];
pii B[MAXN+1];

pii f(int x)
{
    int k = 0;
    FOR (i, 0, N) {
        k = 0;
        FOR (j, 0, M) {
            k *= 2;
            k += (G[i][j] >= x);
        }
        B[i] = {k, i};
    }
    sort(B, B+N);
    vector<pii> C;
    k = -1;
    FOR (i, 0, N) {
        if (B[i].first != k) {
            C.push_back(B[i]);
            k = B[i].first;
        }
    }
    for (auto pr1 : C) {
        for (auto pr2 : C) {
            int i, j, a, b;
            tie(a, i) = pr1;
            tie(b, j) = pr2;
            if ((a | b) == (1 << M) - 1) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

pii bsearch()
{
    int l = 0, r = MAXA, x;
    pii ans;
    pii fail = {-1, -1};
    FOR (_, 0, 32) {
        x = (l + r) / 2;
        pii pr = f(x);
        if (pr != fail) l = x, ans = pr;
        else r = x;
    }
    return ans;
}

void Solve()
{
    cin >> N >> M;
    FOR (i, 0, N) FOR (j, 0, M) cin >> G[i][j];
    pii ans = bsearch();
    cout << ans.first+1 << ' ' << ans.second+1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

