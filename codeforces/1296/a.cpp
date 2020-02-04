#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int TC, N, A[2001];

void Solve()
{
    cin >> TC;
    while (TC--) {
        cin >> N;
        FOR (i, 0, N) cin >> A[i];
        int ce = 0, co = 0;
        FOR (i, 0, N) {
            if (A[i] % 2 == 0) {
                ce++;
            } else {
                co++;
            }
        }
        if (co % 2 == 1 || (ce > 0 && co > 0)) {
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

