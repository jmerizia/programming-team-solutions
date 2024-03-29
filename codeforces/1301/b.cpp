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
#define pb push_back()
#define all(x) (x).begin(),(x).end()
#define sz(x) x.size()
#define trav(v,x) for(auto& v : x)
const ll MOD = 1e9+7;
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T modpow(T a,T b,T m){T res=1;for(;b;b/=2,a=(a*a)%m)if(b&1)res=(res*a)%m;return res;}

const int MAXN = 1e5+1;
int tc, n, a[MAXN];

void Solve()
{ 
    cin >> tc;
    while (tc--) {
        cin >> n;
        FOR(i, 0, n) cin >> a[i];
        int mn = 1e9+2, mx = 0;
        FOR(i, 0, n-1) {
            if (a[i] != -1 && a[i+1] == -1) {
                mn = min(mn, a[i]);
                mx = max(mx, a[i]);
            }
            if (a[i] == -1 && a[i+1] != -1) {
                mn = min(mn, a[i+1]);
                mx = max(mx, a[i+1]);
            }
        }
        int k = (mx+mn)/2;
        FOR(i, 0, n) if (a[i] == -1) a[i] = k;
        int m = 0;
        FOR(i, 0, n-1) m = max(m, abs(a[i]-a[i+1]));
        cout << m << ' ' << k << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

