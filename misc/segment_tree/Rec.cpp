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

const int N = 1e5;
int t[N*4];

void build(int pos, int left, int right)
{
  if (left==right) {
    cin >> t[pos];
    return;
  }
  int mid = (left+right)/2;
  build(pos*2, left, mid);
  build(pos*2+1, mid+1, right);
  t[pos] = t[pos*2+1] + t[pos*2];
}

void modify(int pos, int left, int right, int x, int value)
{
  if (left==right) {
    t[pos]=y;
    return;
  }
  int mid=(left+right)/2;
  if (target<=mid) modify(pos*2, left, mid, x, value);
  else modify(pos*2+1, mid+1, right, x, value);
  t[pos] = t[pos*2+1] + t[pos*2];
}

int query(int pos, int left, int right)
{
  if (left<pos*2) {
    return t[pos];
  }
}

int main()
{

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
