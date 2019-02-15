#include <bits/stdc++.h>
using namespace std;

int b, k, a[100001];

int main()
{
    cin >> b >> k;
    for (int i = 0; i < k; i++) {
        int aa; cin >> aa;
        a[i] = aa % 2;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans += i == k-1 ? a[i] : b*a[i];
        ans %= 2;
    }
    cout << (ans ? "odd" : "even") << endl;
    return 0;
}
