#include <bits/stdc++.h>
using namespace std;

int p, q, s;

int main()
{
  cin >> p >> q >> s;
  int a = p, b = q;
  // finds lcm inefficiently :p
  while (a <= s && b <= s) {
    if (a == b) {
      printf("yes");
      return 0;
    }
    if (a < b) a += p;
    else b += q;
  }
  printf("no");
}
