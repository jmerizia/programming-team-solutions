// F=template && g++ -std=c++1y $F.cpp -o $F.bin && ./$F.bin < 1.in
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
#define DO(i, a, b) for (int i = (a); i < (b); ++i)
#define DOd(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define CONTAINS(set, x) (set.find(x) != set.end())

int T, n;
string A, B;
set<map<char, int>> subsets;

int main()
{
  cin >> T;
  DO(t, 1, T+1) {
    subsets.clear();
    cin >> n >> A >> B;
    // generate all subsets of B, O(n^3)
    DO(i, 0, n) DO(j, i+1, n+1) {
      map<char, int> mp;
      DO(k, i, j) {
        if (CONTAINS(mp, B[k])) mp[B[k]]++;
        else mp[B[k]] = 1;
      }
      subsets.insert(mp);
    }
    // check all subsets of A, O(n^3)
    int ans = 0;
    DO(i, 0, n) DO(j, i+1, n+1) {
      map<char, int> mp; 
      DO(k, i, j) {
        if (CONTAINS(mp, A[k])) mp[A[k]]++;
        else mp[A[k]] = 1;
      }
      if (CONTAINS(subsets, mp)) ans++;
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
