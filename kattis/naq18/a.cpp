#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<set<int>>> boards;

// if two boards can tie
int can_tie(set<int> a, set<int> b)
{
  for (auto it = a.begin(); it != a.end(); ++it) {
    if (b.count(*it)) {
      return 1;
    }
  }
  return 0;
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) {
    set<int> board;
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        int a;
        cin >> a;
        board.insert(a);
      }
    }
    boards.push_back(board);
  }

  for (int i = 0; i < boards.size(); i++) {
    for (int j = i + 1; j < boards.size(); j++) {
      if (can_tie(boards[i], boards[j])) {
        printf("%d %d", i + 1, j + 1);
        return 0;
      }
    }
  }
  printf("no ties");
}
