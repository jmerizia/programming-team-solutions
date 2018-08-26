#include <bits/stdc++.h>
using namespace std;

string board[6];
int ax = -1, ay = -1;

int tst(int x, int y)
{
  return (board[x][y] == 'Y') || (ax == x && ay == y);
}

int yellow_win()
{
  // check each row
  for (int i = 0; i < 6; i++) {
    int ct = 0;
    for (int j = 0; j < 7; j++) {
      if (tst(i, j)) ct++;
      else ct = 0;

      if (ct == 4) return 1;
    }
  }

  // check each col
  for (int j = 0; j < 7; j++) {
    int ct = 0;
    for (int i = 0; i < 6; i++) {
      if (tst(i, j)) ct++;
      else ct = 0;

      if (ct == 4) return 2;
    }
  }

  // check diagonal 1 (along left)
  for (int i = 0; i < 6; i++) {
    int ct = 0;
    for (int a = i, b = 0; a < 6 && b < 7; a++, b++) {
      if (tst(a, b)) ct++;
      else ct = 0;

      if (ct == 4) return 3;
    }
  }

  // check diagonal 1 (along top)
  for (int j = 0; j < 7; j++) {
    int ct = 0;
    for (int a = 0, b = j; a < 6 && b < 7; a++, b++) {
      if (tst(a, b)) ct++;
      else ct = 0;

      if (ct == 4) return 4;
    }
  }

  // check diagonal 2 (along left)
  for (int i = 0; i < 6; i++) {
    int ct = 0;
    for (int a = i, b = 0; a >= 0 && b < 7; a--, b++) {
      if (tst(a, b)) ct++;
      else ct = 0;

      if (ct == 4) return 5;
    }
  }

  // check diagonal 2 (along bottom)
  for (int j = 0; j < 7; j++) {
    int ct = 0;
    for (int a = 5, b = j; a >= 0 && b < 7; a--, b++) {
      if (tst(a, b)) ct++;
      else ct = 0;

      if (ct == 4) return 6;
    }
  }

  return 0;
}

int main()
{
  for (int i = 0; i < 6; i++) cin >> board[i];
  //cout << yellow_win(); return 0;
  for (int j = 0; j < 7; j++) {
    int i = 0;
    for (; i < 6 && board[i][j] == '.'; i++);
    i--;
    if (i != -1) ax = i, ay = j;
    //printf("%d %d\n", ax, ay);
    if (yellow_win()) printf("drop in column %d", j+1), exit(0);
  }

  printf("too hard");

  return 0;
}
