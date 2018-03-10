#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

string x;
string y;

int lcs(int i, int j)
{
  if (i == -1 || j == -1) return 0;
  if (x[i] == y[j]) return lcs(i-1, j-1) + 1;
  if (x[i] != y[j]) return max(lcs(i, j-1), lcs(i-1, j));
}

int main()
{
  cin >> x >> y;
  cout << lcs(x.length(), y.length());
  return 0;
}
