#include <bits/stdc++.h>
using namespace std;

int cases;

int calc(string s)
{
  int damage = 0;
  int charge = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'S') damage += charge;
    else if (s[i] == 'C') charge *= 2;
  }
  return damage;
}

int main()
{

  cin >> cases;
  for (int i = 0; i < cases; i++) {
    int damage, n;
    string query;

    cin >> damage;
    cin >> query;
    n = query.length();

    int cur = calc(query);
    int count = 0;
    bool impossible = false;
    while (cur > damage) {
      printf("query: %s %d \n", query.c_str(), cur);

      int idxC = n-1;
      for (; idxC >= 0 && query[idxC] == 'S'; idxC--);
      if (idxC < n-1) {
        query[idxC] = 'S';
        query[idxS] = 'C';
      }

      cur = calc(query);
      count++;
    }
    printf("Case #%d: ", i+1);
    if (impossible) cout << "IMPOSSIBLE" << endl;
    else cout << count << endl;
  }

  return 0;
}
