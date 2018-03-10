// unfinished
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <ctime>
#include <limits.h>
#include <sstream>
using namespace std;

typedef double DB;
typedef long long LL;
typedef stringstream SS;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<(a);i++)
#define FORd(i, a, b) for(int i=b-1;i>=a;i--)
#define F0Rd(i, a) for(int i=a-1;i>=0;i--)
#define SZ(x) (int)(x).size()
#define ALL(x) x.begin(), x.end()
#define PI M_PI
#define F first
#define S second
#define PB push_back
#define MP make_pair
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int GCD(int a,int b){if(b==0)return a;else return GCD(b,a%b);}
int LCM(int a,int b){return abs(a*b)/GCD(a,b);}

int n, m, k;
int ar[501][501], mn[501][501];

int main()
{
  cin >> n >> m >> k;
  F0R(i, n) {
    string day;
    cin >> day;
    F0R(j, m) ar[i][j] = day[j] - '0';
  }

  F0R(i, n) { // for every day
    cout << "-----" << endl;
    F0R(j, m + 1) { // for every possible number of classes to attend
      // find minimal hours
      int h = INT_MAX;
      int l = 0, r = 0;
      F0R(jj, j) {
        while (r < m && ar[r] == 0) r++;
        r++;
      }
      while (l < m && ar[l] == 0) l++;
      cout << "j: " << j << " l: " << l << " r: " << r << endl;
      while (r < m) {
        h = min(h, r - l + 1);
        r++;
        l++;
        while (r < m && ar[r] == 0) r++;
        while (l < m && ar[l] == 0) l++;
      }
      mn[i][j] = h;
    }
  }

  F0R(i, n) {
    F0R(j, m+1) cout << mn[i][j];
    cout << endl;
  }


  return 0;
}
