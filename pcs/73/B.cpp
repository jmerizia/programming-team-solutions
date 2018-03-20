#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

string s;

int main()
{
  cin >> s;
  int k = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') k++;
    else k--;

    if (k < 0) {
      cout << "Unbalanced";
      return 0;
    }
  }
  if (k != 0) cout << "Unbalanced";
  else cout << "Balanced";
  return 0;
}
