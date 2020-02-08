//time 4:06
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

void Solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int l = 0;
    int r = 0;
    FOR(i, 0, n) if (s[i] == 'L') l++; else r++;
    cout << (l+r+1) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

