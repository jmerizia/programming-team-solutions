#include <bits/stdc++.h>
using namespace std;

int n, m, k, b[100001], a[100001];

bool cmp(int a, int b) {
    return b < a;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n-1; i++) {
        a[i] = b[i+1] - b[i] - 1;
    }
    sort(a, a+n-1, cmp);
    int ans = b[n-1] - b[0] + 1;
    for (int i = 0; i < k-1 && i < n-1; i++) {
        ans -= a[i];
    }
    cout << ans << endl;
    return 0;
}
