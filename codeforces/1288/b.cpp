#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

bool all9(ll b)
{
    while (b) {
        if (b%10 != 9) return false;
        b /= 10;
    }
    return true;
}

ll cnt(ll b)
{
    int c = 0;
    while (b) b /= 10, c++;
    return c;
}

void Solve()
{
    ll t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        ll k = cnt(b) - 1 + all9(b);
        ll ans = a * k;
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

