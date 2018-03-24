#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int a, b, n;
vector<double> ar;

int main()
{
  // v = d/t; d/v = t
  cin >> a >> b >> n;

  for (int i = 0; i < n; i++) {
    int x, y, v;
    cin >> x >> y >> v;
    double d = (double)pow((a-x)*(a-x) + (b-y)*(b-y), 0.5);
    double t = d / (double)v;
    ar.push_back(t);
  }
  sort(ar.begin(), ar.end());
  printf("%0.10f", ar[0]);

  return 0;
}
