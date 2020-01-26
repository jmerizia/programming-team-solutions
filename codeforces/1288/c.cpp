#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

const int MOD = 1e9 + 7;
int CHOOSE[2000][2000], N, M, MEM[1001][11];

void Init()
{
    CHOOSE[0][0] = 1;
    for (int n = 1; n < 2000; n++)
        for (int k = 0; k <= n; k++)
            CHOOSE[n][k] = (k == 0) ?
                1 :
                (CHOOSE[n-1][k] + CHOOSE[n-1][k-1]) % MOD;
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 10; j++)
            MEM[i][j] = -1;
}

int f(int cur)
{
    return CHOOSE[N+M-cur][N-cur];
}

int dp(int cur, int len)
{
    //cout << cur << ' ' << len << endl;
    int ans;
    if (MEM[cur][len] != -1) {
        ans = MEM[cur][len];
    } else if (len == M) {
        ans = f(cur);
    } else {
        ans = 0;
        for (int nxt = cur; nxt <= N; nxt++) {
            ans = (ans + dp(nxt, len+1)) % MOD;
        }
    }
    MEM[cur][len] = ans;
    return ans;
}

void Solve()
{
    cin >> N >> M;
    Init();
    cout << dp(1, 0) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

