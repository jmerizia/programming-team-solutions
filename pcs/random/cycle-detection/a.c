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

const int MAXN = 50000;

VI adj[MAXN + 1], starts;
set<int> vert;
set<int> vis;
int m, n, a, b;

bool has_cycle(int start, int prev)
{
  for(int vv: adj[start]){
    if(vv==prev)continue;
    // if vv visited, then cycle
    if(vis.count(vv)) return 1;
    else vis.insert(vv);
    // if vv child cycle, then cycle
    if(has_cycle(vv, start)) return 1;
  }
  return 0;
}

void remove_connected(int start)
{
  for(int vv: adj[start]){
    if(vert.count(vv)){
      vert.erase(vert.find(vv));
      remove_connected(vv);
    }
  }
}

int main()
{
  cin >> n >> m;
  F0R(i, m){
    cin >> a >> b;
    vert.insert(a);
    vert.insert(b);
    adj[a].PB(b);
    adj[b].PB(a);
  }
  while(SZ(vert)>0){
    starts.PB(*vert.begin());
    remove_connected(*vert.begin());
  }
  for(int start: starts){
    if(has_cycle(start, -1)){
      cout << "bad"; return 0;
    }
  }
  cout << "good";
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
