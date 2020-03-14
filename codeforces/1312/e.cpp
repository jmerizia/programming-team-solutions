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

const int N = 505;
int n, a[N], mem[N][N];

int dp(int l, int r)
{
    debug("%d %d\n", l, r);
    int ret;
    if (mem[l][r] != -1) {
        ret = mem[l][r];
    } else if (r-l==1) {
        ret = a[l];
    } else {
        ret = -1;
        FOR(i, l+1, r-1) {
            int x = dp(l, i);
            int y = dp(i, r);
            if (x != -1 && y != -1 && x == y) {
                ret = x+1;
                break;
            }
        }
    }
    mem[l][r] = ret;
    return ret;
}

void Solve()
{
    re(n); re(a, n);
    FOR(i, 0, n) FOR(j, 0, n) mem[i][j] = -1;
    cout << dp(0, n) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

