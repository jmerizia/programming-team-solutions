#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

void Solve()
{
    const int MAXN = 1e5+1;
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, P; cin >> N >> P;
        vector<int> v (N);
        for (int i = 0; i < N; i++) cin >> v[i];
        sort(v.begin(), v.begin()+N, greater<int>());
        vector<int> pref (N+1, 0);
        for (int i = 1; i < N+1; i++) pref[i] = pref[i-1] + v[i-1];
        int ans = INT_MAX;
        for (int i = 0; i <= N - P; i++) {
            int sm = pref[i+P] - pref[i];
            ans = min(ans, v[i]*P - sm);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

