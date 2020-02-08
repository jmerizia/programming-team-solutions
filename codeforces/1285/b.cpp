// time: 45:00
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(x) (x).begin(), (x).end()

const int MAXN = 1e5+1;
int TC, N, A[MAXN];
ll DP1[MAXN], DP2[MAXN];

void Solve()
{
    cin >> TC;
    while (TC--) {
        cin >> N;
        FOR(i, 0, N) cin >> A[i];
        DP1[1] = A[1];
        DP2[0] = A[0];
        FOR(i, 2, N) DP1[i] = max(DP1[i-1], 0ll) + A[i];
        FOR(i, 1, N-1) DP2[i] = max(DP2[i-1], 0ll) + A[i];
        ll best1 = 0;
        ll best2 = 0;
        FOR(i, 1, N) best1 = max(best1, DP1[i]);
        FOR(i, 0, N-1) best2 = max(best2, DP2[i]);
        ll best = max(best1, best2);
        cout << best << endl;
        ll yas = 0;
        FOR(i, 0, N) yas += A[i];
        if (yas > best) {
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

