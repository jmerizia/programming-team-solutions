#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

string S;
const int MAXN = 1e5;
int T, N, X, C[MAXN+1];

void Solve()
{
    cin >> T;
    while (T--) {
        cin >> N >> X >> S;
        C[0] = S[0] == '0' ? 1 : -1;
        FOR (i, 1, N) {
            C[i] = C[i-1] + (S[i] == '0' ? 1 : -1);
        }
        int l = C[N-1];
        int tot = (X == 0 ? 1 : 0);
        if (l == 0) {//same pattern
            bool x_in_c = false;
            FOR (i, 0, N) {
                if (C[i] == X) {
                    x_in_c = true;
                    break;
                }
            }
            if (x_in_c) {//infty
                cout << "-1" << endl;
            } else {
                cout << tot << endl;
            }
        } else {//changing pattern
            FOR (i, 0, N) {
                if ((X-C[i])/l>=0 && (X-C[i])%l==0) {
                    ++tot;
                }
            }
            cout << tot << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

