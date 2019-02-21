#include <bits/stdc++.h>
using namespace std;

int n, c[5001], mem[5001][5001][2];

int dp(int l, int r, int side)
{
    if (l == r) {
        return 0; // already same color
    }
    if (mem[l][r][side] != -1) {
        return mem[l][r][side];
    }
    int res;
    if (side == 0) {
        int side0 = dp(l+1, r, 0) + (c[l] == c[l+1] ? 0 : 1);
        int side1 = dp(l+1, r, 1) + (c[l] == c[r] ? 0 : 1);
        res = min(side0, side1);
    } else {//side==1
        int side0 = dp(l, r-1, 0) + (c[r] == c[l] ? 0 : 1);
        int side1 = dp(l, r-1, 1) + (c[r] == c[r-1] ? 0 : 1);
        res = min(side0, side1);
    }
    return (mem[l][r][side] = res);
}

void init()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mem[i][j][0] = -1;
            mem[i][j][1] = -1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    init();
    cout << min(dp(0, n-1, 0), dp(0, n-1, 1)) << endl;

    return 0;
}

// Got it in first try!
// ** Very important insight:
// The final color of a segment will always be the color
// of either the left endpoint or right endpoint.
// To realise this, do some examples on paper,
// or if that didn't work, quickly implement n^3
// version for small test cases and see patterns.
// Then, the rest of the dp falls right into place:
// The minimum number of steps required to get a
// segment [l, r] same color as c[l] is the min
// of getting [l+1, r] same color as c[l+1] or
// getting [l+1, r] same color as c[r], and then
// plus 1, if c[l] is not the same as the subproblem's
// final color. Similar logic applied for getting
// segment [l, r] to color c[l].
// This makes for O(n^2) solution,
// as expected from bounds.
