#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

const int MAXN = 2e5+99;
int TC, N, A[MAXN];

void Solve()
{
    cin >> TC;
    while (TC--) {
        cin >> N;
        N *= 2;
        FOR(i, 0, N) cin >> A[i];
        sort(A, A+N);
        int ans = A[N/2]-A[N/2-1];
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

