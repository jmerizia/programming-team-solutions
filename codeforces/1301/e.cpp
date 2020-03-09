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

int n, m, q, a[512][512], tim1, tim2;
string g[512];

bool overlap(pii l1, pii r1, pii l2, pii r2)
{
    //printf("%d %d %d %d | %d %d %d %d \n", l1.fi, l1.se, r1.fi, r1.se, l2.fi, l2.se, r2.fi, r2.se);
    if (l1.fi > r2.fi || l2.fi > r1.fi) return false;
    if (l1.se > r2.se || l2.se > r1.se) return false;
    return true;
}

struct Node {
    int val = 0;
    vector<Node> ch;
    pii p1, p2;
    Node(pii _p1, pii _p2) {
        this->p1 = _p1;
        this->p2 = _p2;
        int x1, y1, x2, y2;
        tie(x1, y1) = _p1;
        tie(x2, y2) = _p2;
        if (x1 == x2-1 && y1 == y2-1) {
            this->val = a[x1][y1];
        } else {
            int w = (x2-x1)/2;
            ch.pb(Node({x1, y1}, {x1+w, y1+w}));
            ch.pb(Node({x1+w, y1+w}, {x2, y2}));
            ch.pb(Node({x1, y1+w}, {x1+w, y2}));
            ch.pb(Node({x1+w, y1}, {x2, y1+w}));
            this->val = 0;
            trav(c, ch) this->val = max(this->val, c.val);
        }
    }
    int query(pii _p1, pii _p2) {
        tim2++;
        //printf("%d %d %d %d \n", p1.fi, p1.se, p2.fi, p2.se);
        int x1, y1, x2, y2;
        tie(x1, y1) = _p1;
        tie(x2, y2) = _p2;
        if (x1 <= this->p1.fi && this->p2.fi <= x2 &&
            y1 <= this->p1.se && this->p2.se <= y2) {
            // node completely within query
            //printf("within %d %d %d %d \n", p1.fi, p1.se, p2.fi, p2.se);
            return this->val;
        } else if (overlap(this->p1, this->p2, _p1, _p2)) {
            // node and query have some intersection
            int ret = 0;
            trav(c, ch) ret = max(ret, c.query(_p1, _p2));
            //printf("overlap %d %d %d %d : %d \n", p1.fi, p1.se, p2.fi, p2.se, ret);
            return ret;
        } else {
            // query and node do not intersect
            //printf("no intersection %d %d, %d %d ", _p1.fi, _p1.se, _p2.fi, _p2.se);
            //printf(" w/ %d %d, %d %d \n", p1.fi, p1.se, p2.fi, p2.se);
            return 0;
        }
    }
};


int oob(pii p) {
    return (p.fi < 0 || p.fi >= n || p.se < 0 || p.se >= m);
}

int bfs(pii s, vector<pii> dirs)
{
    queue<pii> Q;
    set<pii> vis;
    Q.push(s);
    vis.insert(s);
    vector<pii> buf;
    char col = g[s.fi][s.se];
    int ret = 1;
    while (true) {
        bool pos = true;
        while (sz(Q)) {
            pii u = Q.ft; Q.pop();
            trav(d, dirs) {
                pii v = {u.fi+d.fi, u.se+d.se};
                tim1++;
                if (oob(v) || g[v.fi][v.se] != col) {
                    pos = false;
                    break;
                }
                if (!CONTAINS(vis, v)) {
                    vis.insert(v);
                    buf.pb(v);
                }
            }
            if (!pos) break;
        }
        if (pos) {
            ret++;
            trav(p, buf) Q.push(p);
            buf.clear();
        } else {
            break;
        }
    }
    return ret;
}

void init()
{
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            set<char> s = {g[i][j], g[i-1][j-1], g[i-1][j], g[i][j-1]};
            if (sz(s) == 4) {//try
                a[i][j] = min(
                        min(
                            bfs({i-1, j-1}, {{-1, -1}, {-1, 0}, {0, -1}}),
                            bfs({i-1, j}, {{-1, 1}, {-1, 0}, {0, 1}})
                           ),
                        min(
                            bfs({i, j-1}, {{1, -1}, {1, 0}, {0, -1}}),
                            bfs({i, j}, {{1, 1}, {1, 0}, {0, 1}, {0, 0}})
                           )
                        );
            }//else 0
        }
    }
}

void Solve()
{
    cin >> n >> m >> q;
    FOR(i, 0, n) cin >> g[i];
    init();
    FOR(i, 0, n) {
        FOR(j, 0, m) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    //cout << tim1 << endl;
    //Node tree ({0, 0}, {512, 512});
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            if (a[i][j] > 0) {

            }
        }
    }
    int ans = tree.query({4, 4}, {5, 5});
    cout << ans << endl;
    cout << tim2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

