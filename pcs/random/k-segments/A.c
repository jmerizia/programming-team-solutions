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

int n, k;
VI e, s;

int main()
{

  cin >> n >> k;
  F0R(i, n){
    int a, b;
    cin >> a; s.PB(a);
    cin >> b; e.PB(b);
  }

  sort(ALL(s));
  sort(ALL(e));

  int a = 0, b = 0, open = 0, total = 0;
  SS ss;
  while(1){
    
    if (a == n && b == n) {
      break;
    } else if (a == n) {
      b++;
    } else if (b == n) {
      a++;
    } else if (s[a] < e[b]) {
      a++;
    } else if (e[b] < s[a]) {
      b++;
    } else {
      // special case:
      if (a - b + 1 >= k && !open) {
        ss << s[a] << ' ' << e[b] << endl;
        total++;
      }
      a++; b++;
    }

    //cout << a << ' ' << b << ' ' << a - b << endl;
    if (a - b >= k && !open){
      //cout << "open: " << s[a - 1] << endl;
      open = 1;
      ss << s[a - 1] << ' ';
    }
    else if (a - b < k && open){
      //cout << "close: " << e[b - 1] << endl;
      open = 0;
      ss << e[b - 1] << endl;
      total++;
    }

  }
  cout << total << endl << ss.str();

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
