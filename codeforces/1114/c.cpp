#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, b;
set<ll> fa;

void calc()
{
    int bb = b;
    fa.insert(bb);
    for (ll i = 2; i * i <= bb; i++) {
        if (bb % i == 0) fa.insert(i);
        while (bb % i == 0) bb /= i;
    }
}

int main()
{
    cin>>n>>b;
    calc();
    ll tot = LLONG_MAX;
    for (ll f : fa) {
        ll cnt = 1, tmp = f;
        while (b % tmp == 0) tmp *= f, cnt++;
        cnt--;
        tot = min(tot, (n/f)/cnt);
        cout << cnt << f << endl;
    }
    cout << tot;

    return 0;
}
