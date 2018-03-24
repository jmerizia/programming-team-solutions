#include <bits/stdc++.h>
using namespace std;

const int N = 50;
const int STATES = 1e5;

int n, row[N], col[N];

int checkState(vector<vector<int>> state)
{
  for (int i = 0; i < n; i++)
    int r = 0;
    for (int j = 0; j < n; j++) r^state[i][j];

}

void solve(int i, int j, vector<vector<int>> state)
{
  if (i == n || j == n) return checkState();
  state[i] = 0;
  if ()
  solve(i+1, j, state);
  solve(i+1, j, state);
}

int main()
{
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < n; i++) {
    row[i] = a[j] - '0';
    row[i] = b[j] - '0';
  }
  vector<vector<int>> start_state = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

  solve();

}
