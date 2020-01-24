#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

void Solve()
{
    int n; cin >> n;
    vector<int> v (n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int dor = 0;
    for (int i = 0; i < n; i++) dor |= v[i];
    cout << dor % n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

