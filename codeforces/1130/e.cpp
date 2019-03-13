#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

void Solve()
{
    ll k; cin >> k;
    ll n = 2000LL;
    ll x = n+k;
    vector<ll> ans (n);
    ans[0] = -1;
    for (int i = 1; i < n; i++) {
        if (x == 0) {
            ans[i] = 0;
        } else if (x < 1e6) {
            ans[i] = x;
            x = 0;
        } else {
            ans[i] = (ll)1e6;
            x -= 1e6;
        }
    }
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

// good question to ask:
//   For what input does looking ahead
//   change the answer?
// Take example [-1 1e6 1e6 1e6]
// Then the greedy solution will skip over
//   -1, reporting segment 2 to 4.
// However, in some cases subtracting 1 from
//   that sum has less effect than adding one
//   to the range length, since the range length
//   may be smaller than the sum
//   (i.e. [-1, 1e6, 1e6, ...]).
// Note that the greedy answer will be
//   less than or equal to optimal.
// Greedy will report (n-1)*(1e6+1e6+...+1e6)
//   = n*(1e6+1e6+...+1e6) - (1e6+1e6+...+1e6)
// But actual answer is n*(1e6+1e6+...+1e6-1)
//   = n*(1e6+1e6+...+1e6) - n
// Maximal difference of these is 
//   (n*(1e6+1e6+...+1e6) - n)
//     - (n*(1e6+1e6+...+1e6) - (1e6+1e6+...+1e6))
//   = (1e6+1e6+...+1e6) - n
//   <= 1e6*(2000-1) - 2000 (for n <= 2000)
//   = 1998998000 <= 1e9 (>= k)
// Finally, we have: greedy sum - n = k
// So to generate output, put -1.
// Then let x = k + 2000.
// Then keep putting 1e6 and subtracting it
// from x until there is less than 1e6.
// Put remaining x.
// Until there are 2000 numbers, put 0.
