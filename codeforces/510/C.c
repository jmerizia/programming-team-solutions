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
const int MOD = (int) pow(10, 9) + 7;
const int ERR = 1e-5;
int arMinIdx(int*arr,int n){return min_element(arr,arr+n)-arr;}
int arMaxIdx(int*arr,int n){return max_element(arr,arr+n)-arr;}
int gcd(int a,int b){if(b==0)return a;else return gcd(b,a%b);}
int lcm(int a,int b){return abs(a*b)/gcd(a,b);}

const int N = 26;

int n;
string names[101];
VI adj[N+1];
int in[N+1];
VI v;

bool kahn()
{
  queue<int> todo;
  FOR(i, 1, N+1) in[i] = 0;
  FOR(i, 1, N+1) for (int j: adj[i]) in[j]++;
  FOR(i, 1, N+1) if (in[i] == 0) todo.push(i);

  while(SZ(todo)){
    int n = todo.front(); todo.pop();
    v.PB(n);
    for(int m: adj[n]){
      in[m]--;
      if (!in[m]) todo.push(m);
    }
  }

  FOR(i, 1, 27) if (in[i] > 0) return false;
  return true;
}

int charId(char c)
{
  if (c == ' ') return 0;
  return c - 'a' + 1;
}

int main()
{
  cin >> n;
  F0R(i, n) cin >> names[i];
  F0R(i, n) names[i] += " ";

  bool failed = 1;
  F0R(i, n-1){
    int j = 0;
    while(names[i][j] == names[i+1][j]) j++;
    if (names[i+1][j] == ' '){
      cout << "Impossible";
      return 0;
    }
    adj[charId(names[i][j])].PB(charId(names[i+1][j]));
  }

  if(!kahn()){
    cout << "Impossible";
  } else {
    F0R(i, SZ(v)) if(v[i]!=0) cout << char(v[i] + 'a' - 1);
  }

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
