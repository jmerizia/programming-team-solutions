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
ostream& operator<<(ostream& os, const pair<T, U>& v){
    cout<<"{"<<v.fi<<", "<<v.se<<"}";}

const int MAXN = 2099;
int t, n, a[MAXN], mem[MAXN][MAXN][100];

int dp(int i, int j, int k)
{
    int ret;
    if (mem[i][j][k] != -1) return mem[i][j][k];
    else if (j-i+1<=0) ret = 1;
    else if (a[i] == a[j] && (k == 0 || a[i] == k)) ret = 2+dp(i+1, j-1, a[i]);
    else ret = max(dp(i, j-1, 0), dp(i+1, j, 0));
    return (mem[i][j][k] = ret);
}

void Solve()
{
    cin >> t;
    while (t--) {
        re(n); re(a, n);
        FOR(i, 0, n) FOR(j, 0, n) FOR(k, 0, 30) mem[i][j][k] = -1;
        cout << dp(0, n-1, 0) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

