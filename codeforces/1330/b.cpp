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
void re(int& e){cin>>e;}
void re(ll& e){cin>>e;}
void re(int* v, int n){FOR(i,0,n)cin>>v[i];}
void re(vi& v, int n){FOR(i,0,n)cin>>v[i];}
#define debug(...) printf(__VA_ARGS__)
//#define debug(...)

void Solve()
{
    const int N = 200000+99;
    int t, n; vi a(N);
    re(t);
    while (t--) {
        re(n); re(a, n);
        multiset<int> L, R;
        set<int> Lu, Ru;
        FOR(i, 0, n) R.insert(a[i]), Ru.insert(a[i]);
        vector<pii> ans;
        FOR(i, 0, n-1) {
            L.insert(a[i]);
            R.erase(R.find(a[i]));
            Lu.insert(a[i]);
            if (!CONTAINS(R, a[i]) && CONTAINS(Ru, a[i])) Ru.erase(Ru.find(a[i]));
            if (*L.rbegin()==sz(L) && sz(L) == sz(Lu) &&
                    *R.rbegin()==sz(R) && sz(R) == sz(Ru))
                ans.pb({sz(L), sz(R)});
        }
        cout << sz(ans) << endl;
        trav(e, ans) cout << e.fi << ' ' << e.se << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}
