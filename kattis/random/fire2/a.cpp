#include <bits/stdc++.h>
using namespace std;

#define CONTAINS(st, x) (st.find(x) != st.end());
typedef pair<int, int> pii;

int T, w, h;
vector<string> board;
vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int can_make_it() {
    queue<pii> Q_player;
    queue<pii> Q_fire;
    map<pii, int> depth;
    set<pii> fire_spread;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (board[i][j] == '*') {
                pii pos = {i, j};
                Q_fire.push(pos);
                fire_spread.insert(pos);
            }
            if (board[i][j] == '@') {
                pii pos = {i, j};
                Q_player.push(pos);
                depth[pos] = 0;
            }
        }
    }

    while (!Q_player.empty()) {
        // move fire
        int n = Q_fire.size();
        while (n--) {
            pii u = Q_fire.front(); Q_fire.pop();
            int x, y; tie(x, y) = u;
            // printf("fire: %d %d\n", x, y);
            for (pii dir : dirs) {
                int _x, _y; tie(_x, _y) = dir;
                int nx = x+_x, ny = y+_y;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if (board[nx][ny] != '#') {
                        pii v = {nx, ny};
                        if (fire_spread.find(v) == fire_spread.end()) {
                            fire_spread.insert(v);
                            Q_fire.push(v);
                        }
                    }
                }
            }
        }

        // move player
        n = Q_player.size();
        while (n--) {
            pii u = Q_player.front(); Q_player.pop();
            int x, y; tie(x, y) = u;
            // printf("move: %d %d\n", x, y);
            if (x == 0 || y == 0 || x == h-1 || y == w-1) return depth[u]+1;
            for (pii dir : dirs) {
                int _x, _y; tie(_x, _y) = dir;
                int nx = x+_x, ny = y+_y;
                if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                    if (board[nx][ny] == '.') {
                        pii v = {nx, ny};
                        if (fire_spread.find(v) == fire_spread.end()) {
                            // if fire has not spread here yet
                            if (depth.find(v) == depth.end()) {
                                depth[v] = depth[u]+1;
                                Q_player.push(v);
                            }
                        }
                    }
                }
            }
        }
    }
    return -1;
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
        int ans = can_make_it();
        if (ans == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }


    return 0;
}
