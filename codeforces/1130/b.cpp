#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define CONTAINS(set, x) (set.find(x) != set.end())

void Solve()
{
    int n; cin >> n;
    vector<pair<int, int>> A (n*2);
    for (int i = 0; i < n*2; i++) {
        int a; cin >> a;
        A[i] = {a, i};
    }
    sort(A.begin(), A.end());
    ll ans = A[0].second + A[1].second;
    for (int i = 0; i < n*2-2; i += 2) {
        ll a1 = A[i].second, a2 = A[i+1].second;
        ll b1 = A[i+2].second, b2 = A[i+3].second;
        ans += min(abs(a1-b1) + abs(a2-b2), abs(a1-b2) + abs(a2-b1));
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

