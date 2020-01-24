#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

bool sorted(vector<int>& v, int l, int r) {
    if (l+1 == r) return true;
    for (int i = l; i < r-1; i++) if (v[i] > v[i+1]) return false;
    return true;
}

int rec(vector<int>& v, int l, int r) {
    if (sorted(v, l, r)) return r - l;
    int mid = (l + r) / 2;
    return max(rec(v, l, mid), rec(v, mid, r));
}

void Solve()
{
    int n; cin >> n;
    vector<int> v (n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << rec(v, 0, n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

