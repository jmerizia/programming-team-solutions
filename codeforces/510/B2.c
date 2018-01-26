#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <ctime>
#include <limits.h>
#include <sstream>
using namespace std;

//clock_t bt = clock();
typedef double DB;
typedef long long LL;
typedef stringstream SS;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<(a);i++)
#define FORd(i, a, b) for(int i=b-1;i>=a;i--)
#define F0Rd(i, a) for(int i=a-1;i>=0;i--)
#define SZ(x) (int)(x).size()
#define ALL(x) x.begin(), x.end()
#define PI M_PI
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define H(a, b) (a*100 + b)
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int arMinIdx(int*arr,int n){return min_element(arr,arr+n)-arr;}
int arMaxIdx(int*arr,int n){return max_element(arr,arr+n)-arr;}
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return abs(a*b)/gcd(a,b);}

const int N = 50;

int n, m; 
string s[N+1];
int vis[N+1][N+1];
bool cycle = false;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

void dfs(int x, int y, int px, int py, char c)
{
  if(x<0||x>=n||y<0||y>=m) return;
  if(s[x][y]!=c) return;
  if(vis[x][y]){
    cycle = true; return;
  }
  vis[x][y] = true;
  //cout << x << ',' << y << endl;
  F0R(i, 4){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if (nx==px && ny==py) continue;
    dfs(nx, ny, x, y, c);
  }
}

int main()
{
  cin >> n >> m;
  F0R(i, n) cin >> s[i];
  F0R(x, n) F0R(y, m) if (!vis[x][y]) dfs(x, y, -1, -1, s[x][y]);
  cout << (cycle ? "Yes" : "No");

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
