//time:15:00+
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
template<class T> T modpow(T a,T b,T m){
    T res=1;for(;b;b/=2,a=(a*a)%m)if(b&1)res=(res*a)%m;return res;}
template<class T> T inv(T a,T b){return 1<a?b-inv(b%a,a)*b/a:1;}
#define debug(...) printf(__VA_ARGS__)
//#define debug(...)

const int N = 1e5+5;
int t, n, m, p[N], q[N];

void Solve()
{
    cin >> t;
    while (t--) {
        cin >> n;
        FOR(i, 0, n) cin >> p[i];
        cin >> m;
        FOR(i, 0, m) cin >> q[i];
        ll ep = 0, op = 0, eq = 0, oq = 0;
        FOR(i, 0, n) if (p[i]%2) op++; else ep++;
        FOR(i, 0, m) if (q[i]%2) oq++; else eq++;
        cout << op*oq+ep*eq << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

