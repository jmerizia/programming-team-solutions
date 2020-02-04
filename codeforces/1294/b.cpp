#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int T, N;
string ans;
vector<pii> v;

void Solve()
{
    cin >> T;
    while (T--) {
        v.clear();
        ans.clear();
        cin >> N;
        FOR(i, 0, N) {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end());
        bool possible = true;
        FOR(i, 0, N-1) {
            if (v[i].second > v[i+1].second) {
                possible = false;
            }
        }
        if (possible) {
            int x = 0, y = 0;
            FOR(i, 0, N) {
                FOR(j, x, v[i].first) {
                    ans.push_back('R');
                    x++;
                }
                FOR(j, y, v[i].second) {
                    ans.push_back('U');
                    y++;
                }
            }
            cout << "YES" << endl << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

