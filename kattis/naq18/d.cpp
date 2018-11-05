#include <bits/stdc++.h>
using namespace std;

int L, W, x, y;
int row[30];
int speeds[30];
int offsets[30];
int intervals[30];
string directions;

void game_tick()
{
  // each time, I and S stay the same, but
  // O becomes (O + S) % I
  for (int i = 0; i < L; i++) {
    if (i % 2 == 0) {
      offsets[i] = (offsets[i] + speeds[i]) % intervals[i];
    } else {
      offsets[i] = (offsets[i] - speeds[i] + intervals[i]) % intervals[i];
    }
  }
}

bool is_on_car(int x, int y)
{
  int lane = y;
  for (int i = offsets[lane]; i < W; i += intervals[lane]) {
    if (i == x) return 1;
  }
  return 0;
}

int main()
{
  cin >> L >> W;
  for (int i = 0; i < L; i++) {
    int O, I, S;
    cin >> O >> I >> S;
    speeds[i] = S;
    offsets[i] = O;
    intervals[i] = I;
  }
  cin >> x >> directions;
  x--;
  y = L;
  for (char d : directions) {
    game_tick();
    if (d == 'U') y--;
    if (d == 'D') y++;
    if (d == 'R') x++;
    if (d == 'L') x--;
    if (is_on_car(x, y)) {
      printf("squish");
      return 0;
    }
  }
  printf("safe");
  return 0;
}
