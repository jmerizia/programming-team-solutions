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
#define all(x) x.begin(), x.end()
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

int mp[1001][1001], r, c, n;
set<PII> vis;
PII dirs[] = {PII (-1, 0), PII (1, 0), PII (0, -1), PII (0, 1)};

// walk a to b
bool same_region(PII a, PII b)
{
  if(a==b)return 1;
  for(PII dir: dirs){
    PII nw = make_pair(a.F - dir.F, a.S - dir.S);
    if(nw.F >= 1 && nw.S >= 1 && nw.F <= r && nw.S <= c){
      if(!vis.count(nw)){
        vis.insert(nw);
        if(same_region(nw, b)) return 1;
      }
    }
  }
  return 0;
}

int main()
{
  cin >> r >> c;
  string ln;
  F0R(i, r){
    cin >> ln;
    F0R(j, c) mp[i+1][j+1] = ln[j] - 48;
  }
  cin >> n;
  F0R(i, n) {
    int ar[4];
    cin >> ar[0] >> ar[1] >> ar[2] >> ar[3];
    PII a (ar[0], ar[1]); PII b (ar[2], ar[3]);
    if (mp[a.F][a.S] != mp[b.F][b.S]) cout << "neither";
    else if (same_region(a, b)) {
      cout << (mp[a.F][a.S] == 0 ? "binary" : "decimal");
    }
  }
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
