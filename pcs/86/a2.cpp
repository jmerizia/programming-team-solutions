// F=template && g++ -std=c++1y $F.cpp -o $F.bin && ./$F.bin < 1.in
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
#define c2(x, y, a) x(y(a))
#define c3(x, y, z, a) x(y(z(a)))
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pf printf
#define pb push_back
#define DO(i, a, b) for (int i = (a); i < (b); ++i)
#define DOd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define CONTAINS(set, x) (set.find(x) != set.end())

int n, s;
map<pii, vector<pii>> adj;

int bfs(pii st, pii en)
{
  queue<pii> Q;
  map<pii, int> vis;
  Q.push(st);
  vis[st] = 0;
  while (sz(Q)) {
    pii u = Q.front(); Q.pop();
    if (u == en) return vis[u];
    for (pii v : adj[u]) {
      if (!CONTAINS(vis, v)) {
        vis[v] = vis[u] + 1;
        Q.push(v);
      }
    }
  }
  return -1;
}

int main()
{
  cin >> n;
  DO(i, 0, n) {
    cin >> s;
    int x = 0, y = 0;
    pii st (x, y);
    adj.clear();
    DO(j, 0, s) {
      char p; cin >> p;
      pii prev (x, y);
      if (p == 'N') y++;
      if (p == 'S') y--;
      if (p == 'E') x++;
      if (p == 'W') x--;
      pii cur (x, y);
      adj[prev].pb(cur);
      adj[cur].pb(prev);
    }
    pii en (x, y);
    pf("%d\n", bfs(st, en));
  }

  return 0;
}
