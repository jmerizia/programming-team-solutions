// F=template && g++ -std=c++1y $F.cpp -o $F.bin && ./$F.bin < 1.in
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
#define c2(x, y, a) x(y(a))
#define c3(x, y, z, a) x(y(z(a)))
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pf printf
#define pb push_back
#define DO(i, a, b) for (int i = (a); i < (b); ++i)
#define DOd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define CONTAINS(set, x) (set.find(x) != set.end())

int n;
vector<tiii> stones, sorted_a, sorted_b;

int bsearch_b(vector<tiii> v, int target)
{
  int l = 0, r = sz(v);
  DO(i, 0, 30) {
    int mid = (l + r) / 2;
    if (get<1>(v[mid]) < target) {
      l = mid;
    } else if (get<1>(v[mid]) > target) {
      r = mid;
    } else {
      return mid;
    }
  }
  return -1;
}

int bsearch_a(vector<tiii> v, int target)
{
  int l = 0, r = sz(v);
  DO(i, 0, 30) {
    int mid = (l + r) / 2;
    if (get<0>(v[mid]) < target) {
      l = mid;
    } else if (get<0>(v[mid]) > target) {
      r = mid;
    } else {
      return mid;
    }
  }
  return -1;
}

int solve(int cur, int target)
{
  if (cur == target) return 0;
  int cost = 1e8;
  // for each stone s.t. cur == a or cur == b
  //    update cur and call solve
  int in_a = bsearch_a(sorted_a, cur);
  int in_b = bsearch_b(sorted_b, cur);
  pf("%d %d\b", in_a, in_b);
  return 0;
}

int main()
{
  while (1) {
    cin >> n;
    if (n == 0) break;
    DO(i, 0, n) {
      int a, b, h; cin >> a >> b >> h;
      tiii stone (a, b, h);
      stones.pb(stone);
    }
    int porch, gazebo;
    sorted_a = stones;
    sorted_b = stones;
    sort(all(sorted_a));
    sort(all(sorted_b), [](tiii a, tiii b)->bool{return get<1>(a) < get<1>(b);});
    cin >> porch >> gazebo;
    cout << solve(porch, gazebo) << endl;
  }
  return 0;
}
