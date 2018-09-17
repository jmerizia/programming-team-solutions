// by: Tarediiran atakyn jmerizia
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> piii;

int russian[300], stk[10], used[10], n, sol;
set<piii> ans;
string a, b, c;

int num_val(char p) {
  return stk[russian[p]];
}

void test() {
  ll a_sum = 0, b_sum = 0, c_sum = 0;
  if (num_val(a[0]) == 0 ||
      num_val(b[0]) == 0 ||
      num_val(c[0]) == 0) {
    return;
  }

  for (char p : a) {
    a_sum *= 10l;
    a_sum += num_val(p);
  }

  for (char p : b) {
    b_sum *= 10;
    b_sum += num_val(p);
  }

  for (char p : c) {
    c_sum *= 10;
    c_sum += num_val(p);
  }

  if (a_sum + b_sum == c_sum) {
    ans.insert({a_sum, {b_sum, c_sum}});
    sol = 1;
  }
}

void back(int k) {
  if (k == n) test();
  else {
    for (int i = 0; i < 10; i++) {
      if (!used[i]) {
        used[i] = 1;
        stk[k] = i;
        back(k+1);
        used[i] = 0;
      }
    }
  }
}

int main() {
  cin >> a >> b >> c;
  set<char> uniq;
  for (char k : a) uniq.insert(k);
  for (char k : b) uniq.insert(k);
  for (char k : c) uniq.insert(k);
  int i = 0;
  for (auto it = uniq.begin(); it != uniq.end(); it++, i++) {
    russian[*it] = i;
  }
  n = uniq.size();

  back(0);
  if (!sol) {
    cout << "NO SOLUTION";
  } else {
    for (auto it = ans.begin(); it != ans.end(); it++) {
      printf("%lld+%lld=%lld\n", it->first, it->second.first, it->second.second);
    }
  }

  return 0;
}
