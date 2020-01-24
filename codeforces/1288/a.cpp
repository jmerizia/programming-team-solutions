#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

int t, n, d;

int f(int x)
{
    return x + (d+x) / (x+1);
}

void Solve()
{
    cin >> t;
    while (t--) {
        cin >> n >> d;
        int k = (int)sqrt(d) - 1;
        string ans = min(f(k), f(k+1)) <= n ? "YES" : "NO";
        cout << ans << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

