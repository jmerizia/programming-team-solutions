#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <set>
#include <vector>

using namespace std;

#define f first
#define s second

typedef long long ll;
typedef pair<int, pair<int, int> > piii;

set<piii> combs;
set<piii> mem;
int n;

piii copy(piii cur)
{
  return {cur.f, {cur.s.f, cur.s.s}};
}

int calc(piii cur)
{
    return cur.f*7 + cur.s.f*3 + cur.s.s*2;
}

void solve(piii cur)
{
  if (mem.count(cur)) return;
  int sc = calc(cur);
  if (sc == n) {
    combs.insert(copy(cur));
  }
  else if (sc < n) {
    solve(make_pair(cur.f+1, make_pair(cur.s.f, cur.s.s)));
    solve(make_pair(cur.f, make_pair(cur.s.f+1, cur.s.s)));
    solve(make_pair(cur.f, make_pair(cur.s.f, cur.s.s+1)));
  }
  mem.insert(copy(cur));
}

int main() {
    cin >> n;
    piii cur = {0, {0, 0}};
    solve(cur);
    for (auto k : combs) {
        printf("%d %d %d\n", k.f, k.s.f, k.s.s);
    }
    return 0;
}
