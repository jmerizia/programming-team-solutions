#include <bits/stdc++.h>
using namespace std;

int n, a[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, a[i]);
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) cnt++;
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);
    cout << ans << endl;

    return 0;
}
