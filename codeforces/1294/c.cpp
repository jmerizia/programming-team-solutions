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
        int a = 0, b = 0, c = 0;
        for (int i = 2; i*i <= N; i++) if (N%i==0) { a = i; break; }
        if (a == 0) {
            printf("NO\n");
            continue;
        }
        int k = N/a;
        for (int i = 2; i*i <= k; i++) if (i!=a&&k%i==0) { b = i; break; }
        if (b == 0) {
            printf("NO\n");
            continue;
        }
        c = (N/a)/b;
        if (c!=1&&c!=a&&c!=b) {
            printf("YES\n%d %d %d\n", a, b, c);
        } else {
            printf("NO\n");
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

