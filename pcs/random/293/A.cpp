#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int bs(int target)
{
  int mid, l = 0, r = n-1;
  for (int i = 0; i < 12; i++) {
    mid = (l + r) / 2;
    if (target < v[l]) r = mid;
    else l = mid;
  }
}

int main()
{
  cin >> n;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

    }
  }

  return 0;
}
