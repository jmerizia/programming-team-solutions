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
//#define endl ('\n')  // avoid flushing
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    cout<<"[";FOR(i,0,sz(v))cout<<v[i]<<(i==sz(v)-1?"":", ");cout<<"]";}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& v){ cout<<"{"<<v.fi<<", "<<v.se<<"}";}

const int mxN = 1e5+99;
int t, n, S, ch[mxN];
ll sm; //oops
map<pii, ll> W;
map<int, ll> mp;
multiset<pair<ll, int>, greater<pair<ll, int>>> L;
vi adj[mxN];

int dfs1(int u, int p)
{
    int tot = 0;
    if (sz(adj[u]) == 1 && adj[u][0] == p) {
        tot = 1;
    } else {
        trav(v, adj[u]) {
            if (v != p) {
                tot += dfs1(v, u);
            }
        }
    }
    ch[u] = tot;
    return tot;
}

void dfs2(int u, int p)
{
    trav(v, adj[u]) {
        if (v != p) {
            ll w = W[{u, v}];
            mp[v] = w;
            L.insert({w*ch[v]-w/2*ch[v], v});
            sm += w*ch[v];
            dfs2(v, u);
        }
    }
}

void Solve()
{
    re(t);
    while (t--) {
        re(n), re(S);
        FOR(i, 0, n-1) {
            int a, b, w; re(a); re(b); re(w);
            adj[a].pb(b);
            adj[b].pb(a);
            pii ab = {a, b};
            pii ba = {b, a};
            W[ab] = w;
            W[ba] = w;
        }
        dfs1(1, -1);
        dfs2(1, -1);
        int ans = 0;
        while (sm > S) {
            //if (ans % 100000 == 0) {
            //    cout << sm << endl;
            //}
            auto it = L.begin();
            ll d;
            int v;
            tie(d, v) = *it;
            L.erase(it);
            sm -= d;
            mp[v] /= 2;
            ll nw = mp[v]*ch[v]-mp[v]/2*ch[v];
            L.insert({nw, v});
            ans++;
        }
        cout << ans << endl;

        //clean
        sm = 0;
        FOR(i, 1, n+1) adj[i].clear();
        W.clear();
        L.clear();
        mp.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

