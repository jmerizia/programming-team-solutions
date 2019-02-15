#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int i = 0;
    long long ans = 0;
    while (i < n) {
        int j = i+1;
        while (j < n && s[i] == s[j]) {
            j++;
        }
        auto it = a.begin();
        sort(it + i, it + j);
        for (int l = j-1, m = 0; l >= i && m < k; l--, m++) {
            ans += a[l];
        }
        i = j;
    }
    cout << ans;

    return 0;
}
