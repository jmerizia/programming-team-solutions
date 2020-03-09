#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
typedef pair<int, double> pid;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<double> vd;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define ROF(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define fi first
#define se second
#define bk back()
#define ft front()
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) x.size()
#define trav(v,x) for(auto& v : x)
const ll MOD = 998244353;
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T modpow(T a,T b,T m){T res=1;for(;b;b/=2,a=(a*a)%m)if(b&1)res=(res*a)%m;return res;}
ll inv(ll a,ll b){return 1<a?b-inv(b%a,a)*b/a:1;}

const int MAXN = 2e5+99;
ll fa[MAXN];

ll choose(ll n, ll k) {
    return (fa[n]*inv((fa[k]*fa[n-k])%MOD, MOD))%MOD;
}

void Solve()
{
    int n, m;
    cin >> n >> m;
    fa[0] = 1;
    FOR(i, 1, m+1) fa[i] = (((ll)fa[i-1])*i)%MOD;
    ll ans = 0;
    FOR(i, 1, n-1) ans = (ans+choose(n-2, i)*i)%MOD;
    ans = (ans*choose(m, n-1))%MOD;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

