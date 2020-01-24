#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())

string to_string(pii pr) {
    return "(" + to_string(pr.first) + ", " + to_string(pr.second) + ")";
}

vector<int> nxt(int cur, int N)
{
    vector<int> p;
    int x = cur / 1000;
    int y = cur % 1000;
    if (x < N-1) p.push_back((x + 1) * 1000 + y); //S
    if (y < N-1) p.push_back(x * 1000 + y + 1); //E
    return p;
}

char get_dir(int a, int b) {
    int ax = a / 1000;
    int ay = a % 1000;
    int bx = b / 1000;
    int by = b % 1000;
    if (bx - ax == 1) return 'S';
    if (by - ay == 1) return 'E';
    assert(0);
}

vector<int> search(set<pair<pii, pii>>& bad, int N, int start, int target)
{
    vector<bool> vis (int(1e6+1), false);
    queue<int> Q;
    map<int, int> par;
    vis[start] = true;
    Q.push(start);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == target) {
            vector<int> path;
            int k = target;
            path.push_back(k);
            while (CONTAINS(par, k)) {
                k = par[k];
                path.push_back(k);
            }
            reverse(path.begin(), path.end());
            return path;
        }
        for (int v : nxt(u, N)) {
            //pair<pii, pii> uv = {u, v};
            //if (CONTAINS(bad, uv)) { continue; }
            if (!vis[v]) {
                vis[v] = true;
                Q.push(v);
                par[v] = u;
            }
        }
    }
    assert(0);
}

set<pair<pii, pii>> get_bad(string& s, int N)
{
    int x = 0, y = 0;
    set<pair<pii, pii>> bad;
    for (char c : s) {
        pii u = {x, y};
        if (c == 'S') { x++; }
        if (c == 'E') { y++; }
        pii v = {x, y};
        bad.insert({u, v});
    }
    return bad;
}

void Solve()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N; string s; cin >> N >> s;
        auto bad = get_bad(s, N);
        cout << "here" << endl;
        vector<int> path = search(bad, N, 0, (N-1)*1000 + N-1);
        cout << "Case #" << t << ": ";
        for (int i = 0; i < path.size() - 1; i++) {
            cout << get_dir(path[i], path[i+1]);
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

