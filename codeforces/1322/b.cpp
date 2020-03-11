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
//#define debug(...) printf(__VA_ARGS__)
#define debug(...)

// 010
// 001
// 011
// 001
// ---
// 010+001=011
// 010+011=101
// 010+001=011
// 001+011=101
// 001+001=010
// 011+001=100
//        +334
//        ^110
//
// For a pair of #s, when their kth bits are opposite,
//   then the kth bit of the answer is flipped.
// For a pair of #s, if their sum carries to the kth bit,
//   then the kth bit of the answer is flipped also.
// How many pairs have opposite kth bits?
//  Count zeros and ones from kth bit, answer is zeros*ones.
// How many pairs carry?
//  Create mask m = (1 << k) - 1 for all #s.
//  Note: If sum of #s > m, sum will flip kth bit in answer.
//  Sort masked #s.
//  Ask, for each # x, how many other #s have sum > m?
//  So, use BS to find idx of first value > m-x.
//  Then the # of pairs that carry with x is n-idx.

int n;
vi a, b;

void Solve()
{
    cin >> n;
    a.resize(n);
    b.resize(n);
    trav(e, a) cin >> e;
    int ans = 0;
    FOR(k, 0, 26) {
        debug("-- %d \n", k);
        int c = 0;
        int o = 0, z = 0;
        trav(x, a) if ((x>>k)&1) o++; else z++;
        c ^= (o%2)*(z%2);
        int m = (1<<k)-1;
        FOR(i, 0, n) b[i] = a[i]&m;
        sort(all(b));
        trav(x, b) debug("%d ", x);
        debug("\n");
        FOR(i, 0, n) {
            int x = b[i];
            int j = lower_bound(b.begin()+i+1, b.end(), m-x+1) - b.begin();
            c ^= (n-j)%2;
            debug("%d -> %d \n", m-x+1, n-j);
        }
        ans |= c<<k;
    }
    printf("%d\n", ans);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

