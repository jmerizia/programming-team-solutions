#include <bits/stdc++.h>
using namespace std;

int T, A, dp[1005][1005], n;
vector<int> choices;
vector<pair<int, int>> prs;

int find_next_x()
{
  int mn = 100;
  int next_x = 2;
  for (int i = 2; i <= n-1; i++) {
    int tot = dp[i-1][1] + dp[i-1][2] + dp[i-1][3] +
              dp[i][1]   + dp[i][2]   + dp[i][3] +
              dp[i+1][1] + dp[i+1][2] + dp[i+1][3];
    if (tot < mn) {
      next_x = i;
      mn = tot;
    }
  }
  return next_x;
}

void clrdp()
{
  for (int i = 0; i < 300; i++) {
    dp[i][1] = 0;
    dp[i][2] = 0;
    dp[i][3] = 0;
  }
}

int main()
{
  cin >> T;
  for (int t = 0; t < T; t++) {
    choices.push_back(0);
    clrdp();
    cin >> A;
    n = (A+3-1)/3;
    int a = 1, b = 1;
    int x;
    while (!(a == 0 && b == 0)) {
      x = find_next_x();
      choices.push_back(x);
      cout << x << " 2" << endl;
      cout.flush();
      cin >> a >> b;
      prs.push_back(make_pair(a, b));
      if (a == -1 || b == -1) return 0;
      if (a != 0 && b != 0) dp[a][b] = 1;
    }

  }

  return 0;
}
