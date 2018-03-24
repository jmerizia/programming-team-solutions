#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int n, m, a[N];
int main()
{
  cin >> n >> m;
  set<int> st;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    st.insert(a[i]);
  }
  stringstream ans;
  int cur = 1;
  for (int i = 1; i <= m; i++) {
    if (!st.count(cur)) {
      ans << cur;
    } else {
      for (int k = cur; k <= n; k++) {

      }
    }
  }
  cout << ans.str();
}
