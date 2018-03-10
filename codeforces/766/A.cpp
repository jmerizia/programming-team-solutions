#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
  string x, y;
  cin >> x >> y;
  if (x == y) cout << -1;
  else cout << max(x.length(), y.length());
  return 0;
}
