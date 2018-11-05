#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> path;

void solve()
{
  int house = 1;
  int pos = 0;
  if (s[pos] == 'L') {
    int cnt = 0;
    while (s[pos] == 'L') pos++, cnt++;
    while (cnt) {
      path.push_back(house + cnt);
      cnt--;
    }
    path.push_back(1);
    house += pos + 1;
  }
  if (s[pos] == 'X') return;

  while (s[pos] != 'X') {
    printf("%c\n", s[pos]);
    while (s[pos] == 'R' && s[pos] == s[pos+1]) {
      path.push_back(house);
      pos++;
      house++;
    }
    printf("%d %d\n", pos, house);
    path.push_back(house);
    house++;
    pos++;
    int Ls = 0;
    while (s[pos] == 'L') Ls++, pos++;
    printf("%d %d\n", pos, house);
    while (Ls) {
      path.push_back(house + Ls - 1);
      Ls--;
    }
    house += Ls;
    path.push_back(house);
  }
}

int main()
{
  cin >> n >> s;
  s.push_back('X');
  solve();
  for (int k : path) printf("%d\n", k);
}
