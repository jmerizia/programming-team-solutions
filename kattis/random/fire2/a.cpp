#include <bits/stdc++.h>
using namespace std;

#define CONTAINS(st, x) (st.find(x) != st.end());
typedef pair<int, int> pii;

int T, w, h;
vector<string> board;
int closest_fire[1001][1001];
vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int init_closest_fires() {
    queue<pii> Q;
    map<pii, int> depth;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == '*') {
                pii pos = {i, j};
                Q.push(pos);
                depth[pos] = 0;
            }
        }
    }
    while (!Q.empty()) {
        pii u = Q.front(); Q.pop();
        int x, y; tie(x, y) = u;
        for (pii dir : dirs) {
            int _x, _y; tie(_x, _y) = dir;
            if (x+_x >= 0 && x+_x < h && y+_y >= 0 && y+_y < w) {
                if (board[x+_x][y+_y] != '#') {
                    pii v = {x+_x,y+_y};
                    if (depth.find(v) == depth.end()) {
                        depth[v] = depth[u]+1;
                        closest_fire[v.first][v.second] = depth[v];
                        Q.push(v);
                    }
                }
            }
        }
    }
    return INT_MAX;
}

int can_make_it(pii start) {
    queue<pii> Q;
    map<pii, int> depth;
    Q.push(start);
    depth[start] = 0;
    while (!Q.empty()) {
        pii u = Q.front(); Q.pop();
        int x, y; tie(x, y) = u;
        if (x == 0 || y == 0 || x == h-1 || y == w-1) return depth[u];
        for (pii dir : dirs) {
            int _x, _y; tie(_x, _y) = dir;
            int next_depth = depth[u]+1;
            if (x+_x >= 0 && x+_x < h && y+_y >= 0 && y+_y < w) {
                if (board[x+_x][y+_y] == '.') {
                    pii v = {x+_x,y+_y};
                    if (closest_fire[v.first][v.second] > next_depth) {
                        if (depth.find(v) == depth.end()) {
                            depth[v] = next_depth;
                            Q.push(v);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

pii find_start() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == '@') return {i, j};
        }
    }
    return {-1, -1};
}

int main()
{
    cin >> T;
    while (T--) {
        board.clear();
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            string row; cin >> row;
            board.push_back(row);
        }
        init_closest_fires();
        pii start = find_start();
        int ans = can_make_it(start);
        if (ans == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans+1);
    }


    return 0;
}
