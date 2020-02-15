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
template<class T> T modpow(T a,T b,T m){T res=1;for(;b;b/=2,a=(a*a)%m)if(b&1)res=(res*a)%m;return res;}

namespace segtree {
    class SegTree { public:
        vi t;
        int def = 0;
        SegTree(vi &v) {
            t = vi(sz(v)*4, def);
        }
        int func(int a, int b) {
            //return a + b;
            if (a == def) return b;
            else if (b == def) return a;
            else return gcd(a, b);
        }
        void modify(int i, int y, int x, int l, int r) {
            if (i < l || r < i) return;
            if (l==r) {
                t[x] = y;
            } else {
                int m = (l+r)/2;
                modify(i, y, x*2, l, m);
                modify(i, y, x*2+1, m+1, r);
                t[x] = func(t[x*2], t[x*2+1]);
            }
        }
        int query(int a, int b, int x, int l, int r) {
            if (b < l || r < a) return def;
            if (a <= l && r <= b) return t[x];
            int m = (l+r)/2;
            return func(query(a, b, x*2, l, m), query(a, b, x*2+1, m+1, r));
        }
        int solve(int q, int a, int b, int x, int l, int r) {
            // 0: no changes
            // 1: one change
            // 2: two+ changes
            int ret;
            if (l==r) {
                if (a <= l && l <= b) {
                    if (t[x]%q==0) ret = 0;
                    else ret = 1;
                } else {
                    ret = 0;
                }
            } else {
                if (b < l || r < a) ret = 0;
                else if (a <= l && r <= b) {
                    if (t[x] == def) ret = 0;
                    else if (t[x]%q==0) ret = 0;
                    else { //something needs to change here
                        int m = (l+r)/2;
                        bool left_good = t[x*2]%q==0;
                        bool right_good = t[x*2+1]%q==0;
                        if (left_good && right_good) {
                            ret = 0;
                        } else if (left_good) {
                            ret = solve(q, a, b, x*2+1, m+1, r);
                        } else if (right_good) {
                            ret = solve(q, a, b, x*2, l, m);
                        } else {
                            ret = 2;
                        }
                    }
                } else {
                    int m = (l+r)/2;
                    ret = max(solve(q, a, b, x*2+1, m+1, r),
                              solve(q, a, b, x*2, l, m));
                }
            }
            //printf("%d %d %d %d\n", x, l, r, ret);
            return ret;
        }
    };
}
using namespace segtree;

const int MAXN = 5e5+1;
int n, q;
vi a;

void Solve()
{
    cin >> n;
    a = vi(n);
    FOR(i, 0, n) cin >> a[i];
    auto tr = SegTree(a);
    FOR(i, 0, n) tr.modify(i+1, a[i], 1, 1, n);
    cin >> q;
    while (q--) {
        //cout << "------" << endl;
        //FOR(i, 0, n*4) cout << tr.t[i] << ' ';
        //cout << endl;
        int typ; cin >> typ;
        if (typ == 1) {
            int l, r, x; cin >> l >> r >> x;
            //printf("query: %d %d %d \n", l, r, x);
            int ans = tr.solve(x, l, r, 1, 1, n) < 2;
            printf(ans?"YES\n":"NO\n");
        } else {
            int i, y; cin >> i >> y;
            tr.modify(i, y, 1, 1, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

