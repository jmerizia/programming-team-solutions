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

const int MAXN = 101;

VI adj[MAXN];
set<int> all_nodes;
set<int> children;
int target;

bool dfs(int cur, VI path) {
  path.PB(cur); // add to path
  if(cur == target) return true; // found
  if(SZ(adj[cur]) == 0) return false; // leaf
  // check each child
  F0R(i, SZ(adj[cur])){
    VI pathc (path);
    if(dfs(adj[cur][i], pathc)){
      pathc.PB(target);
      F0Rd(j, SZ(pathc)) cout << pathc[j] << " ";
    }
  };
  return false;
}

int init() {
  cin >> target;
  string ln;
  // why no loop value :(
  while(getline(cin, ln)){
    if (ln == "-1") break;
    SS ss (ln); string wd; VI vec;
    while(getline(ss, wd, ' ')) vec.PB(stoi(wd));
    FOR(i, 1, SZ(vec)){
      adj[vec[0]].PB(vec[i]);
      all_nodes.insert(vec[i]);
      children.insert(vec[i]);
    }
    if(SZ(vec)>1) all_nodes.insert(vec[0]);
  }
}

int main()
{
  init();
  VI path;
  set<int> result;
  set_difference(all(all_nodes), all(children), inserter(result, result.end()));
  dfs(*result.begin(), path);
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
