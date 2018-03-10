#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; i++)

const int MAXN = 501;

const double rt2 = sqrt(2.0);

int n, m;

pair<int, int> boxes[MAXN], circles[MAXN];

int main()
{
  cin >> n >> m;
  FOR(i, 0, n) cin >> boxes[i].first;
  FOR(i, 0, n) cin >> boxes[i].second; 
  FOR(i, 0, m) cin >> circles[i].first; 
  FOR(i, 0, m) cin >> circles[i].second; 

  sort(boxes, boxes+n);
  sort(circles, circles+m);

  int total = 0;
  FOR(i, 0, n) {
    for (int j = 0; j < m; j++) {

      // check if box i fits in circle j, if not skip this circle
      if (boxes[i].first*rt2 > circles[j].first*2.0) continue;

      // maximally decrement box and circle copies
      int mn = min(boxes[i].second, circles[j].second);
      boxes[i].second -= mn;
      circles[j].second -= mn;
      total += mn;

      // if no more boxes, break
      if (boxes[i].second == 0) break;

    }
  }

  cout << total;

  return 0;
}
