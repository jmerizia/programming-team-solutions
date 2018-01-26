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

int t;
string A = "qwertyuiop";
string B = "asdfghjkl";
string C = "zxcvbnm";

PII location(char c)
{
  int l1 = A.find(c);
  if (l1!=string::npos) return make_pair(0,l1);

  int l2 = B.find(c);
  if (l2!=string::npos) return make_pair(1,l2);

  int l3 = C.find(c);
  if (l3!=-1) return make_pair(2,l3);
}

int dist(char c, char cc)
{
  PII a = location(c);
  PII b = location(cc);
  return abs(a.F-b.F) + abs(a.S-b.S);
}

int main()
{
  cin >> t;
  F0R(i, t){
    int n;
    string w; cin >> w >> n;
    vector<pair<int, string>> prs;
    F0R(j, n){
      string ww; cin >> ww;
      int d = 0;
      F0R(k, w.length()){
        if (w[k]!=ww[k]){
          d += dist(w[k], ww[k]);
        }
      }
      prs.PB(make_pair(d, ww));
    }
    sort(ALL(prs));
    F0R(i, SZ(prs)) cout << prs[i].S << ' ' << prs[i].F << endl;
  }

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
