#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

const int MAXN = 101;
int TC, N, A[MAXN];

void Solve()
{
    cin >> TC;
    while (TC--) {
        cin >> N;
        int k = 0;
        int ans = 0;
        FOR(i, 0, N) cin >> A[i];
        FOR(i, 0, N) {
            if (A[i] == 0) {
                k += 1;
                ans++;
            } else {
                k += A[i];
            }
        }
        if (k == 0) ans++;
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

