#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

const int MAXN = 2e5+2;
ll N, A, B, K, H[MAXN], Skips[MAXN];

ll bsearch(ll h)
{
    ll l = 0, r = (ll)1e9+2;
    FOR (i, 0, 30) {
        ll mid = (l+r)/2;
        ll g = mid*(A+B);
        if (g <= h) l = mid;
        else r = mid;
    }
    return l*(A+B);
}

void Solve()
{
    cin >> N >> A >> B >> K;
    FOR(i, 0, N) cin >> H[i];
    FOR(i, 0, N) {
        ll h = H[i];
        h -= bsearch(h);
        if (h <= 0) h += (A+B);
        h -= A;
        if (h <= 0) {
            Skips[i] = 0;
        } else {
            Skips[i] = (h+A-1)/A;
        }
    }
    sort(Skips, Skips+N);
    ll ans = 0;
    FOR(i, 0, N) {
        K -= Skips[i];
        if (K < 0) break;
        ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

