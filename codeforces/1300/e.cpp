#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)

const int MAXN = 1e6+1;
int N, A[MAXN];
vector<vector<int>> ans;

void Solve()
{
    cin >> N;
    FOR(i, 0, N) cin >> A[i];
    int t = 0, w = 0;
    FORd(i, 0, N) {
        if (t <= A[i] * w) {
            t += A[i];
            w++;
        } else {
            ans.push_back({t, w});
            t = A[i];
            w = 1;
        }
    }
    FOR (i, 0, ans.size()) {
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

