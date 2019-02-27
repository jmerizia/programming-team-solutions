#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define CONTAINS(set, x) (set.find(x) != set.end())

void Solve()
{
    int w1, h1, w2, h2;
    cin >> w1 >> h1 >> w2 >> h2;
    int ans = 4 + w1 + 2*h1 + w2 + 2*h2 + abs(w1-w2);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

