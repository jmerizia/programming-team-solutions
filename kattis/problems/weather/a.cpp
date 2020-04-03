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
#define SAFE

ll add(ll a, ll b) {
#ifdef SAFE
    if ((b > 0) && (a > LLONG_MAX - b)) {
        cout << "Overflow!" << endl;
        cout << a << " + " << b << endl;
        exit(0);
    }
#endif
    return a+b;
}

ll mul(ll a, ll b) {
#ifdef SAFE
    if ((b != 0) && (a > LLONG_MAX / b)) {
        cout << "Overflow!" << endl;
        cout << a << " * " << b << endl;
        exit(0);
    }
#endif
    return a*b;
}

int n;
ll p[4];
ll fa[21];

void Solve()
{
    fa[0] = 1;
    FOR(i, 1, 21) fa[i] = i*fa[i-1];

    cin >> n;
    FOR(i, 0, 4) {
        double in; cin >> in;
        p[i] = (ll)1000000ll*in;
    }
    vll freq; // distinct frequencies
    FOR(i, 0, n+1) FOR(j, i, n+1) FOR(k, j, n+1) {
        int a = i, b = j-i, c = k-j, d = n-k;
        ll tot = fa[n]/fa[a]/fa[b]/fa[c]/fa[d];
        ll sm = 0;
        sm = add(sm, mul(p[0],a));
        sm = add(sm, mul(p[1],b));
        sm = add(sm, mul(p[2],c));
        sm = add(sm, mul(p[3],d));
        freq.pb(mul(sm, tot));
    }
    ll mx = LLONG_MAX;
    trav(f, freq) mx = min(mx, f);
    cout << mx << endl;
    cout << (double)mx << endl;
    return;
    vi par(4*sz(freq), 0);
    priority_queue<pair<ll, int>> Q;
    FOR(i, 0, sz(freq)) Q.push({freq[i], i});
    int cur = sz(freq);
    while (sz(Q) > 1) {
        auto a = Q.top(); Q.pop();
        auto b = Q.top(); Q.pop();
        par[a.se] = cur;
        par[b.se] = cur;
        Q.push({a.fi+b.fi, cur});
        cur++;
    }
    int root = Q.top().se;
    double ans = 0.;
    FOR(i, 0, sz(freq)) {
        int c = i, d = 0;
        while (c != root) c = par[c], d++;
        ans += d*(freq[i]/1000000ll);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

