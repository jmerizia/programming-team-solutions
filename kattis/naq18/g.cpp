#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> path;

int count_Ls(int pos) {
  int cnt = 0;
  while (s[pos] == 'L') pos++, cnt++;
  return cnt;
}

void solve() {
  int house = 1;
  int pos = 0;
  while (s[pos] != 'X') {
    int Ls = count_Ls(pos);
    // skip over Ls, and make room
    pos += Ls;
    house += Ls;
    int tmp_house = house;
    // take the Ls
    while (tmp_house >= 1) {
      path.push_back(tmp_house--);
    }
    house++;
    // take the next Rs
    while (s[pos] == 'R') {
      path.push_back(house++);
      pos++;
    }
  }
}

int main()
{
  cin >> n >> s;
  s.push_back('X');
  solve();
  for (int k : path) printf("%d\n", k);
}
