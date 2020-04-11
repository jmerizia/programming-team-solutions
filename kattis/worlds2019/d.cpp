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
    cout<<"[";FOR(i,0,sz(v))cout<<(i>0?", ":"")<<v[i];cout<<"]";}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& v){
    cout<<"{"<<v.fi<<", "<<v.se<<"}";}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v){
    cout<<"{";for(auto it=v.begin();it!=v.end();it++){cout<<(it!=v.begin()?", ":"")<<*it;};cout<<"}";}
template <typename T, typename U>
ostream& operator<<(ostream& os, const set<T, U>& v){
    cout<<"{";for(auto it=v.begin();it!=v.end();it++){cout<<(it!=v.begin()?", ":"")<<it->fi;};cout<<"}";}

int n, idx = 0;
vector<pair<char, int>> s;

void Solve()
{
    cin >> n;
    FOR(i, 0, n) {
        string str; cin >> str;
        stringstream ss (str.substr(1, sz(str)));
        int num; ss >> num;
        s.pb({str[0], num});
    }
    map<int, char> st;
    st[1] = 'c';
    st[3] = 'b';
    cout << st << endl;

    //map<int, vector<int>> mp;
    //FOR(i, 0, n) {//fill
    //    int t = s[i].se;
    //    mp[t] = vector<int>(2*n, 0);
    //}
    //FOR(i, 0, 2*n) {
    //    char c = s[i%n].fi;
    //    int t = s[i%n].se;
    //    mp[t][i] += (c == 's') ? 1 : -1;
    //}
    //FOR(i, 0, 2*n) {
    //    char c = s[i].fi;
    //    int t = s[i].se;
    //    print({c, t});
    //    cout << mp[t][i] << endl;
    //}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

