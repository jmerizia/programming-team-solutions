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

string st;
int K, ops[1005], ans;

int init()
{
  FOR(i, 1, 10){
    int a = i;
    int op = 0;
    while(a>1){
      op++;

      // add digits
      int x = a;
      int nw = 0;
      while(x>0){
        int l = x%2;
        nw+=l;
        x/=2;
      }

      a=nw;
    }
    ops[i] = op;
  }
}

LL comb(LL n, LL k)
{
  LL a = 1, nn = n, nk = n-k;
  for (;nn > k;nn--)a*=nn;
  for (;nk > 1;nk--)a/=nk;
  return a;
}

int main()
{
  //cin >> st >> K;
  int n, k; cin >> n >> k;
  cout << comb(n, k);
  return 0;
  init();

  int a = 0;
  F0R(i, st.length()){
    if(st[i]=='1'){
      // choose 0
      int n = st.length()-i-1;

      // choose 1
      a++;
    }
  }

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
