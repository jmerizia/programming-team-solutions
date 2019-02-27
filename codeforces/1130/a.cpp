#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define CONTAINS(set, x) (set.find(x) != set.end())

void Solve()
{
    int n; cin >> n;
    vector<int> V (n);
    for (int i = 0; i < n; i++) {
        cin >> V[i];
    }
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        if (V[i] > 0) pos++;
        if (V[i] < 0) neg++;
    }
    int goal = (n+1)/2;
    if (pos >= goal) {
        cout << 1;
    } else if (neg >= goal) {
        cout << -1;
    } else {
        cout << 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

