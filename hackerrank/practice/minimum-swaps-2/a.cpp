#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define CONTAINS(set, x) (set.find(x) != set.end())

int idx_of(int k, vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i] == k)
            return i;
    return -1;
}

void Solve()
{
    int n;
    cin >> n;
    vector<int> ar (n);
    vector<int> idx_of (n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        ar[i]--;
    }
    for (int i = 0; i < n; i++) {
        idx_of[ar[i]] = i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // find value at i
        // find the idx where the value i is
        // move the value i to the ith position
        // move the value at idx to the value of i
        int idx = idx_of[i];
        int old_val = ar[i];
        if (idx != i) {
            ar[idx] = ar[i];
            ar[i] = i;
            idx_of[i] = i;
            idx_of[old_val] = idx;
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solve();
    return 0;
}

