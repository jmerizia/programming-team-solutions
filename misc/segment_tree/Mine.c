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
#define MP MP
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int GCD(int a,int b){if(b==0)return a;else return GCD(b,a%b);}
int LCM(int a,int b){return abs(a*b)/GCD(a,b);}

const int N = 1e5; // array limit
int n;
int t[2*N];

void init()
{
  for (int i = 0; i < n; i++) cin >> t[i+n];
}

void build()
{
  for (int i = n-1; i > 0; i--)
    t[i] = t[2*i] + t[2*i+1];
}

void modify(int pos, int value)
{
  t[n+pos] = value;
  for (int i = (n+pos)/2; i > 0; i/=2)
    t[i] = t[i<<1] + t[i<<1|1];
}

int main()
{
  cin >> n;
  init(); build();
  //modify(0, 100);

  for (int i = 1; i < 2*n; i++){
    cout << t[i] << ' ';
  }

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
