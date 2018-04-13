#include <bits/stdc++.h>
using namespace std;

const int N = 300;
int T, D, n, cur;
string s;

void upd()
{
  int tmp = 1;
  cur = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'S') cur += tmp;
    else tmp <<= 1;
  }
}

int main()
{

  cin >> T;
  for (int i = 0; i < T; i++) {

    cin >> D >> s;
    n = s.length();

    int count = 0;
    bool impossible = false;

    printf("Case #%d: ", i+1);
    upd();

    while (cur > D) {
      int idx = n-1;
      while (idx >= 0 && s[idx] == 'C') idx--;
      while (idx >= 0 && s[idx] == 'S') idx--;
      if (idx == -1) {
        impossible = true;
        break;
      }
      s[idx] = 'S';
      s[idx+1] = 'C';

      upd();
      count++;
    }

    if (impossible) printf("IMPOSSIBLE\n");
    else printf("%d\n", count);
  }

  return 0;
}
