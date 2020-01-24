#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

int dp[1000][1000], grid[1000][1000], pattern[1000][1000], N, M, t, n, m;

void init()
{
    dp[0][0] = grid[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0) {
                if (j > 0) {
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                }
            } else if (j == 0) {
                if (i > 0) {
                    dp[i][j] = dp[i-1][j] + grid[i][j];
                }
            } else {
                dp[i][j] = dp[i-1][j] + \
                           dp[i][j-1] - \
                           dp[i-1][j-1] + \
                           grid[i][j];
            }
        }
    }
}

int ps(int x, int y)
{
    if (x < 0 || y < 0) return 0;
    return dp[x][y];
}

// (a, b) = top left
// (c, d) = bottom right
int get_sum(int a, int b, int c, int d) {
    return ps(c, d) - ps(c, b-1) - ps(a-1, d) + ps(a-1, b-1);
}

bool check(int x, int y)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (pattern[i][j] != grid[i+x][j+y]) {
                return false;
            }
        }
    }
    return true;
}

bool test()
{
    int pattern_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pattern_sum += pattern[i][j];
        }
    }
    for (int i = 0; i < N-n+1; i++) {
        for (int j = 0; j < M-m+1; j++) {
            if (get_sum(i, j, i+n-1, j+m-1) == pattern_sum) {
                if (check(i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Solve()
{
    cin >> t;
    while (t--) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < M; j++) {
                grid[i][j] = tmp[j]-'0';
            }
        }
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < m; j++) {
                pattern[i][j] = tmp[j]-'0';
            }
        }
        init();
        if (test()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

