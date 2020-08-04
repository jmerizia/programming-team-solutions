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

int n;
string grid[100];

bool has_four_connected(char player){
    // horizontalCheck 
    for (int j = 0; j<n-3 ; j++ ){
        for (int i = 0; i<n; i++){
            if (grid[i][j] == player && grid[i][j+1] == player && grid[i][j+2] == player && grid[i][j+3] == player){
                return true;
            }           
        }
    }
    // verticalCheck
    for (int i = 0; i<n-3 ; i++ ){
        for (int j = 0; j<n; j++){
            if (grid[i][j] == player && grid[i+1][j] == player && grid[i+2][j] == player && grid[i+3][j] == player){
                return true;
            }           
        }
    }
    // ascendingDiagonalCheck 
    for (int i=3; i<n; i++){
        for (int j=0; j<n-3; j++){
            if (grid[i][j] == player && grid[i-1][j+1] == player && grid[i-2][j+2] == player && grid[i-3][j+3] == player)
                return true;
        }
    }
    // descendingDiagonalCheck
    for (int i=3; i<n; i++){
        for (int j=3; j<n; j++){
            if (grid[i][j] == player && grid[i-1][j-1] == player && grid[i-2][j-2] == player && grid[i-3][j-3] == player)
                return true;
        }
    }
    return false;
}


bool is_safe(int x, int y, char k)
{
    if (grid[x][y] != '.') {
        cout << "oops!" << endl;
        exit(0);
    }
    grid[x][y] = k;
    bool ans = !(has_four_connected('r') || has_four_connected('y'));
    grid[x][y] = '.';
    return ans;
}

pii find_next()
{
    FOR(i, 0, n) FOR(j, 0, n) if (grid[i][j] == '.') return {i, j};
    return {-1, -1};
}

int c = 0;

bool bt(int d)
{
    int x, y;
    tie(x, y) = find_next();
    c++;
    if (c % 100000 == 0) {
        cout << c << endl;
        cout << d << endl;
        cout << x << ' ' << y << endl;
    }
    //cout << x << ' ' << y << endl;
    if (x < 0) {
        cout << "yes!" << endl;
        return true;  // solved!
    }
    if (rand() % 2) {
        if (is_safe(x, y, 'y')) {
            grid[x][y] = 'y';
            if (bt(d+1)) return true;
            grid[x][y] = '.';
        }
        if (is_safe(x, y, 'r')) {
            grid[x][y] = 'r';
            if (bt(d+1)) return true;
            grid[x][y] = '.';
        }
    } else {
        if (is_safe(x, y, 'r')) {
            grid[x][y] = 'r';
            if (bt(d+1)) return true;
            grid[x][y] = '.';
        }
        if (is_safe(x, y, 'y')) {
            grid[x][y] = 'y';
            if (bt(d+1)) return true;
            grid[x][y] = '.';
        }
    }
    return false;
}

void print_grid()
{
    FOR(i, 0, n) {
        FOR(j, 0, n) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void Solve()
{
    cin >> n;
    n = 11;
    FOR(i, 0, n) cin >> grid[i];
    int k = 0;
    FOR(i, 0, n) FOR(j, 0, n) if (grid[i][j] == '.') k++;
    cout << k << endl;
    cout << bt(0) << endl;
    //cout << has_four_connected('y') << endl;
    print_grid();
    cout << c << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(6);
    Solve();
    return 0;
}

