#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <ctime>
#include <limits.h>
#include <sstream>
using namespace std;

//clock_t bt = clock();
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
const int ERR = 1e-6;
int GCD(int a,int b){if(b==0)return a;else return GCD(b,a%b);}
int LCM(int a,int b){return abs(a*b)/GCD(a,b);}

double f(double n)
{
  return n * (log(n)/log(2));
}

double bs(double target)
{
  double left = 0, right = 1e12, mid = 0;
  F0R (i, 100) {
    mid = (left + right)/2;
    double g = f(mid);
    if (abs(g - target) < 1e-7) return mid;
    else if (target > g) left = mid;
    else right = mid;
  }
  return mid;
}

int main()
{
  double a; cin >> a;
  printf("%0.10f", bs(a));

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
