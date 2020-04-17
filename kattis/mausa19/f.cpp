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

db calc(vd &x, vd &y)
{
    pdd a, b;
    do {
        db d = -1;
        FOR(i, 0, n) FOR(j, i+1, n) {
            db dd = dist({x[i], y[i]}, {x[j], y[j]});
            if (dd > d) {
                d = dd;
                a = {x[i], y[i]};
                b = {x[j], y[j]};
            }
        }
    } while (0);
    bool justtwo = true;
    FOR(i, 0, n) {
        pdd c = {x[i], y[i]};
        pdd p = mid(a, b);
        db r = dist(a, b)/2;
        if (dist(p, c)>r) {
            justtwo = false;
            break;
        }
    }
    cout << justtwo << endl;
    if (justtwo) return dist(a, b);
    db mnd = DBL_MAX;
    FOR(i, 0, n) {
        pdd c = {x[i], y[i]};
        if (c == a || c == b) continue;
        pdd p = circle_center(a, b, c);
        db r = dist(c, p);
        bool worked = true;
        FOR(j, 0, n) {
            pdd d = {x[j], y[j]};
            if (d == a || d == b || d == c) continue;
            if (dist(p, d)>r) {
                worked = false;
                break;
            }
        }
        if (worked) {
            mnd = min(mnd, r*2);
        }
    }
    return mnd;
}

void Solve()
{
    cin >> n; vd x(n), y(n), z(n);
    FOR(i, 0, n) cin >> x[i] >> y[i] >> z[i];
    FOR(i, 0, n) x[i] += (rand()%100)*1e-10;
    FOR(i, 0, n) y[i] += (rand()%100)*1e-10;
    FOR(i, 0, n) z[i] += (rand()%100)*1e-10;
    db d1 = calc(x, y);
    db d2 = calc(y, z);
    db d3 = calc(x, z);
    cout << min(d1, min(d2, d3)) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

