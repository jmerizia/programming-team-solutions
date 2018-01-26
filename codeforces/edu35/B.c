#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
typedef double db;
typedef long long ll;
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<(a);i++)
#define FORd(i, a, b) for(int i=b-1;i>=a;i--)
#define F0Rd(i, a) for(int i=a-1;i>=0;i--)
#define sz(x) (int)(x).size()
#define PI M_PI
#define print2d(arr) \
  F0R(i, n) { \
    F0R(j, n) cout << dp[i][j] << " "; \
    cout << endl; }
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int arMinIdx(int*arr,int n){return min_element(arr,arr+n)-arr;}
int arMaxIdx(int*arr,int n){return max_element(arr,arr+n)-arr;}

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  int mx = -1;
  FOR(i, 1, n) {
    int j = n - i;
    int mn = min(a / i, b / j);
    mx = max(mx, mn);
  }
  cout << mx;
  return 0;
}
