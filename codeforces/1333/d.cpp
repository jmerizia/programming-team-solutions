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
#define endl ('\n')  // avoid flushing
//#define debug(...)

int n, k, idx = 0;
string a;

vi next(int max_extra)
{
    vi v;
    FOR(i, 0, n-1) {
        idx = (idx+1)%(n-1);
        if (a[idx]=='R'&&a[idx+1]=='L') {
            v.pb(idx);
            if (sz(v) == max_extra) break;
        }
    }
    return v;
}

void no()
{
    cout << -1 << endl;
    exit(0);
}

void Solve()
{
    cin >> n >> k >> a;
    int max_moves = 0;
    for (int i = 0, j = 0; i < n; i++) if (a[i] == 'L') max_moves += i-j++;
    if (k > max_moves) no();
    vvi ans;
    for (vi v = next(max_moves-k+1); sz(v) && max_moves > 0 && k > 0; v = next(max_moves-k+1)) {
        trav(i, v) a[i]='L', a[i+1]='R', max_moves--;
        k--;
        ans.pb(v);
    }
    if (max_moves > 0 || k > 0) no();
    trav(v, ans) {
        cout << sz(v) << ' ';
        trav(i, v) cout << i+1 << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

