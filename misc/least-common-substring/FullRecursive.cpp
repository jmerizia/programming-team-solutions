#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

string x;
string y;

string lcs(int i, int j)
{
  if (i == -1 || j == -1) return "";
  if (x[i] == y[j]) return lcs(i-1, j-1) + x[i];
  if (x[i] != y[j]){
    string left = lcs(i, j-1);
    string right = lcs(i-1, j);
    return (left.length() > right.length()) ? left : right;
  }
}

int main()
{
  cin >> x >> y;
  cout << lcs(x.length(), y.length());
  return 0;
}
