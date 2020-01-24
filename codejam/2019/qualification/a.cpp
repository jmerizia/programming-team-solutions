#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

void Solve()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        ll N; cin >> N;
        ll A = 0, B = 0;
        for (ll i = 1; N > 0; N /= 10, i *= 10) {
            int d = N % 10;
            if (d == 4) { A += 2*i; B += 2*i; }
            else { A += d*i; }
        }
        cout << "Case #" << t << ": " << A << " " << B << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

