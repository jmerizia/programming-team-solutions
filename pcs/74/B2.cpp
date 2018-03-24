#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, ar[105][105], dp[105][105], dpk[105];

int total(int i, int j, int ii, int jj)
{
  return dp[ii][jj]
    - (j>0?dp[ii][j-1]:0)
    - (i>0?dp[i-1][jj]:0)
    + (i>0&&j>0?dp[i-1][j-1]:0);
}

int solve(int l, int r, int y)
{
  if (y == n) return INT_MIN;
  int prefix_sum = total(y, l, y, r);
  return max(prefix_sum, solve(l, r, y+1) + prefix_sum);
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> ar[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      dp[i][j] = (i>0?dp[i-1][j]:0)
        + (j>0?dp[i][j-1]:0)
        - (i>0&&i>0?dp[i-1][j-1]:0)
        + ar[i][j];

  int mx = INT_MIN;
  for (int l = 0; l < n; l++)
    for (int r = l; r < n; r++)
      mx = max(mx, solve(l, r, 0));

  cout << mx;

  return 0;
}
