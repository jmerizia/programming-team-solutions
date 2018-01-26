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
typedef double db;
typedef long long ll;
typedef stringstream SS;
typedef pair<int, int> pii;
#define FOR(i, a, b) for(int i=a;i<b;i++)
#define F0R(i, a) for(int i=0;i<(a);i++)
#define FORd(i, a, b) for(int i=b-1;i>=a;i--)
#define F0Rd(i, a) for(int i=a-1;i>=0;i--)
#define sz(x) (int)(x).size()
#define PI M_PI
#define f first
#define s second
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int arMinIdx(int*arr,int n){return min_element(arr,arr+n)-arr;}
int arMaxIdx(int*arr,int n){return max_element(arr,arr+n)-arr;}
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return abs(a*b)/gcd(a,b);}

int n, k;
vector<pii> vt;

int main()
{
  cin >> n >> k;
  int pre[k];
  F0R(i, k) cin >> pre[i];
  pii rn (1, n);
  vt.push_back(rn);
  for(int j: pre) if(vt.back().f <= j && j <= vt.back().s) {
    int a, b; a = vt.back().f; b = vt.back().s;
    pii new1 (a, j - 1);
    pii new2 (j + 1, b);
    vt.pop_back();
    if (b != j) vt.push_back(new2);
    if (a != j) vt.push_back(new1);
  } else cout << "-1"; return 0;
  F0R(i, k) cout << pre[i] << " ";
  F0Rd(i, sz(vt)) {
    pii pr = vt[i];
    FORd(j, pr.f, pr.s+1) cout << j << " ";
  };
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
