// F=template.cpp g++ -std=c++1y $F.cpp -o $F.bin && ./$F.bin < 1.in
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
#define c2(x, y, a) x(y(a))
#define c3(x, y, z, a) x(y(z(a)))
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define pf printf
#define DO(i, a, b, ...) for (int i = (a); i < (b); ++i) {__VA_ARGS__}
#define DOd(i, a, b, ...) for (int i = (b)-1; i >= (a); --i) {__VA_ARGS__}

int x(int a) {return a + 1;}
int y(int a) {return a + 2;}
int z(int a) {return a + 3;}

int main()
{
  // Composability of macros:
  vector<int> ar = {1, 2, 3, 4, 5, 6, 7};
  c2(sort, all, ar); // macro c2 is replaced first

  // just why...
  int sm = 0;
  DO(i, 0, sz(ar), sm += ar[i]; pf("%d\n", sm););
  pf("sum = %d\n", sm);

  int a = 0, b = 0;
  DO(i, 0, 10, a += 2; b += 3;);
  pf("%d %d\n", a, b);

  return 0;
}
