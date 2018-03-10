#include <iostream>
#include <algorithm>
#include <math.h>
#include <utility>
#include <map>

using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; i++)

int t;

string w, s;

int main()
{
  cin >> t;
  FOR(i, 0, t) {
    cin >> w >> s;
    map<char, int> counts;
    FOR(j, 0, w.length()) counts[w[j]]++;

    bool worked_for_one = false;
    FOR(j, 0, s.length() - w.length()){

      cout << "testing: ";
      FOR(k, j, j + w.length()) cout << w[k];
      cout << endl;

      map<char, int> mp = counts;

      // remove elements
      FOR(k, j, j + w.length()){
        if (mp.count(k)) mp[w[k]]--;
      }

      bool worked = true;
      for (pair<char, int> el: mp) {
        if (el.first > 0) {
          worked = false;
          break;
        }
      }

      if (worked) {
        FOR(k, j, j + w.length()) cout << w[k];
        cout << endl;
        worked_for_one = true;
        break;
      }

    }

    if (!worked_for_one) cout << -1 << endl;
  }

  return 0;
}
