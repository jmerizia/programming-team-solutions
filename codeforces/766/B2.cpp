#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int n, ar[N];

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar+n);
  int w = 0;
  for (int i = 0; i < n-2; i++)
    if (ar[i] + ar[i+1] > ar[i+2])
      w++;
  cout << (w ? "YES" : "NO");

  return 0;
}
