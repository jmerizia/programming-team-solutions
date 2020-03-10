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

//#define DBG
int n;
vi a;

int bt(int sp=0) {
#ifdef DBG
    FOR(i, 0, sp) cout << ' ';
    FOR(i, 0, n) cout << a[i] << ' ';
    cout << endl;
#endif
    int ans = 0;
    FOR(i, 0, n) if (a[i] > 0) ans++;
    FOR(i, 0, n-1) {
        if (a[i] == 0) continue;
        int j = i+1;
        while (j < n-1 && a[j] == 0) j++;
        if (a[i] == a[j]) {
            a[i]++;
            a[j] = 0;
            ans = min(ans, bt(sp+1));
            a[i]--;
            a[j] = a[i];
        }
    }
#ifdef DBG
    FOR(i, 0, sp) cout << ' ';
    cout << ans << endl;
#endif
    return ans;
}

void Solve()
{
    cin >> n;
    a.resize(n);
    FOR(i, 0, n) cin >> a[i];
    cout << bt() << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

