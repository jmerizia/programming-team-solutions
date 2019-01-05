// rip time
#include <bits/stdc++.h>
using namespace std;

string s;
int all_cards[100];
int theta[11];
int other[11];

int main()
{
  cin >> s;
  int theta_turn = 1;
  for (int i = 0; i < s.length(); i++) {
    int card = -1;
    if (s[i] == 'A') card = 1;
    if (s[i] == '2') card = 2;
    if (s[i] == '3') card = 3;
    if (s[i] == '4') card = 4;
    if (s[i] == '5') card = 5;
    if (s[i] == '6') card = 6;
    if (s[i] == '7') card = 7;
    if (s[i] == '8') card = 8;
    if (s[i] == '9') card = 9;
    if (s[i] == 'T') card = 10;
    if (s[i] == 'J') card = 11;
    if (card == -1) continue;
    if (card == 11) {
      // clever
    } else {
      if (theta_turn) {

      }
    }
    all_cards

    printf("%c %d \n", s[i], card);
  }
}
