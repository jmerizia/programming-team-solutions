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
#define endl ('\n')  // avoid flushing
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    cout<<"[";FOR(i,0,sz(v))cout<<v[i]<<(i==sz(v)-1?"":", ");cout<<"]";}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& v){ cout<<"{"<<v.fi<<", "<<v.se<<"}";}

const int mxN = 3000;
int t, n;
vector<pii> segs;
map<pii, int> mp;
vvi adj;
vi chl;

bool within(pii &a, pii &b)
{
    return b.fi <= a.fi && a.se <= b.se && a != b;
}

bool next_to(pii &a, pii &b)
{
    return a.se < b.fi || b.se < a.fi;
}

void build()
{
    FOR(i, 0, n) {
        FOR(j, i+1, n) {
            int a = mp[segs[i]];
            int b = mp[segs[j]];
            if (within(segs[i], segs[j])) {
                adj[a].pb(b);
            } else if (within(segs[j], segs[i])) {
                adj[b].pb(a);
            } else if (next_to(segs[i], segs[j])) {
                adj[a].pb(b);
                adj[b].pb(a);
            }
        }
    }
}

int dfs(int u)
{
    if (!chl[u]) {
        int tot = 1;
        trav(v, adj[u]) {
            tot += dfs(v);
        }
        chl[u] = tot;
    }
}

void clean()
{
    segs.clear();
    adj.clear();
    mp.clear();
}

void Solve()
{
    cin >> t;
    while (t--) {
        cin >> n;
        segs.resize(n);
        adj.resize(n);
        chl.resize(n);
        FOR(i, 0, n) {
            int l, r; cin >> l >> r;
            segs[i] = {l, r};
            mp[segs[i]] = i;
        }
        build();
        cout << adj << endl;
        //FOR(u, 0, n) dfs(u);
        cout << chl << endl;
        clean();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

