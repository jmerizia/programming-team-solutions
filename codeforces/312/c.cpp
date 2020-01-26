#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int N, K;

void Solve()
{
    cin >> N >> K;
    int tot = (N*(N-1))/2;
    if (tot <= K) {
        cout << "no solution" << endl;
    } else {
        FOR (i, 0, N) {
            cout << "0 " << i << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

