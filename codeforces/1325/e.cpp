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
//#define DEBUG
#ifdef DEBUG
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

bool is_prime[(int)1e6+1];
vector<int> primes;
int spf[(int)1e6+1];
int pidx[(int)1e6+1];
void run_sieve(int n)
{
    primes.push_back(1);
    memset(is_prime, true, sizeof(is_prime));
    FOR(i, 2, n+1) spf[i] = i;
    for (int p = 2; p*p <= n; p++)
        if (is_prime[p])
            for (int i = p*p; i <= n; i += p) {
                is_prime[i] = false;
                spf[i]=p;
            }
    for (int p = 2; p <= n; p++)
        if (is_prime[p])
            primes.push_back(p);
    FOR(i, 0, sz(primes)) pidx[primes[i]] = i;
}

const int N = 1e5+99;
const int P = 1e5; // ~78K
int n, m/*largest prime idx*/, a[N];
vector<int> adj[P];
vector<pii> edges;

int bfs(int start)
{
    queue<int> Q;
    //node -> {distance to root, which child branch of root}
    pii flag = {-1, -1};
    vector<pii> V(P, flag);
    Q.push(start);
    V[start] = {0, -1};
    while (sz(Q)) {
        int u = Q.ft;
        Q.pop();
        trav(v, adj[u]) {
            if (V[v] != flag) continue;
            Q.push(v);
            int c = V[u].se==-1?v:V[u].se;
            V[v] = {V[u].fi+1, c};
        }
    }
#ifdef DEBUG
    FOR(i, 0, sz(V)) debug("%d: (%d, %d), ",
            primes[i], V[i].fi, V[i].se);
    debug("\n");
#endif
    int mn = MOD;
    trav(e, edges) {
        int i, j;
        tie(i, j) = e;
        // if these nodes take different child branches from the root, 
        // this must be a cycle that goes through the root.
        if (V[i].se != -1 && V[j].se != -1 && V[i].se != V[j].se) {
#ifdef DEBUG
            debug("cycle: %d %d\n", primes[i], primes[j]);
#endif
            mn = min(mn, V[i].fi+V[j].fi+1);
        }
    }
#ifdef DEBUG
    debug("dfs(%d) => %d\n", primes[start], mn);
#endif
    return mn;
}

int Solve()
{
    run_sieve(1e6);
#ifdef DEBUG
    FOR(i, 0, 10) debug("%d ", primes[i]);
    debug("\n");
#endif

    re(n); re(a, n);
    int mx = -1; FOR(i, 0, n) mx = max(mx, a[i]);
    m = -1;
    FOR(i, 0, n) {
#ifdef DEBUG
        debug("%d %d : ", i, a[i]);
#endif
        if (is_prime[a[i]] && a[i] > 1) {
            int j = lower_bound(all(primes), a[i])-primes.begin();
            adj[j].pb(0);
            adj[0].pb(j);
            edges.pb({j, 0});
            edges.pb({0, j});
#ifdef DEBUG
            debug("prime %d %d \n", 0, j);
#endif
        } else {
            int x = a[i];
            vi div_idx;
            int y = 1;
            while (x>1) {
                int p = spf[x];
                int j = pidx[p];
                int cn = 0;
                while (x%p==0) x/=p, cn++;
                if (cn%2==1) div_idx.pb(j), y *= p, m=max(m, j);
            }
            if (!sz(div_idx)) {
                adj[0].pb(0);
                edges.pb({0, 0});
            } else if (sz(div_idx) == 1) {
                adj[0].pb(div_idx[0]);
                adj[div_idx[0]].pb(0);
            } else {
                trav(j, div_idx)
                    trav(k, div_idx)
                        if (j!=k)
                            adj[j].pb(k), edges.pb({j, k});
            }
            a[i] = y;
#ifdef DEBUG
            debug("sz = %d\n", (int)sz(div_idx));
#endif
        }
    }
#ifdef DEBUG
    debug("edges:\n");
    trav(e, edges) debug("%d %d\n", primes[e.fi], primes[e.se]);
    debug("---\n");
#endif
    sort(a, a+n);
    FOR(i, 0, n) if (a[i] == 1) return 1;
    FOR(i, 0, n-1) if (a[i] == a[i+1]) return 2;
    m++;
    int ans = MOD;
    FOR(i, 0, m) {
        if (primes[i]*primes[i] > mx) break;
        ans = min(ans, bfs(i));
    }
    if (ans==MOD) return -1;
    return ans;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout << fixed << setprecision(6);
    printf("%d\n", Solve());
    return 0;
}

