#include <bits/stdc++.h>
#include <string>
using namespace std;

typedef long long ll;
typedef vector<string> vs;
string a, b;
int dp[1001][1001];

int solve(int i, int j, vs* _pth)
{
  if (dp[i][j] != -1) return dp[i][j];
  int ans = 0;
  if (i == 0) ans = j;
  else if (j == 0) ans = i;
  else if (a[i-1] == b[j-1]) ans = solve(i-1, j-1, _pth);
  else {
    string insert_action = "Insert"; // + to_string(a[i]) + " at " + to_string(i) + " with " + to_string(b[j-1]) + "\n";
    string remove_action = "Remove"; // + to_string(a[i-1]) + " at " + to_string();
    string replace_action = "Replace";

    vs insert_pth = *_pth;
    vs remove_pth = *_pth;
    vs replace_pth = *_pth;
    insert_pth.push_back(insert_action);
    remove_pth.push_back(remove_action);
    replace_pth.push_back(replace_action);

    int insert_ans = solve(i, j-1, &insert_pth);
    int remove_ans = solve(i-1, j, &remove_pth);
    int replace_ans = solve(i-1, j-1, &replace_pth);

    if (insert_ans <= remove_ans && insert_ans <= replace_ans) {
      *_pth = insert_pth;
    } else if (remove_ans <= replace_ans) {
      *_pth = remove_pth;
    } else {
      *_pth = replace_pth;
    }
    int ans = 1 + min(insert_ans, min(remove_ans, replace_ans));
  }

  dp[i][j] = ans;
  printf("%d %d %d\n", i, j, ans);
  return ans;
}

// Convert to top down, and keep track of actions taken;
// This works since we can output any optimal path
int main()
{
  cin >> a >> b;
  for (int i = 0; i <= a.length(); i++) for (int j = 0; j <= b.length(); j++) dp[i][j] = -1;

  vs pth;
  cout << solve(a.length(), b.length(), &pth) << endl;
  cout << pth.size() << endl;

  for (string k : pth) cout << k << endl;

  return 0;
}
