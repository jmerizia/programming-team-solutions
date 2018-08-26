#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int n, T;
vector<int> a, b, c;

int main()
{
  cin >> T;
  for (int t= 0; t < T; t++) {
    cin >> n;
    int k;
    for (int i = 0; i < n; i++) {
      cin >> k;
      if (i&1) b.push_back(k);
      else a.push_back(k);
    }
    if (n&1) b.push_back(INT_MAX);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) {
      c.push_back(a[i]);
      c.push_back(b[i]);
    }
    bool failed = false;
    printf("Case #%d: ", t+1);
    for (int i = 0; i < c.size()-1; i++) {
      if (c[i] > c[i+1]) {
        cout << i;
        failed = true;
        break;
      }
    }
    if (!failed) cout << "OK";
    cout << endl;
    a.clear();
    b.clear();
    c.clear();
  }
  return 0;
}
