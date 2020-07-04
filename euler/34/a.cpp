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

bool is_prime[(int)1e7+1];
vector<int> primes;
int spf[(int)1e7+1];
int pidx[(int)1e7+1];
void run_sieve(int n)
{
    memset(is_prime, true, sizeof(is_prime));
    for (int i = 1; i < n+1; i++)
        spf[i] = i;
    for (int p = 2; p*p <= n; p++)
        if (is_prime[p])
            for (int i = p*p; i <= n; i += p)
                is_prime[i] = false, spf[i]=p;
    for (int p = 2; p <= n; p++)
        if (is_prime[p])
            primes.push_back(p);
    for (int i = 0; i < primes.size(); i++)
        pidx[primes[i]] = i;
}

int dig(int x) {
    int c = 0;
    while (x) x/=10, c++;
    return c;
}

int rot(int x) {
    int d = x%10;
    x/=10;
    x += (int)d*pow(10, dig(x));
    return x;
}

void Solve()
{
    int N = 1e6;
    run_sieve(N*10);
    int ans = 0;
    for (int p : primes) {
        if (p > N) break;
        bool ok = true;
        int r = rot(p);
        while (r != p) {
            if (!is_prime[r]) {
                ok = false;
                break;
            }
            r = rot(r);
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

