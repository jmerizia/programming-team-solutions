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

bool is_prime[(int)1e6+1];
vector<int> primes;
void run_sieve(int n)
{
    primes.push_back(1);
    memset(is_prime, true, sizeof(is_prime));
    for (int p = 2; p*p <= n; p++)
        if (is_prime[p])
            for (int i = p*p; i <= n; i += p)
                is_prime[i] = false;
    for (int p = 2; p <= n; p++)
        if (is_prime[p])
            primes.push_back(p);
}

const int N = 1e5+99;
const int P = 1e5; // ~78K
int n, m/*largest prime idx*/, a[N];
set<int> adj[P];
vector<pii> edges;

int bfs(int start)
{
    queue<pii> Q;
    set<int> vis;
    Q.push(start);
    par[start] = -1;
    vis.insert(start);
    while (!sz(Q)) {
        int u = Q.ft();
        Q.pop();
        trav(v, adj[u]) {
            if (CONTAINS(vis, v)) continue;
            vis.insert(v);
            par[v] = u;
        }
    }
    FOR(i, 0, sz(edges)) {
        int p, q;
        tie(p, q) = edges[i];

    }
}

int Solve()
{
    run_sieve(1e6);
    FOR(i, 0, 10) debug("%d ", primes[i]);
    debug("\n");

    re(n); re(a, n);
    int mx = -1; FOR(i, 0, n) mx = max(mx, a[i]);
    m = -1;
    FOR(i, 0, n) {
        debug("%d %d : ", i, a[i]);
        if (is_prime[a[i]] && a[i] > 1) {
            int j = lower_bound(all(primes), a[i])-primes.begin();
            adj[j].insert(0);
            adj[0].insert(j);
            edges.pb({j, 0});
            edges.pb({0, j});
            debug("prime %d %d \n", 0, j);
        } else {
            int x = a[i];
            vi div_idx;
            FOR(j, 1, sz(primes)) {
                int p = primes[j];
                int cn = 0;
                while (x%p==0) x/=p, cn++;
                if (cn%2==1) div_idx.pb(j), m=max(m, j);
                if (x==1) break;
            }
            if (!sz(div_idx)) {
                adj[0].insert(0);
                edges.pb({0, 0});
            } else {
                trav(j, div_idx)
                    trav(k, div_idx)
                        if (j!=k)
                            adj[j].insert(k), edges.pb({j, k});
            }
        }
    }
    m++;
    memset(dist, -1, P);
    FOR(i, 0, m) {
        if (primes[i]*primes[i] > mx) break;
        bfs(i);
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    cout << Solve() << endl;
    return 0;
}

