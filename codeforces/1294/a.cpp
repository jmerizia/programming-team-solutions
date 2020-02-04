#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int T, A, B, C, N;

void Solve()
{
    cin >> T;
    while (T--) {
        cin >> A >> B >> C >> N;
        vector<int> v = {A, B, C};
        sort(v.begin(), v.end());
        int k = v[2]-v[0]+v[2]-v[1];
        cout << ((N<k || (N-k)%3!=0) ? "NO" : "YES") << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

