#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef double db;
typedef long long ll;
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

int main()
{
  int ar[3];
  cin >> ar[0] >> ar[1] >> ar[2];
  if(count(ar, ar+3, 1)>0) cout << "YES";
  else if(count(ar, ar+3, 2)>1) cout << "YES";
  else if(count(ar, ar+3, 3)>2) cout << "YES";
  else if(count(ar, ar+3, 2)==1
      && count(ar, ar+3, 4)==2) cout << "YES";
  else cout << "NO";
  return 0;
}
