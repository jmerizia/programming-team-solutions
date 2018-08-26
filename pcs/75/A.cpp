#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 1e6 + 1;

int n, k, s[N], e[N];
vector<pair<int, int>> ans;

int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    cin >> e[i];
  }

  sort(s, s + n);
  sort(e, e + n);

  int i = 0, j = 0, c = 0;
  bool open = false;
  while (i < n && j < n) {

    cout << "it " << i << ' ' << j << ' ' << c << endl;

    if (s[i] < e[j]) {
      c++;
      i++;
    }
    else if (s[i] > e[j]) {
      c--;
      j++;
    }
    else {
      ans.push_back(make_pair(s[i], e[j]));
      i++;
      j++;
    }

    if (c == k) {
      if (open) {
        ans[ans.size()-1].second = e[j];
        open = false;
      } else {
        ans.push_back(make_pair(s[i], -1));
        open = true;
      }
    }

  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }

  return 0;
}
