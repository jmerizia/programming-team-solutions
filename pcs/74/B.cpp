#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, ar[105][105], dp[105][105];

int total(int i, int j, int ii, int jj)
{
  return dp[ii][jj]
    - (j>0?dp[ii][j-1]:0)
    - (i>0?dp[i-1][jj]:0)
    + (i>0&&j>0?dp[i-1][j-1]:0);
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> ar[i][j];

  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
      dp[i][j] = (i>0?dp[i-1][j]:0)
        + (j>0?dp[i][j-1]:0)
        - (i>0&&i>0?dp[i-1][j-1]:0)
        + ar[i][j];

//  for (int i = 0; i < n; i++) {
//    for (int j = 0; j < n; j++)
//      cout << dp[i][j] << ' ';
//    cout << endl;
//  }


  int mx = INT_MIN;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int ii = i; ii < n; ii++)
        for (int jj = j; jj < n; jj++)
          mx = max(mx, total(i, j, ii, jj));

  cout << mx;

  return 0;
}
