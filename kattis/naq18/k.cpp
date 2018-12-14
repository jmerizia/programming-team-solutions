#include <bits/stdc++.h>
using namespace std;

char op;
string s;

int main()
{
  cin >> op >> s;
  if (op == 'E') {
    string nw;
    int cnt = 1;
    for (int i = 1; i < s.length(); i++) {
      if (s[i] == s[i-1]) {
        cnt++;
      } else {
        nw.push_back(s[i-1]);
        nw.push_back('0'+cnt);
        cnt = 1;
      }
    }
    nw.push_back(s[s.length()-1]);
    nw.push_back('0'+cnt);
    cout << nw;
  } else {
    string nw;
    char cur;
    for (int i = 0; i < s.length(); i++) {
      if (i % 2 == 0) {
        cur = s[i];
      } else {
        int cnt = (int) (s[i] - '0');
        for (int j = 0; j < cnt; j++) {
          nw.push_back(cur);
        }
      }
    }
    cout << nw;
  }
}
