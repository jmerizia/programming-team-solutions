#include <iostream>
#include <string>
#include <math.h>
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

int main()
{
  int n;
  cin >> n;
  int dp[n+1][n+1] = {};
  dp[0][0] = 1;
  FOR(i, 0, n) {
    char com;
    cin >> com;
    if (com == 'f') {
      dp[i+1][0] = 0;
      FOR(j, 1, n) dp[i+1][j] = dp[i][j-1];
    } else {
      int sum = 0;
      FORd(j, 0, n) {
        sum = (sum+dp[i][j]) % MOD;
        dp[i+1][j] = sum;
      }
    }
  }
  int sum = 0;
  FOR(j, 0, n) sum = (sum+dp[n - 1][j]) % MOD;
  cout << sum;
  return 0;
}
