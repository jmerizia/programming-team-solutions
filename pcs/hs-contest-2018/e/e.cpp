#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
ll dp[101][101], MOD = 1000000009;

ll solve(int a, int b)
{
  if (a < 0 || b < 0) return 0;
  if (a == 0 && b == 0) return 1;
  if (dp[a][b] != -1) return dp[a][b];
  ll ans = 0;
  ans += solve(a - 2, b) + solve(a, b - 2); // safety
  ans += solve(a - 3, b) + solve(a, b - 3); // field goal
  ans += solve(a - 6, b) + solve(a, b - 6); // touchdown
  ans += solve(a - 7, b) + solve(a, b - 7); // touchdown + 1
  ans += solve(a - 8, b) + solve(a, b - 8); // touchdown + 2
  ans += solve(a - 6, b - 1) + solve(a - 1, b - 6); // other team gets 1pt
  ans += solve(a - 6, b - 2) + solve(a - 2, b - 6); // other team gets 2pts
  ans %= MOD;
  dp[a][b] = ans;
  //printf("%d %d %lld\n", a, b, ans);
  return ans;
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i <= n+1; i++) {
    for (int j = 0; j <= m+1; j++) {
      dp[i][j] = -1;
    }
  }
  printf("%d\n", solve(n, m));
}
