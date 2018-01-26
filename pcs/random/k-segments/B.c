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

const int MAXN = 1e6+1;

int n, k, c, total;
//vector<PII> ev;
//vector<int> ans;
PII ev[MAXN];
int ans[MAXN];

int main()
{
  cin >> n >> k;
  F0R(i, n){
    int a, b;
    cin >> a;
    cin >> b;
    PII st (a, 0);
    PII en (b, 1);
    ev[2*i] = st;
    ev[2*i + 1] = en;
  }

  sort(ev, ev + 2*n);

  F0R(i, 2*n){
    if (!ev[i].S) {
      c++;
      if (c == k) {
        // open
        ans[total] = ev[i].F;
        total++;
      }
    } else {
      if (c == k) {
        // close
        ans[total] = ev[i].F;
        total++;
      }
      c--;
    }
  }

  printf("%d\n", total/2);
  for (int i = 0; i < total; i+=2){
    printf("%d %d\n", ans[i], ans[i+1]);
  }

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
