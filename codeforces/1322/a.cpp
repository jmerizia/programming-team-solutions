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
const ll MOD = 1e9+7;
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T modpow(T a,T b,T m){T res=1;for(;b;b/=2,a=(a*a)%m)if(b&1)res=(res*a)%m;return res;}
template<class T> T inv(T a,T b){return 1<a?b-inv(b%a,a)*b/a:1;}
//#define debug(...) printf(__VA_ARGS__)
#define debug(...)

int n;
string s;
vi a;

void no() { cout << -1 << endl; };

void Solve()
{
    cin >> n >> s;
    a.resize(n);
    int k = 0;
    vector<pii> v;
    FOR(i, 0, n) {
        char c = s[i];
        k += c=='('?1:-1;
        debug("%d ", k);
        if (k < 0) {
            if (sz(v) == 0 || v.bk.se != -1) {
                v.pb({i, -1});
            }
        } else if (k == 0) {
            if (sz(v) > 0 && v.bk.se == -1) {
                v.bk.se = i;
            }
        }
    }
    debug("\n");
    trav(p, v) debug("(%d %d), ", p.fi, p.se);
    debug("\n");
    if (k != 0) return no();
    if (sz(v) > 0 && v.bk.se == -1) return no();
    int ans = 0;
    trav(p, v) ans += p.se-p.fi+1;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

