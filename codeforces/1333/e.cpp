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

int n, grid[599][599];
map<pii, pii> mp;
vector<pii> base = {
    {0, 0}, //1
    {1, 0}, //2
    {1, 1}, //3
    {2, 0}, //4
    {1, 2}, //5
    {2, 2}, //6
    {0, 1}, //7
    {2, 1}, //8
    {0, 2}, //9
    {-1, -1}, //fin
};

void Solve()
{
    cin >> n;
    if (n < 3) cout << -1, exit(0);
    FOR(i, 0, sz(base)-1) mp[base[i]] = base[i+1];
    FOR(layer, 3, n) {
        if (layer % 2 == 1) {
            FOR(i, 0, layer) mp[{layer, i}] = {layer, i+1};
            FOR(i, 1, layer+1) mp[{i, layer}] = {i-1, layer};
            if (layer != n-1) mp[{0, layer}] = {0, layer+1};
            else mp[{0, layer}] = {0, 0};
        } else {
            FOR(i, 1, layer+1) mp[{layer, i}] = {layer, i-1};
            FOR(i, 0, layer) mp[{i, layer}] = {i+1, layer};
            if (layer != n-1) mp[{layer, 0}] = {layer+1, 0};
            else mp[{layer, 0}] = {0, 0};
        }
    }
    pii cur; 
    if (n > 3) cur = {3, 0};
    else cur = {0, 0};
    int idx = 1;
    while (cur.fi != -1) {
        grid[cur.fi][cur.se] = idx++;
        cur = mp[cur];
    }

    FOR(i, 0, n) {
        FOR(j, 0, n) cout << grid[i][j] << ' ';
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

