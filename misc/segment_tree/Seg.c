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

int build()
{
  for(int i = n-1; i>0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

int modify(int p, int value)
{
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>2]= t[p] + t[p^1];
}

int query(int l, int r)
{
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}


int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i+n];
  build();


  for (int i = 1; i < 2*n; i++){
    cout << t[i] << ' ';
  }
  return 0;
  modify(0, 10);
  cout << query(0, 3);
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
