//2:09:30
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

const int MAX = 1099;
int R, C;
vector<string> g(MAX);

int fill(int x, int y)
{
    if (g[x][y]!='.') return 0;
    g[x][y]='x';
    if (y<C-1&&g[x][y+1]=='.') fill(x, y+1);
    if (x<R-1&&g[x+1][y]=='.') fill(x+1, y);
    if (y>0  &&g[x][y-1]=='.') fill(x, y-1);
    if (x>0  &&g[x-1][y]=='.') fill(x-1, y);
    if (x>0&&y>0    &&g[x-1][y-1]=='.'&&g[x-1][y]=='\\'&&g[x][y-1]=='\\') fill(x-1, y-1);
    if (x<R-1&&y<C-1&&g[x+1][y+1]=='.'&&g[x+1][y]=='\\'&&g[x][y+1]=='\\') fill(x+1, y+1);
    if (x>0&&y<C-1&&g[x-1][y+1]=='.'&&g[x-1][y]=='/'&&g[x][y+1]=='/') fill(x-1, y+1);
    if (x<R-1&&y>0&&g[x+1][y-1]=='.'&&g[x+1][y]=='/'&&g[x][y-1]=='/') fill(x+1, y-1);
    return 1;
}

void Solve()
{
    re(R); re(C);
    FOR(i, 0, R) cin >> g[i];
    int ans = 0;
    FOR(i, 0, R-1) FOR(j, 0, C-1) {
        if (g[i][j]=='/'&&g[i][j+1]=='\\'&&
            g[i+1][j]=='\\'&&g[i+1][j+1]=='/') ans++;
    }
    // remove exterior dots:
    FOR(i, 0, R) fill(i, 0), fill(i, C-1);
    FOR(i, 0, C) fill(0, i), fill(R-1, i);
    FOR(i, 0, R) FOR(j, 0, C) ans += fill(i, j);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

