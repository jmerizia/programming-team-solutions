#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <list>
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
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int arMinIdx(int*arr,int n){return min_element(arr,arr+n)-arr;}
int arMaxIdx(int*arr,int n){return max_element(arr,arr+n)-arr;}
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return abs(a*b)/gcd(a,b);}

const int MAXN = 30;

int pri[MAXN+1];

int main()
{
  LL n, L;
  cin >> n >> L;
  F0R(i, n) cin >> pri[i];
  cout << LLONG_MAX << endl;
  LL total = 0;
  int runs = 0;
  while (L > 0) {
    runs++; if (runs == 10) break;
    LL mn = LLONG_MAX; LL idx;
    F0R(i, n) {
      LL cost = ceil(L / pow(2, i)) * pri[i];
      if(cost < mn){
        mn = cost; idx = i;
      }
    }
    L -= (1<<idx);
    total += pri[idx];
    cout << L << ' ';
  }
  cout << endl;
  cout << total;
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
