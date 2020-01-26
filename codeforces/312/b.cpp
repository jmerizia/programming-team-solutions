#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

double A, B, C, D;

void Solve()
{
    cin >> A >> B >> C >> D;
    double k = (1 - A/B) * (1 - C/D);
    cout << setprecision(10) << (A/B) / (1 - k) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

