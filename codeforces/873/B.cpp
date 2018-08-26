#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int ans, n, k, dp[N];
string s;

int main()
{
  cin >> n;
  cin >> s;
  for (int i = 0; i < n+1; i++) dp[i] = -1;
  for (int i = 0; i < n; i++) {
    if (s[i]=='1') k++;
    else k--;
    if (dp[k] > -1) ans = max(ans, i-dp[k]);
    else dp[k] = i;
  }
  cout << ans;

  return 0;
}
