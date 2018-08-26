#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int n;
string str;
vector<string> lines;

queue<int> solve(string s) {
  cout << s.length() << endl;
  queue<int> pos;
  int i = 0, j = 0, cur = 0;

  while (j < s.length() && s[j] != ' ') j++; j++;
  while (j < s.length()) {

    printf("%d %d\n", i, j-cur);
    if (j-cur >= n) {
      printf("yep\n");
      pos.push(i-1);
      cur = j;
    }

    while (j < s.length() && s[j] != ' ') j++; j++;
    while (i < s.length() && s[i] != ' ') i++; i++;
  }

  return pos;

}

int main() {
  cin >> n;
  getline(cin, str);
  getline(cin, str);

  string temp;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '~') {
      string cpy = temp;
      lines.push_back(cpy);
      temp.clear();
    } else {
      temp.push_back(str[i]);
    }
  }
  if (str[str.length()-1] != '~') {
    lines.push_back(temp);
  }

  for (string line : lines) {

    auto pos = solve(line);
    // for (int p : pos) {
    //   cout << p << endl;
    // }
    for (int i = 0; i < line.length(); i++) {

      if (pos.size() && pos.front() == i) {
        cout << endl;
        pos.pop();
      } else {
        cout << line[i];
      }

    }
    cout << endl;

  }

  return 0;
}
