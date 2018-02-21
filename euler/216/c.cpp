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

clock_t bt = clock();
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

const int N = 8e6;

int siv[N+1];
VI pri;
//int freq[30];
//int prime_appearance[N+1];

void init()
{
  FOR(i, 1, N+1) siv[i] = i;
  //int iter = 0;
  FOR(i, 2, N+1) if (siv[i]){
    //iter++;
    //if (iter%1000==0) cout << "current: " << i << endl;
    //for(int j = i+1; j < N+1; j++)
    //  if (j % i == 0) siv[j] = 0;
    for (int j = 2*i; j < N+1; j+=i) siv[j] = 0;
  }
  FOR(i, 1, N+1) if (siv[i]) pri.PB(i);
}


int main()
{
  init();
  cout << "done creating sieve." << endl;
  cout << "primes found: " << SZ(pri)-1 << endl;
  cout << "largest prime: " << pri[SZ(pri)-1] << endl;
  
  int n = 1e4;
  int tot = n-2;
  FOR(i, 2, n){
    if (i%10000==0) cout << "i: " << i << endl;
    LL k = 2l*i*i-1;
    //cout << k << endl;
    for(int i=1; i*i<=k; i++ ) if (k%pri[i]==0){
      //cout << " divis by " <<  pri[i] << endl;
      tot--;
      break;
    }
  }
  cout << tot;
  return 0;
  //int sm = 0;
  //F0R(i, 30) sm+=freq[i];
  //cout << sm << endl;
  //F0R(i, 30) cout << freq[i] << ' ';
  //sort(prime_appearance, prime_appearance + N+1);
  //for (int i = N; i > N-100; i--) cout << prime_appearance[i] << ' ';
  //cout << endl;


  clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}
