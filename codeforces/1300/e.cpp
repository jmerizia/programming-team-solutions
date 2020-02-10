#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define CONTAINS(set, x) (set.find(x) != set.end())
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

const int MAXN = 1e6+1;
int N, A[MAXN];

void Solve()
{
    cin >> N;
    FOR(i, 0, N) cin >> A[i];
    int last = -1;
    for(int i = 0; i < N; ) {
        double avg = 0;
        while (i < N && A[i] <= last) {
            tot += A[i];
            i++;
        }
        avg /= 
        if (i < N) last = A[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

