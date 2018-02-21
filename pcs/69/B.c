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

int e, q;
map<string, vector<string>> adj;

int bfs(string start)
{
  set<string> vis;
  queue<string> Q;
  Q.push(start);
  vis.insert(start);
  while (SZ(Q)) {
    string nxt = Q.front();
    Q.pop();
    for (string k: adj[nxt]) {
      if (!vis.count(nxt)) Q.push(k);
    }
  }
}

int main()
{
  cin >> e >> q;
  F0R(i, e) {
    string a, b;
    cin >> a >> b;
    vector<string> ve;
    if (!adj.count(a)) adj.insert(MP(a, ve));
    if (!adj.count(b)) adj.insert(MP(a, ve));
    adj[a].PB(b);
    adj[b].PB(a);
  }
  F0R(i, q) {
    string a; cin >> a;

  }

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
