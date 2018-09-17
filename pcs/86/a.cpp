#include <bits/stdc++.h>
using namespace std;

// So it turns out that I was submitting the same file everytime. 
// I was using rlogin and scp to copy over the files, and I guess
// something went wrong with that...

typedef pair<int, int> pii;

int n, s;
char p;
map<int, vector<int>> adj;

int hsh(pii pr)
{
  return pr.first*1000 + pr.second;
}

int bfs(int start, int target)
{
  queue<int> Q;
  map<int, int> vis;
  Q.push(start);
  while (Q.size()) {
    int u = Q.front(); Q.pop();
    if (u == target) return vis[u];
    for (int v : adj[u]) {
      if (vis.find(v) == vis.end()) {
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
  while (n--) {
    cin >> s;
    int x = 100, y = 100;
    pii start(x, y);
    int cur = 0;
    adj.clear();
    while (s--) {
      cin >> p;
      pii prev = {x, y};
      if (p == 'N') y++;
      if (p == 'S') y--;
      if (p == 'E') x++;
      if (p == 'W') x--;
      pii cur = {x, y};
      adj[hsh(prev)].push_back(hsh(cur));
      adj[hsh(cur)].push_back(hsh(prev));
    }
    cout << bfs(hsh(start), hsh({x, y})) << endl;
  }
  return 0;
}
