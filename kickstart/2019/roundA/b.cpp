#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

vector<pair<int, int>>
nxt(pair<int, int> u,
    int R, int C)
{
    vector<pair<int, int>> nxt;
    if (u.first > 0) nxt.push_back({u.first - 1, u.second});
    if (u.first < R-1) nxt.push_back({u.first + 1, u.second});
    if (u.second > 0) nxt.push_back({u.first, u.second - 1});
    if (u.second < C-1) nxt.push_back({u.first, u.second + 1});
    return nxt;
}

void
bfs(vector<vector<int>>& distances,
    vector<string>& grid,
    int R, int C)
{
    queue<pair<int, int>> Q;
    set<pair<int, int>> vis;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (grid[i][j] == '1')
                Q.push({i, j}), vis.insert({i, j});
    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();
        for (pair<int, int> v : nxt(u, R, C)) {
            if (!CONTAINS(vis, v)) {
                vis.insert(v);
                distances[v.first][v.second] =
                    distances[u.first][u.second] + 1;
                Q.push(v);
            }
        }
    }
}

int dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// if some pos can reach all squares with value more than k
// monotonic increasing
pair<int, int>
check(vector<vector<int>>& distances,
      int k, int R, int C)
{
    set<pair<int, int>> more_than_k;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (distances[i][j] > k)
                more_than_k.insert({i, j});
    cout << "more than k:" << endl;
    for (pair<int, int> p : more_than_k) {
        cout << p.first << " " << p.second << ", ";
    }
    if (more_than_k.size() == 0) return {0, 0};
    int mx1 = INT_MIN, mn1 = INT_MAX,
        mx2 = INT_MIN, mn2 = INT_MAX;
    pair<int, int> p1, p2, p3, p4;
    for (pair<int, int> p : more_than_k) {
        int a = abs(p.first + p.second),
            b = abs(p.first - p.second);
        if (mx1 < a) {
            mx1 = a;
            p1 = p;
        }
        if (mn1 > a) {
            mn1 = a;
            p2 = p;
        }
        if (mx2 < b) {
            mx2 = b;
            p3 = p;
        }
        if (mn2 > b) {
            mn2 = b;
            p4 = p;
        }
    }
    cout << p1.first << " " << p1.second << endl;
    cout << p2.first << " " << p2.second << endl;
    cout << p3.first << " " << p3.second << endl;
    cout << p4.first << " " << p4.second << endl;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            pair<int, int> p = {i, j};
            if (dist(p1, p) <= k &&
                dist(p2, p) <= k &&
                dist(p3, p) <= k &&
                dist(p4, p) <= k) {
                return p;
            }
        }
    return {-1, -1};
}

pair<int, int> bsearch(vector<vector<int>>& distances, int R, int C) {
    auto p = check(distances, 0, R, C);
    return p;
    //int l = 0, r = R + C, mid;
    //pair<int, int> p;
    //for (int i = 0; i < 30; i++) {
    //    mid = (l + r) / 2;
    //    p = check(distances, mid, R, C);
    //    cout << mid << ": " << p.first << " " << p.second << endl;
    //    if (p.first == -1) l = mid;
    //    else r = mid;
    //}
    //return p;
}

void Solve()
{
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int R, C; cin >> R >> C;
        vector<string> grid;
        for (int i = 0; i < R; i++) {
            string s; cin >> s;
            grid.push_back(s);
        }

        vector<vector<int>> distances (R, vector<int>(C, 0));
        bfs(distances, grid, R, C);
        pair<int, int> p = bsearch(distances, R, C);
        cout << p.first << ' ' << p.second << endl;
        //for (int i = 0; i < R; i++) {
        //    for (int j = 0; j < C; j++) {
        //        cout << distances[i][j] << ' ';
        //    }
        //    cout << endl;
        //}

    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

