#include <bits/stdc++.h>
using namespace std;

// same as 83, with some small change to the graph

typedef long long ll;
const int INF = 1e9;
int n, m, grid[100][100];
vector<pair<int, int>> adj[100*100];

void init()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != n-1) adj[i*100+j].push_back({(i+1)*100+j, grid[i+1][j  ]});
            if (i != 0)   adj[i*100+j].push_back({(i-1)*100+j, grid[i-1][j  ]});
            if (j != m-1) adj[i*100+j].push_back({i*100+(j+1), grid[i  ][j+1]});
            //if (j != 0)   adj[i*100+j].push_back({i*100+(j-1), grid[i  ][j-1]});
        }
    }
}

int solve(int si, int sj)
{
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > Q;
    int val[100*100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            val[i*100+j] = INF;
    //val[0*100+0] = grid[0][0];
    val[si*100+sj] = grid[si][sj];
    Q.push({grid[si][sj], si*100+sj});
    while (!Q.empty()) {
        int u, c;
        tie(c, u) = Q.top();
        Q.pop();
        for (pair<int, int> nxt : adj[u]) {
            int v = nxt.first,
                cp = c + nxt.second;
            if (cp < val[v]) {
                val[v] = cp;
                Q.push({cp, v}); // shouldn't you remove old value?
            }
        }
    }
    //return val[(n-1)*100+(m-1)];
    int mn = INF;
    for (int i = 0; i < n; i++) {
        mn = min(mn, val[i*100+(m-1)]);
    }
    return mn;
}

int main()
{
    init();
    int mn = INF;
    for (int i = 0; i < n; i++) {
        mn = min(mn, solve(i, 0));
    }
    cout << mn << endl;
    return 0;
}
