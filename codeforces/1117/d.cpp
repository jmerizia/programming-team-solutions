#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
ll n, m;
//ll mem[100005];
map<pair<ll, ll>, ll> mem;

////for patterns:
//ll dp(ll k)
//{
//    if (k == n) return 1;
//    if (k > n) return 0;
//    if (mem[k] != -1) return mem[k];
//    return (mem[k] = dp(k+1) + dp(k+m));
//}

ll choose(ll a, ll b) {
    pair<ll, ll> pr = {a, b};
    auto it = mem.find(pr);
    if (it != mem.end()) return it->second;
    if (b == 0 || b == a) return 1;
    if (b == 1) return a;
    return (mem[pr] = (choose(a-1, b-1) + choose(a-1, b))%MOD);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cout << choose(100000000l, 5);

    return 0;
}
