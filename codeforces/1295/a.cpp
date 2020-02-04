#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int T, N;

void Solve()
{
    cin >> T;
    while (T--) {
        cin >> N;
        FOR (i, 0, N/2) {
            if (i == 0 && N%2 == 1) cout << '7';
            else cout << '1';
        }
        cout << endl;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

