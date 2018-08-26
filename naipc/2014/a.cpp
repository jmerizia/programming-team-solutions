#include <bits/stdc++.h>
using namespace std;

typedef double db;
typedef pair<double, double> pdd;

const db INF = 1e6;

#define f first
#define s second

int n = -1;
db x, ve;
vector<pdd> cars;

db unim(db t)
{
  db mn = INF, mx = -INF;
  for (pdd car : cars) {
    db val = car.f + t*car.s;
    mn = min(mn, val);
    mx = max(mx, val);
  }
  return mx - mn;
}

db ts()
{
  db l=0, r=INF, t1, t2;
  for (int i = 0; i < 50; i++) {
    db dist = (r-l)/3;
    db m1 = l+dist, m2 = r-dist;
    t1 = unim(m1);
    t2 = unim(m2);
    if (t1 < t2) {
      r = m2;
    } else {
      l = m1;
    }
  }
  return t1;
}

int main()
{
  while (true) {
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i++) {
      cin >> x >> ve;
      cars.push_back({x, ve});
    }
    printf("%.2f\n", ts());
    cars.clear();
  }
  return 0;
}
