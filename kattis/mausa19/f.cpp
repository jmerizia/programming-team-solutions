#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
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
ostream& operator<<(ostream& os, const pair<T, U>& v){cout<<"{"<<v.fi<<", "<<v.se<<"}";}

const db EPS = 1e-8;
const int MAXN = 5001;
int n;
vector<pdd> lines;
vector<pdd> check_points;

db dist(pdd a, pdd b) { return sqrt(pow(a.fi-b.fi, 2) + pow(a.se-b.se, 2)); }
pdd mid(pdd a, pdd b) { return {(a.fi+b.fi)/2, (a.se+b.se)/2}; }
db slope(pdd a, pdd b) { return (b.se-a.se)/(b.fi-a.fi); }

pdd circle_center(pdd a, pdd b, pdd c)
{
    db m1 = -1/slope(a, b);
    pdd p1 = mid(a, b);
    db m2 = -1/slope(b, c);
    pdd p2 = mid(b, c);
    db b1 = -1*m1*p1.fi+p1.se;
    db b2 = -1*m2*p2.fi+p2.se;
    db x = (b2-b1)/(m1-m2);
    db y = m1*x+b1;
    assert(abs((m2*x+b2)-y)<EPS);
    return {x, y};
}

#define ITERS 45
#define MN -1500
#define MX 1500
#define LINES 50
int bad_cnt = 0;
int good_cnt = 0;
//db MN = 5000;
//db MX = -5000;

bool check(pdd p, db d, vd &x, vd &y)
{
    // Given, a circle query, determine if any point lies outside
    bool check = true;
    FOR(i, 0, n) if (2*dist(p, {x[i], y[i]}) > d) { check = false; break; }

    bool ans = true;
    trav(c, check_points) if (2*dist(p, c) > d) { ans = false; break; }
    if (ans != check) bad_cnt++;
    else good_cnt++;
    return ans;
}

db ts_d(pdd p, vd &x, vd &y)
{
    db m, l = MN, r = MX;
    FOR(i, 0, 40) {
        m = (r+l)/2;
        if (check(p, m, x, y)) r = m;
        else l = m;
    }
    return m;
}

db ts_py(db px, vd &x, vd &y)
{
    db m1=1, m2=2, v1, v2, l = MN, r = MX, d;
    while(abs(m2-m1)>EPS) {
        d = (r-l)/3;
        m1 = l+d;
        m2 = l+2*d;
        v1 = ts_d({px, m1}, x, y);
        v2 = ts_d({px, m2}, x, y);
        if (v1 < v2) r = m2;
        else l = m1;
    }
    return v1;
}

db calc(vd &x, vd &y)
{
    // For each line, pre-process the projections
    check_points.clear();
    trav(line, lines) {
        db m, b; tie(m, b) = line;
        db mnd = 5000;
        db mxd = -5000;
        pdd mnp, mxp;
        FOR(i, 0, n) {
            db dd = (m*y[i]+x[i])/(m*m+1); // check this
            if (dd < mnd) {
                mnd = dd;
                mnp = {x[i], y[i]};
            }
            if (dd > mxd) {
                mxd = dd;
                mxp = {x[i], y[i]};
            }
        }
        check_points.pb(mnp);
        check_points.pb(mxp);
    }

    db m1=1, m2=2, v1, v2, l = MN, r = MX, d;
    while (abs(m2-m1)>EPS) {
        d = (r-l)/3;
        m1 = l+d;
        m2 = l+2*d;
        v1 = ts_py(m1, x, y);
        v2 = ts_py(m2, x, y);
        if (v1 < v2) r = m2;
        else l = m1;
    }
    return v1;
}

void Solve()
{
    // preprocess some random lines:
    FOR(i, 0, LINES) {
        db m = (rand()%1000)*1e-3;
        db b = 0.0;
        lines.pb({m, b});
    }
    cin >> n; vd x(n), y(n), z(n);
    FOR(i, 0, n) cin >> x[i] >> y[i] >> z[i];
    db d1 = calc(x, y);
    db d2 = calc(y, z);
    db d3 = calc(x, z);
    cout << bad_cnt << ' ' << good_cnt << endl;
    cout << min(d1, min(d2, d3)) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

