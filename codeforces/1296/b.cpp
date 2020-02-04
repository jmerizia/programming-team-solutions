#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int TC, S;

void Solve()
{
    cin >> TC;
    while (TC--) {
        cin >> S;
        ll ans = 0;
        while (S) {
            ll p = 1;
            while (p <= S) p *= 10;
            if (p > S) p /= 10;
            ans += p;
            S -= p;
            S += p/10;
        }
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

