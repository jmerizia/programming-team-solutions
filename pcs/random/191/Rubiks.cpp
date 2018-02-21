// ******
// DISCLAIMER
// I know this was going to TLE, don't hate on me ok?
//
// DISCLAIMER x2
// Regarding my previous attempt: I forgot to test on give input
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
typedef vector<char> VC;
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

const int N = 16;
VI to_check;

VC given;
VC solved = {
  'R', 'R', 'R', 'R',
  'G', 'G', 'G', 'G',
  'B', 'B', 'B', 'B',
  'Y', 'Y', 'Y', 'Y'
};

void rotate_col(int col, VC *v, char dir)
{
  char a, b, c, d;
  a = (*v)[col];
  b = (*v)[col+4];
  c = (*v)[col+8];
  d = (*v)[col+12];
  if (dir=='d'){
    (*v)[col] = d;
    (*v)[col+4] = a;
    (*v)[col+8] = b;
    (*v)[col+12] = c;
  } else if (dir=='u') {
    (*v)[col] = b;
    (*v)[col+4] = c;
    (*v)[col+8] = d;
    (*v)[col+12] = a;
  }
}

void rotate_row(int row, VC *v, char dir)
{
  char a, b, c, d;
  a = (*v)[4*row];
  b = (*v)[4*row+1];
  c = (*v)[4*row+2];
  d = (*v)[4*row+3];
  if (dir=='r') {
    (*v)[4*row] = d;
    (*v)[4*row+1] = a;
    (*v)[4*row+2] = b;
    (*v)[4*row+3] = c;
  } else if (dir=='l') {
    (*v)[4*row] = b;
    (*v)[4*row+1] = c;
    (*v)[4*row+2] = d;
    (*v)[4*row+3] = a;
  }
}

LL VCtoLL(VC v)
{
  LL o = 0;
  F0Rd(i, N){
    o *= 10;
    if (v[i]=='R') o += 1;
    if (v[i]=='G') o += 2;
    if (v[i]=='B') o += 3;
    if (v[i]=='Y') o += 4;
  }
  return o;
}

VC LLtoVC(LL o)
{
  VC v;
  while (o > 0){
    v.PB(o%10);
    o/=10;
  }
  return v;
}

bool check(VC v)
{
  F0R(i, N) if (v[i]!=solved[i]) return false;
  return true;
}

void bfs()
{
  queue<pair<LL, int>> Q;
  set<LL> V;
  LL g = VCtoLL(given);
  Q.push(MP(g, 0));
  V.insert(g);
  while (SZ(Q)) {
    pair<LL, int> k = Q.front(); Q.pop();
    LL v = k.F; int d = k.S;
    VC vc = LLtoVC(v);
    if (check(vc)) {
      cout << d;
      return;
    }

    F0R(row, 4){
      VC vv = vc; // makes a copy. WOW!
      rotate_row(row, &vv, 'r');
      Q.push(MP(VCtoLL(vv), d+1));

      rotate_row(row, &vv, 'l');
      rotate_row(row, &vv, 'l');
      Q.push(MP(VCtoLL(vv), d+1));
    }

    F0R(col, 4){
      VC vv = vc; // makes a copy. WOW!
      rotate_col(col, &vv, 'd');
      Q.push(MP(VCtoLL(vv), d+1));

      rotate_col(col, &vv, 'u');
      rotate_col(col, &vv, 'u');
      Q.push(MP(VCtoLL(vv), d+1));
    }

  }
}

int main()
{
  //F0R(i, 4){
  //  string stt; cin >> stt;
  //  F0R(j, 4) given.PB(stt[j]);
  //}
  given = solved;
  srand(time(0));
  F0R(i, 2){
    int cr = rand()%4;
    int a = rand()%2;
    int dir = rand()%2;
    if (a) {
      rotate_col(cr, &given, dir?'d':'u');
    } else {
      rotate_row(cr, &given, dir?'r':'l');
    }
  }
  F0R(i, 4){
    F0R(j, 4) cout << given[j+4*i] << ' ';
    cout << endl;
  }
  rotate_col(0, &given, 'u');

  bfs();

  F0R(i, 4){
    F0R(j, 4) cout << given[j+4*i] << ' ';
    cout << endl;
  }

  //clock_t et=clock();cout<<double(et-bt)/CLOCKS_PER_SEC;
  return 0;
}

// did you know, v1 = v2 copies the vector????
