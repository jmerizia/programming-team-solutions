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

const int N = 5e5+10; // array limit
int n;
int t[2*N];

int build()
{
  for(int i = n-1; i>0; --i) t[i] = gcd(t[i<<1], t[i<<1|1]);
}

int modify(int p, int value)
{
  for (t[p += n] = value; p > 1; p >>= 1)
    t[p>>1]= gcd(t[p], t[p^1]);
}

int query(int l, int r)
{
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = gcd(res, t[l++]);
    if (r&1) res = gcd(res, t[--r]);
  }
  return res;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) cin >> t[i+n];
  build();
  int q;
  cin >> q;
  //SS ss;
  F0R(i, q) {
    //ss << "array is [";
    //F0R(kk, n) ss << query(kk, kk+1) << ' ';
    //ss << "]" << endl;
    int type; cin >> type;
    if (type==2){
      int ii, y; cin >> ii >> y;
      modify(ii-1, y);
      //ss << "MODIFIED(";
      //F0R(kk, n) ss << query(kk, kk+1) << ' ';
      //ss << ")" << endl;
    } else {
      int l, r, x; cin >> l >> r >> x;
      l--;
      //if (r-l==1) cout << "YES(short range)" << endl;
      if (r-l==1) cout << "YES" << endl;
      else {
        int d = query(l, r);
        //if (d==x) cout << "YES(equal)" << endl;
        if (d==x) cout << "YES" << endl;
        //else if (x==1) cout << "YES(prime)" << endl; // can add prime
        else if (x==1) cout << "YES" << endl; // can add prime
        else {
          // iterate through range replacing each
          // number with x, and check range gcd
          bool worked = false;
          for (int j = l; j < r; j++){
            int tmp = query(j, j+1);
            modify(j, x);
            if (query(l, r)==x){
              modify(j, tmp); // put original back
              worked = true;
              //cout << "YES(replacement of " << tmp << ")" << endl; break;
              cout << "YES" << endl; break;
            }
            modify(j, tmp); // put original back
          }
          if (!worked){
            cout << "NO" << endl;
          }
        }
      }
    }
  }
  //cout << ss.str();
  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
