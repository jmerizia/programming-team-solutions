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
vector<pii> ADJ[MAXN];
vector<tiii> QUERIES;
vector<tiii> PRS;
vector<vector<pii>> P;
int tim = 0;

bool check()
{
    for(tiii q : QUERIES) {
        int a, b, g;
        tie(a, b, g) = q;
        int cur = b;
        int mn = 1e6;
        while (cur != a) {
            int x, i;
            tie(x, i) = P[a][cur]; //before cur
            mn = min(mn, B[i]);
            cur = x;
        }
        if (mn != g) {
            return false;
        }
    }
    return true;
}

void dfs(int u, int p, int pi, vector<pii>& prs)
{
    tim++;
    prs[u] = {p, pi};
    for (pii pr : ADJ[u]) {
        int v, idx;
        tie(v, idx) = pr;
        if (v != p) {
            dfs(v, u, idx, prs);
        }
    }
}

void Solve()
{
    cin >> N;
    P = vector<vector<pii>>(N, vector<pii>(N));
    //printf("Finished big alloc\n");
    FOR(i, 0, N-1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        ADJ[a].pb({b, i});
        ADJ[b].pb({a, i});
    }
    cin >> M;
    FOR(i, 0, M) {
        int a, b, g;
        cin >> a >> b >> g;
        a--; b--;
        QUERIES.pb({a, b, g});
    }
    //printf("Finished reading\n");
    FOR(i, 0, N) {
        //note: this is faster than realloc:
        dfs(i, -1, -1, P[i]);
    }
    //printf("%d\n", tim);
    //printf("Finished preprocessing\n");
    for(tiii q : QUERIES) {
        int a, b, g;
        tie(a, b, g) = q;
        int cur = b;
        while (cur != a) {
            int x, i;
            tie(x, i) = P[a][cur]; //before cur
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

