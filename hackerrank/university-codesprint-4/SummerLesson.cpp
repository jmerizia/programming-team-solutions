#include <iostream>

using namespace std;

int n, m, c[1010], s[1010];

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) s[c[i]]++;
  for (int i = 0; i < m; i++) cout << s[i] << ' ';
}
