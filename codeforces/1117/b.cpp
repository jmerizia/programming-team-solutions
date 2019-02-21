#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, k, a[200005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n, greater<ll>());
    ll mx1 = a[0], mx2 = a[1];
    ll cnt = m/(k+1);
    ll tot = cnt*(k*mx1 + mx2) + (m % (k+1))*mx1;
    cout << tot << endl;
    

    return 0;
}
