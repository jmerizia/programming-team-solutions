#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
#define CONTAINS(set, x) (set.find(x) != set.end())

void Solve()
{
    int n;
    cin >> n;
    vector<int> A (n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> B (n);
    int st = 0, en = n-1;
    for (int i = 0; i < n; i++) {
        if (i&1) {
            B[st++] = A[i];
        } else {
            B[en--] = A[i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << B[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

// for n = 2, 3: any configuration is optimal

// 21132
// 2-2 = 0
// 1-1 = 0
// 2-1 = 1
// 2-1 = 1
// 2-3 = 1
// 1-2 = 1
// 3-2 = 1
// 1-3 = 2
// start with sorting config:
// 11223
// make increasing to decreasing:
// 12321

// 1245
// 1-2 = 1
// 4-5 = 1
// 2-4 = 2
// 1-4 = 3
// 2-5 = 3
// 1-5 = 4
// 1452
// note: avoiding interactions: 14, 25, and 15
// at the same time is not possible
