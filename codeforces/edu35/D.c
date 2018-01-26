#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <map>
#include <ctime>
#include <limits.h>
#include <sstream>
using namespace std;

//clock_t bt = clock();
typedef double db;
typedef long long ll;
typedef stringstream SS;
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<(a);i++)
#define FORd(i, a, b) for(int i=b-1;i>=a;i--)
#define F0Rd(i, a) for(int i=a-1;i>=0;i--)
#define sz(x) (int)(x).size()
#define PI M_PI
#define print2d(arr) \
  F0R(i, n) { \
    F0R(j, n) cout << dp[i][j] << " "; \
    cout << endl; }
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int arMinIdx(int*arr,int n){return min_element(arr,arr+n)-arr;}
int arMaxIdx(int*arr,int n){return max_element(arr,arr+n)-arr;}
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return abs(a*b)/gcd(a,b);}

int n, m, a, b, k;
SS ss;

int main()
{
  cin >> n;
  int ar[n]; F0R(i, n) cin >> ar[i];
  F0R(i, n-1) FOR(j, i+1, n) if (ar[i] > ar[j]) k ^= 1;
  cin >> m;
  F0R(i, m) {
    cin >> a >> b;
    int d = b - a + 1;
    d = d*(d-1)/2;
    k = (k+d)%2;
    if (k) ss << "odd" << endl;
    else ss << "even" << endl;
  }
  cout << ss.str();
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
