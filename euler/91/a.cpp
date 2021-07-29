#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

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
    cout<<"[";FOR(i,0,sz(v))cout<<v[i]<<(i==sz(v)-1?"":", ");cout<<"]";return cout;}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& v){ cout<<"{"<<v.fi<<", "<<v.se<<"}"; return cout;}

const int n = 50;
const double EPS = 1e-6;

int dot(pii a, pii b) {
    return a.fi*b.fi+a.se*b.se;
}

double norm(pii a) {
    return sqrt(a.fi*a.fi+a.se*a.se);
}

pii sub(pii a, pii b) {
    return {a.fi-b.fi, a.se-b.se};
}

bool check(pii a, pii b, pii c) {
    return
        dot(sub(a, c), sub(b, c)) == 0 ||
        dot(sub(a, b), sub(c, b)) == 0 ||
        dot(sub(b, a), sub(c, a)) == 0;
}

void Solve()
{
    cout << "python 2 slow" << endl;
    set<pair<pii, pii> > T;
    FOR(ax, 0, n+1) {
        FOR(ay, 0, n+1) {
            FOR(bx, 0, n+1) {
                FOR(by, 0, n+1) {
                    if ((ax == 0 && ay == 0) || (bx == 0 && by == 0)) {
                        continue;
                    }
                    if (ax == bx && ay == by) {
                        continue;
                    }
                    pii a = {ax, ay};
                    pii b = {bx, by};
                    if (check({0, 0}, a, b)) {
                        pair<pii, pii> t = {min(a, b), max(a, b)};
                        T.insert(t);
                    }
                }
            }
        }
    }
    // trav(e, T) cout << e << endl;
    cout << sz(T) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

