#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

set<piii> all;
set<piii> ans;
int b, c, d, l;

void solve(int i, int j, int k)
{
  piii m = {i, {j, k}};
  if (all.find(m) != all.end()) return;
  int tot = i*b+j*c+k*d;
  all.insert(m);
  if (tot > l) return;
  if (tot == l) {
    ans.insert(m);
    return;
  }
  solve(i+1, j, k);
  solve(i, j+1, k);
  solve(i, j, k+1);
}

int main()
{
  cin >> b >> c >> d >> l;
  solve(0, 0, 0);
  for (auto it = ans.begin(); it != ans.end(); it++) {
    piii k = *it;
    printf("%d %d %d\n", k.first, k.second.first, k.second.second);
  }
  if (ans.size() == 0) {
    printf("impossible");
  }
}
