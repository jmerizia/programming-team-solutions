#include <bits/stdc++.h>
using namespace std;

int n, v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> v;
    int ans = 0;
    if (v >= n-1) {
        ans = n-1;
    } else {
        ans += v;
        for (int i = 2; i <= n-v; i++) ans += i;
    }
    cout << ans << endl;

    return 0;
}
