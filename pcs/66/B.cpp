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
#define MP make_pair
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int GCD(int a,int b){if(b==0)return a;else return GCD(b,a%b);}
int LCM(int a,int b){return abs(a*b)/GCD(a,b);}

int n;
VI v;
vector<VI> vv;
vector<string> vs;

void solve(VI cur)
{
  if (SZ(cur) == n){
    vv.PB(cur);
    return;
  }
  for (int k: v){
    if (find(ALL(cur), k) != cur.end()) continue;
    cur.PB(k);
    solve(cur);
    cur.pop_back();
  }
}

int main()
{
  cin >> n;
  F0R(i, n){
    int a; cin >> a;
    v.PB(a);
  }
  VI cur;
  solve(cur);

  F0R(i, SZ(vv)) {
    SS ss;
    F0R(j, SZ(vv[0])){
      ss << vv[i][j];
      ss << " ";
    }
    vs.PB(ss.str());
  }
  sort(ALL(vs));

  F0R(i, SZ(vs)) cout << vs[i] << endl;

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
