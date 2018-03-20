#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a;
vector<int> v;
LL dp[(int)1e8];

int main()
{
  // lol just giv me a n
  cin >> a;
  string t;
  getline(cin, t);
  getline(cin, t);
  stringstream ss (t);
  LL nxt;
  while (ss >> nxt) v.push_back(nxt);

  sort(v.begin(), v.end());

  dp[0] = v[0];
  for (int i = 1; i < v.size(); i++) dp[i] = dp[i-1]*v[i];
  LL mn = a+1;
  for (int i = 0; i < v.size(); i++) mn = min(mn, dp[i]+a/dp[i]); 
  cout << mn;

  return 0;
}
