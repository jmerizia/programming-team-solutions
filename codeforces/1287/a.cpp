//time: 6:58
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)


void Solve()
{
    int TC, N;
    string s;
    cin >> TC;
    while (TC--) {
        cin >> N;
        cin >> s;
        bool aa = false;
        int ans = 0;
        int cur = 0;
        FOR(i, 0, N) {
            if (aa && s[i] == 'P') {
                cur++;
            }
            if (s[i] == 'A') {
                aa = true;
                ans = max(ans, cur);
                cur = 0;
            }
        }
        cout << max(cur, ans) << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

