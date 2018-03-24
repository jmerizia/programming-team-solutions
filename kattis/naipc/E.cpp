#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int MOD = 1e9 + 7;
typedef long long LL;

int n, k;
LL fdp[N];
int ar_used[N];
string ar[N];
string given;

LL fct(int i)
{
  if (fdp[i] != 0) return fdp[i];
  fdp[i] = 1;
  int cur = i;
  while (cur > 1) {
    fdp[i] *= cur;
    fdp[i] % MOD;
    cur--;
  }
  return fdp[i];
}

bool checkSame(int given_idx, int ar_idx)
{
  string target = ar[ar_idx];
  for (int target_idx = 0; target_idx < target.length(); target_idx++, given_idx++) {
    if (given_idx == given.length()) return false;
    if (given[given_idx] != target[target_idx]) return false;
  }
  return true;
}

int findWord(int given_idx)
{
  // TODO: replace with binary search
  int cur = 0;
  while (!checkSame(given_idx, cur)) cur++;
  return cur;
}

int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> ar[i];
  cin >> given;

  sort(ar, ar+n);

  LL total = 0;
  for (int i = 0; i < k; i++) {
    int word_loc = findWord(i);
    int cnt = 0;
    for (int j = 0; j < word_loc; j++) if (!ar_used[j]) cnt++;

    LL children = (cnt * fct(n-i-1) / fct(n-(k-i)))%MOD;
    cout << "children = " << children << endl;
    cout << "n-i-1 = " << n-i-1 << endl;
    cout << "n-(k-i) = " << n-(k-i) << endl;
    total = (total+children)%MOD;
    ar_used[word_loc] = 1;
  }
  cout << total;
}
