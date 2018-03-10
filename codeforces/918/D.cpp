// unfinished
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
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
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int GCD(int a,int b){if(b==0)return a;else return GCD(b,a%b);}
int LCM(int a,int b){return abs(a*b)/GCD(a,b);}

const int N = 101;
int n, m;
int dp[N];
VI adj[N];
char weight[N][N];
int vis[N];

int dfs(int u, int len, int prev)
{
  //if (dp[u] > -1) return dp[u] + len;
  vis[u] = 1;
  int mx = len;
  for (int v: adj[u]) {
    if (!vis[v]) {
      if (weight[u][v] >= weight[prev][u]) {
        mx = max(mx, dfs(v, len+1, u));
      }
    }
  }
  return mx;
}

int dfs(int start) {
  FOR(i, 1, n+1) vis[i] = 0;
  return dfs(start, 0, 0);
}

int main()
{
  F0R(i, N) dp[i] = -1;
  cin >> n >> m;
  F0R(i, m){
    int u, v;
    char c;
    cin >> u >> v >> c;
    adj[u].PB(v);
    weight[u][v] = c;
  }
  FOR(i, 1, n+1) dp[i] = dfs(i);
  FOR(i, 1, n+1) cout << dp[i] << ' ';
  cout << endl;
  FOR(i, 1, n+1) {
    FOR(j, 1, n+1) {
      cout << (dp[i] > dp[j] ? 'A' : 'B');
    }
    cout << endl;
  }


  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
