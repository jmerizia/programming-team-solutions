#include <bits/stdc++.h>
using namespace std;

int n1, n2, m;
int t1[1005], t2[1005];

int main()
{
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n1 >> n2 >> m;
  for (int i = 0; i < n1; i++) t1[i] = -1;
  for (int i = 0; i < n2; i++) t2[i] = -1;

  for (int i = 0; i < m; i++) {
    int x, y, k;
    cin >> x;
    while (1) {
      // try t1
        // worked: place
        // failed: swap
          // try t2
            // worked: place
            // failed: swap, repeat
      if (t1[x % n1] == -1) {
        t1[x % n1] = x;
        printf("placed %d at %d in 1\n", x, x % n1);
        break;
      }
      y = t1[x % n1];
      t1[x % n1] = x;
      if (t2[y % n2] == -1) {
        t2[y % n2] = y;
        printf("placed %d at %d in 1\n", y, y % n1);
        break;
      }
      x = t2[y % n2];
      t2[y % n2] = x;
    }
  }

  return 0;
}
