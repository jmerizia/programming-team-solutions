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

const int N = 1e5+5;
int n, ar[N];

int main()
{
  cin >> n;
  F0R(i, n) cin >> ar[i];
  sort(ar, ar+n);
  int w = 0;
  F0R(i, n-2) if (ar[i] + ar[i+1] > ar[i+2]) {
    w++;
    break;
  }
  cout << (w ? "YES" : "NO");

  return 0;
}
