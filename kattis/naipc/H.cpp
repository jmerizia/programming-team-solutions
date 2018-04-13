#include <bits/stdc++.h>
using namespace std;

#define FORD(i, a, b) for (int i = b-1; i >= a; i--)
#define FOR(i, a, b) for (int i = a; i < b; i++)

const int N = 50;
int n, m, row[N], col[N], ans[N][N];
string a, b;

int main()
{
  cin >> a >> b;
  n = a.length();
  m = b.length();
  FOR(i, 0, n) row[i] = a[i] - '0';
  FOR(i, 0, m) col[i] = b[i] - '0';

  FOR(i, 0, n) FOR(j, 0, m) {
    if (row[i] ^ col[j]) ans[i][j] = 1;
    else ans[i][j] = -1000;
  }

  FORD(i, 0, n) {
    FORD(j, 0, m) {
      if (ans[i][j] != 1) {

        ans[i][j] = 1;
        int r = 0, c = 0;
        FOR(ii, 0, n) r+=ans[ii][j];
        FOR(jj, 0, m) c+=ans[i][jj];
        if (r >= 0 && c >= 0) {
          if (col[i] != c%2 || row[j] != r%2) {
            printf("can't add. i=%d j=%d \n", i, j);
            ans[i][j] = 0; 
          }
        }

      }
    }
  }

  FOR(i, 0, n) {
    FOR(j, 0, m) cout << ans[i][j];
    cout << endl;
  }

}
