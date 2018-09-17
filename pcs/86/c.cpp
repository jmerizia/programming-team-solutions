#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> tiii;

int n;
tiii stones[1001], sorted_a[1001], sorted_b[1001];

int solve(int cur, int target)
{
  if (cur == target) return 0;
  int cost = 1e8;
  // for each stone s.t. cur == a or cur == b
  //    update cur and call solve
  int i = lower_bound(sorted_a, sorted_a + n, cur);
  int j = 0; //lower_bound(sorted_b, sorted_b + n, cur, [](tiii a, tiii b)->bool{return a.second < b.second;});
  printf("%d %d\n", i, j);
}

int main()
{
  while (1) {
    cin >> n;
    if (n == 0) break;
    for (int i = 0; i < n; i++) {
      int a, b, h; cin >> a >> b >> h;
      tiii stone (a, b, h);
      stones[i] = stone; // mem?
      sorted_a[i] = stone;
      sorted_b[i] = stone;
    }
    int porch, gazebo;
    cin >> porch >> gazebo;
    sort(sorted_a, sorted_a+n);
    //sort(sorted_b, sorted_b+n, [](tiii a, tiii b)->bool{ return a.second < b.second; })
    cout << solve(porch, gazebo) << endl;
  }
  return 0;
}
