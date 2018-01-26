#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef double db;
typedef long long ll;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<(a);i++)
#define FORd(i, a, b) for(int i=b-1;i>=a;i++)
#define F0Rd(i, a) for(int i=a-1;i>=0;i++)
#define sz(x) (int)(x).size()
#define PI M_PI

const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;

int main()
{
  string a, b;
  cin >> a >> b;
  string x;
  F0R(i, 21) x += 'z';
  F0R(i, sz(a)) F0R(j, sz(b)) x = min(x, a.substr(0, i+1) + b.substr(0, j+1));
  cout << x << '\n';
  return 0;
}
