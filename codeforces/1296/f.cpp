#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define pb push_back

const int MAXN = 5000+1;
int N, M, B[MAXN];
map<pii, int> MP;
vector<int> ADJ[MAXN];
bool VIS[MAXN];
vector<tiii> QUERIES;
vector<pii> PRS;
vector<vector<int>> P;

bool check()
{
    for(tiii q : QUERIES) {
        int a, b, g;
        tie(a, b, g) = q;
        int cur = b;
        int mn = 1e6;
        while (cur != a) {
            int x = P[a][cur]; //before cur
            pii edge = {x, cur};
            int i = MP[edge];
            mn = min(mn, B[i]);
            cur = x;
        }
        if (mn != g) {
            return false;
        }
    }
    return true;
}

void dfs(int u)
{
    for (int v : ADJ[u]) {
        if (!VIS[v]) {
            VIS[v] = true;
            PRS.pb({u, v});
            dfs(v);
        }
    }
}

void Solve()
{
    cin >> N;
    FOR(i, 0, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ADJ[a].pb(b);
        ADJ[b].pb(a);
        MP[{a, b}] = i;
        MP[{b, a}] = i;
    }
    cin >> M;
    FOR(i, 0, M) {
        int a, b, g;
        cin >> a >> b >> g;
        a--; b--;
        QUERIES.pb({a, b, g});
    }
    P = vector<vector<int>>(N, vector<int>(N));
    FOR(i, 0, N) {
        //note: this is faster than realloc:
        PRS.clear(); 
        FOR(j, 0, N) VIS[j] = false;
        VIS[i] = true;
        dfs(i);
        for (pii pr : PRS) {
            P[i][pr.second] = pr.first;
        }
    }
    //FOR(i, 0, N) {
    //    FOR(j, 0, N) cout << P[i][j] << ' ';
    //    cout << endl;
    //}
    for(tiii q : QUERIES) {
        int a, b, g;
        tie(a, b, g) = q;
        int cur = b;
        while (cur != a) {
            int x = P[a][cur]; //before cur
            pii edge = {x, cur};
            int i = MP[edge];
            B[i] = max(B[i], g);
            cur = x;
        }
    }
    FOR(i, 0, N-1) if (B[i] == 0) B[i] = 1e6;
    if (!check()) {
        cout << "-1" << endl;
    } else {
        FOR(i, 0, N-1) {
            cout << B[i] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

