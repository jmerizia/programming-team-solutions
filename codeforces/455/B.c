#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef double db;
typedef long long ll;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<(a);i++)
#define FORD(i, a, b) for(int i=b-1;i>=a;i--)
#define F0RD(i, a) for(int i=a-1;i>=0;i--)
#define sz(x) (int)(x).size()
#define PI M_PI

const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;

int main()
{
  int n;
  cin >> n;
  int f = n / 2;
  int sum = f * (f + 1);
  sum += (n % 2) * ceil(n/2.0);
  cout << sum;
  return 0;
}
