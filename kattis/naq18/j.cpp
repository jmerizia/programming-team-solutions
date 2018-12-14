#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> next_states(vector<vector<int>> board) {
  int x = 0, y = 0;
  for (int i = 1; i <= 5; i++)
    for (int j = 1)
}

pair<int, int> min_score_diff(vector<vector<int>> board, char player)
{

}

vector<vector<int>> init()
{
  vector<vector<int>> board;
  for (int i = 0; i < 6; i++) {
    vector<int> tmp;
    for (int j = 0; j < 6; j++) {
      tmp.push_back(0);
    }
    board.push_back(tmp);
  }
  return board;
}

int main()
{
  auto board = init();
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= i; j++) {
      cin >> board[i][j];
    }
  }
  solve(board, 'J');
}
