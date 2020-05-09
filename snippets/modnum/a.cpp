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

//snippet-begin
template<class T>
pair<T, T> bezout(T& a, T& b) {
}
template<class T> T modpow(T a,T b,T m){
    T res=1;
    for(;b;b/=2,a=(a*a)%m)
        if(b&1)
            res=(res*a)%m;
    return res;
}
template <const int &MOD>
class modnum { public:
    int n;
    modnum(int _n) { n = _n % MOD + (_n < 0 ? 0 : _n); }
    explicit operator int() const { return n; }
    explicit operator ll() const { return n; }
    modnum inv() {
        int q, r0 = MOD, r1 = n, t0 = 0, t1 = 1;
        while (r1 != 0) {
            q = r0/r1;
            r0 = r1;
            r1 = 
        }
    }

    modnum& operator+= (modnum o) {n = (n+o.n)%MOD; return *this;}
    modnum& operator-= (modnum o) {n = (n+o.n)%MOD; return *this;}
    modnum& operator*= (modnum o) {n = (((ll)n)*o.n)%MOD; return *this;}
};
const int MAXN = 1000;
int fact[MAXN];
void init_fact(int n) { fact[0] = 1; FOR(i, 1, n+1) fact[i] = i*fact[i-1]; }
//using num = modnum<101>;
//snippet-end

void Solve()
{
    //cout << inv(5, 7);
    cout << (-10)%3 + 3 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

