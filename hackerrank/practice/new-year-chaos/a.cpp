#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

int merge(vector<int>& v, vector<int>& space, int a, int b)
{
    // 5678 1234 -> 16 inversions
    // 4678 5123 -> 15 inversions
    // 1 2 -> 0 inversions
    // 2 1 -> 1 inversion
    // cases:
    //   placing L value into L area: 0 inversion
    //   placing L value into R area: 1 inversion
    //   placing R value into R area: 0 inversion
    //   placing R value into L area: 1 inversion
    //
    // 4  6  7  8   5  1  2  3
    // 0           +3 +3 +3 +3
    int i = a, j = mid, k = a;
    int cnt = 0;
    while (i < mid && j < b) {
        if (v[i] < v[j]) {
            if (k >= mid) {
                cnt++;
            }
            space[k] = v[i];
            i++;
            k++;
        } else if (v[i] > v[j]) {
            if (k < mid) {
                cnt++;
            }
            space[k] = v[j];
            j++;
            k++;
        }
    }
}

int sort(vector<int>& v, vector<int>& space, int a, int b)
{
    if (b - a == 0) return 0;
    if (b - a == 1) return 0;
    int mid = (a+b)/2;
    int lsum = sort(v, space, a, mid);
    int rsum = sort(v, space, mid, b);
}

void Solve()
{
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
    }
    cout << count(v) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

