#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define all(a) (a).begin(), (a).end()

const int MAXN = 1e5+10;
const int INF = 1e9+10;
int TC, N, M, Sset[26], nxt[MAXN+1][26];
string S, T;

bool possible()
{
    FOR (i, 0, 26) {
        Sset[i] = 0;
    }
    FOR (i, 0, N) {
        Sset[S[i]-'a'] = 1;
    }
    FOR (i, 0, M) {
        if(!Sset[T[i]-'a']) {
            return false;
        }
    }
    return true;
}

void Solve()
{
    cin >> TC;
    FOR(tc, 0, TC){
        cin >> S >> T;
        N = S.size();
        M = T.size();

        if (!possible()) {
            printf("-1\n");
        } else {
            FOR (i, 0, N+1) {
                FOR (j, 0, 26) {
                    nxt[i][j] = -1;
                }
            }
            FORd (i, N, 0) {
                FOR (j, 0, 26) {
                    if (S[i]-'a' == j) {
                        nxt[i][j] = i;
                    } else {
                        nxt[i][j] = nxt[i+1][j];
                    }
                }
            }

            int i = 0;
            int cur = 0;
            int ans = 1;
            while (i < M) {
                if (cur >= N) {
                    ans++;
                    cur = 0;
                }
                int p = nxt[cur][T[i]-'a'];
                if (p == -1) {
                    ans++;
                    cur = 0;
                } else {
                    cur = p + 1;
                    i++;
                }
            }
            printf("%d\n", ans);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

