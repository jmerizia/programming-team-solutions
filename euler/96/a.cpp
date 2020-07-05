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
//#define endl ('\n')  // avoid flushing
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v){
    cout<<"[";FOR(i,0,sz(v))cout<<v[i]<<(i==sz(v)-1?"":", ");cout<<"]";}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& v){ cout<<"{"<<v.fi<<", "<<v.se<<"}";}

vector<string> grid;
//int cnt;

bool is_safe(int x, int y, char k) {
    int ox = x-x%3, oy = y-y%3;
    FOR(i, 0, 9) if (grid[i][y] == k) return false;
    FOR(j, 0, 9) if (grid[x][j] == k) return false;
    FOR(i, 0, 3) FOR(j, 0, 3) if (grid[i+ox][j+oy] == k) return false;
    return true;
}

bool bt(int zeros) {
    //cnt++;
    //if (cnt % 100000 == 0) {
    //    cout << cnt << endl;
    //}

    if (zeros == 0) return true;
    int x, y;
    FOR(i, 0, 9) FOR(j, 0, 9) if (grid[i][j] == '0') x = i, y = j;
    trav(k, string("123456789")) {
        if (is_safe(x, y, k)) {
            grid[x][y] = k;
            if (bt(zeros-1)) return true;
            grid[x][y] = '0';
        }
    }

    return false;
}

void Solve()
{
    ifstream f;
    f.open("p096_sudoku.txt");
    string tmp;
    int ans;
    FOR(t, 0, 50) {
        getline(f, tmp);
        grid.resize(9);
        FOR(i, 0, 9) {
            getline(f, grid[i]);
        }

        int zeros = 0;
        FOR(i, 0, 9) FOR(j, 0, 9) if (grid[i][j] == '0') zeros++;
        if (!bt(zeros)) {
            cout << "urg, no solution found for test " << t << endl;
            exit(1);
        }
        int num = atoi(grid[0].substr(0, 3).c_str());
        ans += num;
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

