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

int n, m, k, tot;
vector<pair<char, int>> path;

void init()
{
    FOR (i, 0, m-1) {
        path.pb({'D', n-1});
        path.pb({'U', n-1});
        path.pb({'R', 1});
    }

    path.pb({'D', 1});
    FOR(i, 0, n-1) {
        path.pb({'L', m-1});
        path.pb({'R', m-1});
        if (i != n-2) path.pb({'D', 1});
    }
    path.pb({'U', n-1});
    path.pb({'L', m-1});
    tot = 0;
    trav(p, path) tot += p.se;
}

void Solve()
{
    cin >> n >> m >> k;
    init();
    if (k > tot) {
        cout << "NO" << endl;
    } else {
        vector<pair<char, int>> ans;
        int cur = 0;
        trav(p, path) {
            if (cur == k) break;
            if (p.se > k-cur) {
                ans.pb({p.fi, k-cur});
                cur += k-cur;
            } else {
                ans.pb(p);
                cur += p.se;
            }
        }
        cout << "YES" << endl;
        trav(p, ans) cout << p.fi << ' ' << p.se << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

